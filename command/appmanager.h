#ifndef APPMANAGER_H
#define APPMANAGER_H

class QQmlContext;
class QObject;

class AppManager
{
public:
    static void setContext(QQmlContext* context);
    static void setObject(QObject* object);
    static void registration();
};

#endif // APPMANAGER_H
