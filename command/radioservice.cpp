#include "radioservice.h"

RadioService& RadioService::getInstance() {
    static RadioService instance;
    return instance;
}

RadioService::RadioService() {

}

void RadioService::on() {
    qDebug() << "RadioService::on()";
}

void RadioService::off() {
    qDebug() << "RadioService::off()";
}

void RadioService::getInformation(const std::string& method) {
    qDebug() << "RadioService::getInforamtion(): " << QString::fromStdString(method);
}
