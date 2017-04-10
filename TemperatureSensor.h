//  This software is covered by the MIT open source license. See misc/MIT.txt

#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include <QObject>
#include <QTimer>
class TemperatureSensor : public QObject
{
    Q_OBJECT
public:
    explicit TemperatureSensor(QObject *parent = 0);
    double getCurrentTemperature() const { return m_lastTemperature; }

signals:
    void newTemperature(double);

private slots:
    void clockTick();

private:
    void updateTimeOfDay();
    double tempFromTimeOfDay();

    double m_lastTemperature;

    QTimer m_pollTimer;
    double m_timeOfDay;
    double m_timeStep;
    double m_tempSpan;
    double m_lowTemp;
};

#endif // TEMPERATURESENSOR_H
