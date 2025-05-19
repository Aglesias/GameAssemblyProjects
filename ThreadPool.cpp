#include "stdafx.h"
#include "ThreadPool.h"

DreamEngine::ThreadPool::~ThreadPool()
{
    Join();
}

void DreamEngine::ThreadPool::PushJob(Job&& job)
{
    std::lock_guard< std::mutex > lock{ myJobQueueMutex };
    myUnfinishedJobs.fetch_add(1, std::memory_order_relaxed);
    myJobQueue.push_back(std::move(job));
    myConditionalVariable.notify_one();
}

void DreamEngine::ThreadPool::Run(int threadCount)
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
    myDoJoinAllThreads = true;
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
    return static_cast<int>(myJobQueue.size());
}

const int DreamEngine::ThreadPool::GetUnfinishedJobs()
{
    return myUnfinishedJobs;
}

void DreamEngine::ThreadPool::ThreadFunction()
{
    while (true)
    {
        if (myDoJoinAllThreads)
        {
            return;
        }

        std::optional unresolvedJob = GetJob();
        if (unresolvedJob.has_value())
        {
            (*unresolvedJob)();
            myUnfinishedJobs.fetch_add(-1, std::memory_order_relaxed);
        }
        if (myJobQueue.size() == 0)
        {
            std::unique_lock<std::mutex> lock(myJobQueueMutex);
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



