//  This software is covered by the MIT open source license. See misc/MIT.txt

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TemperatureSensor.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void temperatureHasChangedTo(double temperature);

private:
    void setupSensor();

    Ui::MainWindow *ui;  // the view
    TemperatureSensor m_sensor;
};

#endif // MAINWINDOW_H
