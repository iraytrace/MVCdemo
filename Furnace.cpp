//  This software is covered by the MIT open source license. See misc/MIT.txt

#include "Furnace.h"

Furnace::Furnace(QObject *parent) : QObject(parent), m_isOn(false)
{

}

void Furnace::setOn(bool turnOn)
{
    if (turnOn != m_isOn) {
        m_isOn = turnOn;
        emit heating(m_isOn);
    }
}
