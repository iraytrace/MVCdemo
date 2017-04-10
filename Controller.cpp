//  This software is covered by the MIT open source license. See misc/MIT.txt

#include "Controller.h"

Controller::Controller() : m_label(new QLabel)
{
    m_sensor.registerObserver(this);
    m_label->show();
}

bool Controller::wakeUp()
{
    m_sensor.clockTick();
    return m_label->isVisible();
}

void Controller::notify()
{
    double hot = m_sensor.getCurrentTemperature();
    QString stringHot = QString("%1").arg(hot);
    m_label->setText(stringHot);
}
