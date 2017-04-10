//  This software is covered by the MIT open source license. See misc/MIT.txt

#include "Controller.h"

Controller::Controller() : m_label(new QLabel)
{
    m_label->show();
}

bool Controller::wakeUp()
{
    double hot = m_sensor.getCurrentTemperature();
    QString stringHot = QString("%1").arg(hot);
    m_label->setText(stringHot);

    return m_label->isVisible();
}
