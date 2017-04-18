//  This software is covered by the MIT open source license. See misc/MIT.txt

#ifndef FURNACE_H
#define FURNACE_H

#include <QObject>

class Furnace : public QObject
{
    Q_OBJECT
public:
    explicit Furnace(QObject *parent = 0);

signals:
    void heating(bool);

public slots:
    void setOn(bool turnOn);
private:
    bool m_isOn;
};

#endif // FURNACE_H
