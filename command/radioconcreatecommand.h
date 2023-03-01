#ifndef RADIOCONCREATECOMMAND_H
#define RADIOCONCREATECOMMAND_H
#include <ICommand.h>
#include <radiotype.h>
#include <radioservice.h>

class RadioConcreateCommand : public ICommand
{
public:
    RadioConcreateCommand(RadioService* radioservice);
    void setCommand(RadioType::eRADIOCMD cmd);
    void executeCommand() override;
    void setMethod(const std::string& method) override;

private:
    RadioService* radioservice_;

    RadioType::eRADIOCMD commandNum_;
    std::string method_;
};

#endif // RADIOCONCREATECOMMAND_H
