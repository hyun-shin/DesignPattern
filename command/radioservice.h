#ifndef RADIOSERVICE_H
#define RADIOSERVICE_H
#include <QDebug>

class RadioService
{
public:
    static RadioService& getInstance();
    void on();
    void off();

private:
    RadioService();
    RadioService(const RadioService&) = delete; //복사 생성자를 삭제하여 객체 복사 막음
    RadioService& operator=(const RadioService&) = delete; // 복사 대입 연산자를 삭제하여 객체 복사를 막음
};

#endif // RADIOSERVICE_H
