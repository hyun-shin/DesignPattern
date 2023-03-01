#include "radioconcreatecommand.h"
#include <iostream>

RadioConcreateCommand::RadioConcreateCommand(RadioService* radioservice)
    : radioservice_(radioservice) {
}

void RadioConcreateCommand::setCommand(RadioType::eRADIOCMD cmdNum) {
    commandNum_ = cmdNum;
}

void RadioConcreateCommand::executeCommand() {
    switch(commandNum_) {
    case (RadioType::eRADIOCMD::ON):
        radioservice_->on();
        break;

    case (RadioType::eRADIOCMD::OFF):
        radioservice_->off();
        break;

    case (RadioType::eRADIOCMD::GET_INFO):
        radioservice_->getInformation(method_);
        break;

    default:
        qDebug() << "Invalid command";
    }
}

void RadioConcreateCommand::setMethod(const std::string& method) {
    method_ = method;
}

