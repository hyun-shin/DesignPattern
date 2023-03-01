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

private:
    RadioType::eRADIOCMD commandNum_;
    RadioService* radioservice_;
};

#endif // RADIOCONCREATECOMMAND_H
