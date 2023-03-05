#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include <QThreadPool>
#include "AppManager.h"

int main(int argc, char* argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    //QThreadPool::globalInstance()->setMaxThreadCount(1);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    QQmlComponent component(&engine, url);
    if (component.isError()) {
        qDebug() << "Error loading QML file:" << component.errors();
    } else {
        qDebug() << "QML file loaded successfully";
    }

    engine.load(url);

    QList<QObject*> rootObjects = engine.rootObjects();
    QObject* mainQmlObject = rootObjects.first();
    AppManager::setContext(engine.rootContext());
    AppManager::setObject(mainQmlObject);
    AppManager::registration();


    return app.exec();
}
