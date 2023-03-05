#ifndef RADIOSERVICE_H
#define RADIOSERVICE_H
#include <QObject>
#include <QQueue>
#include <QThreadPool>

#include "receiver.h"

class RadioService: public QObject
{
    Q_OBJECT
public:
    explicit RadioService(QObject *parent = nullptr);
    static RadioService* getInstance(QObject *parent = nullptr);

    void setReceiver(Receiver* receiver);
    Q_INVOKABLE void addCommand(QString commandType);
    void processNextCommand();

private:
    virtual ~RadioService();
    static RadioService* instance_;
    Receiver* receiver_;
    QQueue<Command*> commandQueue_;
    QThreadPool threadPool_;
};

#endif // RADIOSERVICE_H
