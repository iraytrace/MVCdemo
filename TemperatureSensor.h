//  This software is covered by the MIT open source license. See misc/MIT.txt

#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

class TemperatureSensor
{
public:
    explicit TemperatureSensor();
    double getCurrentTemperature();

private:
    void updateTimeOfDay();
    double tempFromTimeOfDay();

    double m_lastTemperature;

    double m_timeOfDay;
    double m_timeStep;
    double m_tempSpan;
    double m_lowTemp;
};

#endif // TEMPERATURESENSOR_H
