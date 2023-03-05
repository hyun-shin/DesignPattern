#ifndef RADIOCOMMAND_H
#define RADIOCOMMAND_H
#include <QDebug>
#include "command.h"

class RadioCommand : public Command
{
public:
    enum class CommandType {
        Load,
        Open,
    };

    RadioCommand(CommandType type) : type_(type) {}
    ~RadioCommand() {}

    void setCommandType(CommandType type) {
        type_ = type;
    }

    void execute() override {
        switch(type_) {
            case CommandType::Load:
                qDebug() << "load";
                break;
            case CommandType::Open:
                qDebug() << "open";
                break;
        }
    }

private:
    CommandType type_;
};

#endif // RADIOCOMMAND_H
