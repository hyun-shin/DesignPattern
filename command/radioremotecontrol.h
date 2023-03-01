#ifndef RADIOREMOTECONTROL_H
#define RADIOREMOTECONTROL_H
#include "ICommand.h"
#include <memory>

//Invoker
class RadioRemoteControl {
public:
    RadioRemoteControl();
    void setCommand(std::shared_ptr<ICommand> command);
    void executeCommand();

private:
    std::shared_ptr<ICommand> slot_;
};

#endif // RADIOREMOTECONTROL_H
