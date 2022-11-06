#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ECS.h"

const int DEFAULT_NUM_FLOORS = 10;
const int DEFAUlT_NUM_ELEVATORS = 3;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ecs = new ECS(DEFAUlT_NUM_ELEVATORS, DEFAULT_NUM_FLOORS);
    initConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initConnections() {
    connect(ui->FloorButtonUp, &QPushButton::pressed, this, &MainWindow::pressFloorUp);
    connect(ui->FloorButtonDown, &QPushButton::pressed, this, &MainWindow::pressFloorDown);
}

void MainWindow::pressFloorUp() {
    ui->FloorButtonUp->setStyleSheet("color: rgb(252, 233, 79);");
}

void MainWindow::pressFloorDown() {
    ui->FloorButtonDown->setStyleSheet("color: rgb(252, 233, 79);");
}

