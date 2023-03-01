#ifndef COMMANDQUEUE_H
#define COMMANDQUEUE_H
#include <ICommand.h>

#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>

class CommandQueue : public ICommand
{
public:
    CommandQueue();
    void addCommand(ICommand* command);
    ICommand* getCommand();

private:
    std::queue<ICommand*> command_queue_;
    std::mutex mutex_;
    std::condition_variable condition_variable_;
};

#endif // COMMANDQUEUE_H
