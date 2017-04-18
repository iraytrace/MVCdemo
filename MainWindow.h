//  This software is covered by the MIT open source license. See misc/MIT.txt

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "TemperatureSensor.h"
#include "Furnace.h"
#include "SetPoint.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void temperatureHasChangedTo(double temperature);
    void setpointHasChanged(int val);

private:
    void setupSensor();
    void setupFurnace();
    void setupUiControls();

    Ui::MainWindow *ui;  // the view
    TemperatureSensor m_sensor;
    Furnace m_furnace;
    SetPoint m_setPoint;
};

#endif // MAINWINDOW_H
