#include <QtQml/qqmlcontext.h>
#include "receiver.h"
#include "appmanager.h"
#include "services/radioservice.h"

static QQmlContext *g_context = nullptr;
static QObject *g_object = nullptr;

void AppManager::setContext(QQmlContext *context) {
    g_context = context;
}

void AppManager::setObject(QObject *object) {
    g_object = object;
}

void AppManager::registration() {
    if (g_context) {
        auto radioService = RadioService::getInstance(g_object);
        g_context->setContextProperty("radioService", radioService);
        //radioService->initialize();

        if(radioService) {
            auto receiver = new Receiver(g_object);
            radioService->setReceiver(receiver);
            //g_context->setContextProperty("receiver", receiver);
        }
    }
}
