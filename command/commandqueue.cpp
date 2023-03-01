#include "commandqueue.h"

class ThreadPool {
public:
    ThreadPool(int thread_count, CommandQueue& command_queue) : command_queue_(command_queue) {
        for (int i = 0; i < thread_count; ++i) {
            threads_.push_back(std::thread(&ThreadPool::run, this));
        }
    }

    ~ThreadPool() {
        for (auto& thread : threads_) {
            thread.join();
        }
    }

    void run() {
        while (true) {
            ICommand* command = command_queue_.getCommand();
            if (command == nullptr) {
                break;
            }
            command->executeCommand();
            delete command;
        }
    }

private:
    CommandQueue& command_queue_;
    std::vector<std::thread> threads_;
};

CommandQueue::CommandQueue()
{

}
