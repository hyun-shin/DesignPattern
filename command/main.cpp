#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "radioservice.h"
#include "radioconcreatecommand.h"
#include "radioremotecontrol.h"
#include "radiotype.h"
#include "ThreadPool.h"

int main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    RadioService& radioService = RadioService::getInstance();
    RadioRemoteControl* remote = new RadioRemoteControl();  

    ThreadPool threadPool(1);

    std::vector<RadioType::eRADIOCMD> commands =
    {RadioType::eRADIOCMD::ON,
     RadioType::eRADIOCMD::OFF,
     RadioType::eRADIOCMD::GET_INFO};

    for(const auto& commandNum : commands) {
        RadioConcreateCommand* concreateCommand = new RadioConcreateCommand(&radioService);
        concreateCommand->setCommand(commandNum);

        threadPool.enqueue([=, &remote]() {
            std::shared_ptr<ICommand> command = std::make_shared<RadioConcreateCommand>(*concreateCommand);
            remote->setCommand(command);
            remote->executeCommand();
        });
    }

    delete remote;
    return app.exec();
}
