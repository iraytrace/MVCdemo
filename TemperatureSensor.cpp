//  This software is covered by the MIT open source license. See misc/MIT.txt

#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor()
    : m_lastTemperature(0.0)
    , m_timeOfDay(0.0), m_timeStep(.50)
    , m_tempSpan(30.0), m_lowTemp(55.0)
{
}

double TemperatureSensor::getCurrentTemperature()
{
    updateTimeOfDay();

    double t = tempFromTimeOfDay();
    if (t != m_lastTemperature)
        m_lastTemperature = t;
    return m_lastTemperature;
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
