#include "radioservice.h"

RadioService& RadioService::getInstance() {
    static RadioService instance;
    return instance;
}

RadioService::RadioService() {

}

void RadioService::on() {
    qDebug() << "Radio is on";
}

void RadioService::off() {
    qDebug() << "Radio is off";
}
