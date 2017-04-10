//  This software is covered by the MIT open source license. See misc/MIT.txt

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupSensor();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::temperatureHasChangedTo(double temperature)
{
    ui->temperatureLabel->setText(QString("%1").arg(temperature));
}

void MainWindow::setupSensor()
{
    connect(&m_sensor, SIGNAL(newTemperature(double)),
            this, SLOT(temperatureHasChangedTo(double)));
}
