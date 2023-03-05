#include "radioservice.h"
#include <QDebug>

RadioService* RadioService::instance_ = nullptr;

RadioService::RadioService(QObject *parent)
    : QObject(parent)
{
    threadPool_.setMaxThreadCount(1); // 단일 스레드풀
    connect(&threadPool_, &QThreadPool::started, this, &RadioService::processNextCommand);
}

RadioService::~RadioService() {}

RadioService* RadioService::getInstance(QObject *parent)
{
    if (!instance_) {
        instance_ = new RadioService(parent);
    }

    qDebug() << "RadioAppService::getInstance: " << instance_;
    return instance_;
}

void RadioService::setReceiver(Receiver* receiver) {
    receiver_ = receiver;
}

void RadioService::addCommand(QString commandType) {
    RadioCommand* cmd = nullptr;
    if (commandType == "load") {
        cmd = new RadioCommand(RadioCommand::CommandType::Load);
    } else if (commandType == "open") {
        cmd = new RadioCommand(RadioCommand::CommandType::Open);
    } else {
        return;
    }
    if (receiver_) {
        receiver_->setCommand(cmd);
    }
    delete cmd;
}

void RadioService::processNextCommand() {
    if (!commandQueue_.isEmpty()) {
        Command* command = commandQueue_.dequeue();
        if (receiver_) {
            receiver_->setCommand(command);
        }
        delete command;
    }
}
