#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <condition_variable>
#include <cstddef>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>

class ThreadPool {
public:
    ThreadPool(size_t numThreads) {
        for (size_t i = 0; i < numThreads; ++i) {
            threads.emplace_back([this]() {
                while (true) {
                    std::unique_lock<std::mutex> lock(this->queue_mutex);
                    this->condition.wait(lock, [this]() {
                        return !this->tasks.empty();
                    });
                    auto task = std::move(this->tasks.front());
                    this->tasks.pop();
                    lock.unlock();
                    task();
                }
            });
        }
    }

    template <typename T>
    void enqueue(T task) {
        std::unique_lock<std::mutex> lock(queue_mutex);
        tasks.emplace([=]() {
            task();
        });
        lock.unlock();
        condition.notify_one();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread &worker: threads)
            worker.join();
    }

private:
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop = false;
};
#endif // THREADPOOL_H
