//  This software is covered by the MIT open source license. See misc/MIT.txt

#ifndef SUBJECT_H
#define SUBJECT_H
#include <QVector>
class Observer;

class Subject
{
public:
    void registerObserver(Observer *obs)
    {
        m_observers.push_back(obs);
    }

    void unregisterObserver(Observer *obs)
    {
        if ( m_observers.contains(obs) ) m_observers.removeAll(obs);
    }
    void notifyObservers()
    {
        foreach (Observer *obs, m_observers)
            obs->notify();
    }

private:
    QVector<Observer *> m_observers;
};

#endif // SUBJECT_H
