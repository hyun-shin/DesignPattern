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
        qDebug() << "eRADIOCMD::ON";
        break;

    case (RadioType::eRADIOCMD::OFF):
        qDebug() << "eRADIOCMD::OFF";
        break;

    case (RadioType::eRADIOCMD::GET_INFO):
        qDebug() << "eRADIOCMD::GET_INFO";
        break;

    default:
        qDebug() << "Invalid command";
    }
}

