//  This software is covered by the MIT open source license. See misc/MIT.txt
#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(QObject *parent)
    : QObject(parent), m_lastTemperature(0.0)
    , m_timeOfDay(0.0), m_timeStep(0.50)
    , m_tempSpan(30.0), m_lowTemp(55.0)
{
    m_pollTimer.setInterval(250);
    connect(&m_pollTimer, SIGNAL(timeout()),
            this, SLOT(clockTick()));

    m_pollTimer.start();
}


void TemperatureSensor::clockTick()
{
    updateTimeOfDay();

    double t = tempFromTimeOfDay();
    if (t != m_lastTemperature)
        emit newTemperature(m_lastTemperature = t);
}

void TemperatureSensor::updateTimeOfDay()
{
    m_timeOfDay += m_timeStep;
    if (m_timeOfDay >= 24.0) m_timeOfDay -= 24;
}
double TemperatureSensor::tempFromTimeOfDay()
{
    double mult;
    if (m_timeOfDay <= 12.0) mult =       m_timeOfDay  * (1.0/12.0);
    else                     mult = (24.0-m_timeOfDay) * (1.0/12.0);

    mult = mult * mult * (3.0 - 2.0 * mult);

    return m_lowTemp + m_tempSpan * mult;
}
