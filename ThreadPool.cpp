#include "stdafx.h"
#include "ThreadPool.h"

DreamEngine::ThreadPool::~ThreadPool()
{
    Join();
}

void DreamEngine::ThreadPool::PushJob(Job&& job)
{
    // locks the mutex to avoid data races
    std::lock_guard< std::mutex > lock{ myJobQueueMutex };
    // increments the unfinished jobs by one
    myUnfinishedJobs.fetch_add(1, std::memory_order_relaxed);
    myJobQueue.push_back(std::move(job));
    // Notifies one of the threads that a job is availible
    myConditionalVariable.notify_one();
}

void DreamEngine::ThreadPool::Run(int threadCount) // only called when initializing the pool
{
    if (!myThreads.empty())
    {
        Error();
        return;
    }

    for (int i = 0; i < threadCount; ++i)
    {
        myThreads.push_back(std::thread{ &ThreadPool::ThreadFunction, this });
    }
}

void DreamEngine::ThreadPool::Join()
{
    // sets the atomic bool to true.
    myDoJoinAllThreads = true;
    // Wakes all the threads blocked in wait.
    myConditionalVariable.notify_all();
    for (std::thread& thread : myThreads)
    {
        thread.join();
    }
    myThreads.clear();
}

void DreamEngine::ThreadPool::Error()
{
    puts("an error has occured");
    abort();
}

int DreamEngine::ThreadPool::GetQueueSize()
{
    // Returns the size of the queue for debugging 
    // purposes to see that the queue does not increment faster than it works. Or to set a max number of jobs in queue at one time.
    return static_cast<int>(myJobQueue.size());
}

const int DreamEngine::ThreadPool::GetUnfinishedJobs()
{
    // Returns atomic int to be able to lock the program in a while loop if needed to 
    // be able to wait for jobs to finish.
    return myUnfinishedJobs;
}

void DreamEngine::ThreadPool::ThreadFunction()
{
    while (true)
    {
        // Jump out of the loop 
        if (myDoJoinAllThreads)
        {
            return;
        }

        // Try to Get a job, if none are availible GetJob() returns std::nullopt
        std::optional unresolvedJob = GetJob();
        if (unresolvedJob.has_value())
        {
            // Do job
            (*unresolvedJob)();
            // Decrements the unfinished jobs by one
            myUnfinishedJobs.fetch_sub(1, std::memory_order_relaxed);
        }
        if (myJobQueue.size() == 0)
        {
            // make threads wait for either shutdown requested or jobs are availible.
            std::unique_lock<std::mutex> lock(myJobQueueMutex);
            // Returns myDoJoinAllThreads or size of myJobQueue do prevent spurious wake up
            myConditionalVariable.wait(lock, [this]() { return myDoJoinAllThreads || myJobQueue.size() != 0; });
        }
    }
}

std::optional<Job> DreamEngine::ThreadPool::GetJob()
{
    std::lock_guard< std::mutex > lock{ myJobQueueMutex };
    if (!myJobQueue.empty())
    {
        Job job = std::move(myJobQueue.back());
        myJobQueue.pop_back();
        return job;
    }
    else
    {
        return std::nullopt;
    }
}



