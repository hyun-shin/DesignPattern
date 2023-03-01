#include "radioremotecontrol.h"

RadioRemoteControl::RadioRemoteControl()
{

}

void RadioRemoteControl::setCommand(std::shared_ptr<ICommand> command) {
    slot_ = command;
}

void RadioRemoteControl::executeCommand() {
    slot_->executeCommand();
}
