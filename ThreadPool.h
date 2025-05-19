
#include <vector>
#include <mutex>
#include <functional>
#include <optional>
#include <thread>
#include <condition_variable>
#include <atomic>

#include <stdio.h>

using Job = std::function<void()>;

namespace DreamEngine
{
    class ThreadPool
    {
    public:
        ~ThreadPool();

        void PushJob(Job&& job);

        void Run(int threadCount);

        void Join();

        void Error();
        int GetQueueSize();
        const int GetUnfinishedJobs();

    private:
        void ThreadFunction();
        std::optional<Job> GetJob();


        std::vector<Job> myJobQueue;
        mutable std::mutex myJobQueueMutex;
        std::vector<std::thread> myThreads;
        std::atomic<bool> myDoJoinAllThreads = false;
        std::atomic<int> myUnfinishedJobs;
        std::condition_variable myConditionalVariable;
    };
}