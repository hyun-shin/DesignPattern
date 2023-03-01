#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <string>

class ICommand {
public:
    virtual ~ICommand() {}
    virtual void executeCommand() = 0;
    virtual void setMethod(const std::string& method) = 0;
};

#endif // ICOMMAND_H
