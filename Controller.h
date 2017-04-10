//  This software is covered by the MIT open source license. See misc/MIT.txt

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QLabel>
#include "TemperatureSensor.h"

class Controller
{
public:
    explicit Controller();
    bool wakeUp();

private:
    QLabel *m_label;
    TemperatureSensor m_sensor;
};

#endif // CONTROLLER_H
