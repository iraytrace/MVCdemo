//  This software is covered by the MIT open source license. See misc/MIT.txt

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_setPoint(68)
{
    ui->setupUi(this);
    setupSensor();
    setupFurnace();
    setupUiControls();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::temperatureHasChangedTo(double temperature)
{
    ui->temperatureLabel->setText(QString("%1").arg(temperature));
    ui->temperatureSlider->setValue(int(temperature));

    m_setPoint.announceControlChanges(temperature);
}

void MainWindow::setpointHasChanged(int val)
{
    ui->setPointSlider->setValue(val);
    ui->setPointSpinBox->setValue(val);

    m_setPoint.announceControlChanges(
                int(m_sensor.getCurrentTemperature()) );
}

void MainWindow::setupSensor()
{
    connect(&m_sensor, SIGNAL(newTemperature(double)),
            this, SLOT(temperatureHasChangedTo(double)));
}

void MainWindow::setupFurnace()
{
    connect(&m_furnace, SIGNAL(heating(bool)),
            ui->isHeatingRadioButton, SLOT(setChecked(bool)));

    connect(&m_setPoint, SIGNAL(newControlState(bool)),
            &m_furnace, SLOT(setOn(bool)));
}

void MainWindow::setupUiControls()
{

    connect(ui->setPointSpinBox, SIGNAL(valueChanged(int)),
            &m_setPoint, SLOT(setDesiredTemperature(int)));
    connect(ui->setPointSlider, SIGNAL(valueChanged(int)),
            &m_setPoint, SLOT(setDesiredTemperature(int)));

    connect(&m_setPoint, SIGNAL(newSetPoint(int)),
            this, SLOT(setpointHasChanged(int)));

    setpointHasChanged(m_setPoint.currentValue());
}
