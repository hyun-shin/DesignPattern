#ifndef RECEIVER_H
#define RECEIVER_H
#include <QObject>
#include <QRunnable>
#include <QThreadPool>
#include <QDebug>
//#include "command.h"
#include "radiocommand.h"

class Receiver : public QObject//, public QRunnable
{
    Q_OBJECT
public:

    explicit Receiver(QObject *parent = nullptr): QObject(parent) {
    //     QThreadPool::globalInstance()->setMaxThreadCount(1);
    //    QThreadPool::globalInstance()->start(this);
    }

    void setCommand(RadioCommand *cmd) {
        m_cmd = cmd;
        m_cmd->execute();
    }

    //void run() override {
    //    if (m_cmd) {
    //        m_cmd->execute();
    //    }
    //}

private:
    virtual ~Receiver() {};
    RadioCommand *m_cmd = nullptr;
};

#endif // RECEIVER_H
