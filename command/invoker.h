#ifndef INVOKER_H
#define INVOKER_H
#include "command.h"

class Invoker
{
public:
    Invoker();
    void setCommand(Command* command);
    void executeCommand();
private:
    Command* m_command;
};

#endif // INVOKER_H
