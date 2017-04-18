//  This software is covered by the MIT open source license. See misc/MIT.txt

#ifndef SETPOINT_H
#define SETPOINT_H

#include <QObject>

class SetPoint : public QObject
{
    Q_OBJECT
public:
    explicit SetPoint(int setPointTemp, QObject *parent = 0);

    void announceControlChanges(int curTemp);
    int currentValue() const { return m_desiredTemperature; }

signals:
    void newSetPoint(int);
    void newControlState(bool);

public slots:
    void setDesiredTemperature(int setPointTemp);

private:
    int m_desiredTemperature;
    int m_deadBand;
};

#endif // SETPOINT_H
