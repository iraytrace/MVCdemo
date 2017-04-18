//  This software is covered by the MIT open source license. See misc/MIT.txt

#include "SetPoint.h"

SetPoint::SetPoint(int desiredTemp, QObject *parent)
    : QObject(parent)
    , m_desiredTemperature(desiredTemp)
    , m_deadBand(2)
{

}

void SetPoint::announceControlChanges(int curTemp)
{
    if (curTemp < (m_desiredTemperature - m_deadBand))
        emit newControlState(true);
    if (curTemp > (m_desiredTemperature + m_deadBand))
        emit newControlState(false);
}

void SetPoint::setDesiredTemperature(int setPointTemp)
{
    if (setPointTemp == m_desiredTemperature ) return;
    m_desiredTemperature = setPointTemp;
    emit newSetPoint(m_desiredTemperature);
}
