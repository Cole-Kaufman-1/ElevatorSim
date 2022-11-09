#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ECS.h"
#include <QTimer>

const int MainWindow::DEFAULT_NUM_FLOORS = 5;
const int MainWindow::DEFAUlT_NUM_ELEVATORS = 1;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    initSimulator(DEFAUlT_NUM_ELEVATORS, DEFAULT_NUM_FLOORS);
    initConnections();
}

MainWindow::~MainWindow() {
    delete user;
    delete ecs;
    elevators.clear();
    floors.clear();
    delete ui;
}

void MainWindow::initConnections() {
    connect(ui->FloorButtonUp, &QPushButton::pressed, this, &MainWindow::pressFloorUp);
    connect(ui->FloorButtonDown, &QPushButton::pressed, this, &MainWindow::pressFloorDown);
    connect(ui->HelpButton, &QPushButton::pressed, this, &MainWindow::pressHelpButton);
    connect(ui->FireButton, &QPushButton::pressed, this, &MainWindow::pressFireButton);
    connect(ui->DoorObstcButton, &QPushButton::pressed, this, &MainWindow::pressDoorObstrButton);
    connect(ui->OverloadButton, &QPushButton::pressed, this, &MainWindow::pressOverloadButton);
    connect(ui->PowerOutButton, &QPushButton::pressed, this, &MainWindow::pressPowerOutageButton);
    connect(ui->DestinationGoButton, &QPushButton::pressed, this, &MainWindow::pressDestinationButton);
    connect(ui->CloseDoorButton, &QPushButton::pressed, this, &MainWindow::pressCloseDoorButton);
    connect(ui->OpenDoorButton, &QPushButton::pressed, this, &MainWindow::pressOpenDoorButton);
    connect(ui->OpenDoorButton, &QPushButton::released, this, &MainWindow::pressOpenDoorButton);
    connect(ui->SwapStratButton, &QPushButton::pressed, this, &MainWindow::pressChangeStrategy);
}

void MainWindow::initSimulator(int numElevators,int numFloors) {
    //create user starting on floor 1
    user = new User(1);
    //create ECS
    ecs = new ECS(DEFAUlT_NUM_ELEVATORS, DEFAULT_NUM_FLOORS, this, user);
    //create floor and elevator objects
    elevators.reserve(DEFAUlT_NUM_ELEVATORS);
    for (int i = 0; i < numElevators; ++i) {
        elevators.emplace_back(*(new Elevator(ecs)));
    }
    floors.reserve(DEFAULT_NUM_FLOORS);
    for (int i = 0; i < numFloors; ++i) {
        floors.emplace_back(*(new Floor(ecs, DEFAULT_NUM_FLOORS)));
    }
    ecs->setElevators(&elevators);
    ecs->setFloors(&floors);
    std::cout << "**Initialized Simulation**\n" << std::endl;

}

void MainWindow::pressFloorUp() {
    if (user->getCarNum() == 0 ) {
        floors.at(user->getFloor()-1).pressUp();
    }
}

void MainWindow::pressFloorDown() {
    if (user->getCarNum() == 0 ) {
        floors.at(user->getFloor()-1).pressDown();
    }
}

void MainWindow::pressHelpButton() {
    elevators.at(0).helpButtonPressed();
}

void MainWindow::pressFireButton() {
    elevators.at(0).fireButtonPressed();
}

void MainWindow::pressDoorObstrButton() {
    elevators.at(0).doorObstButtonPressed();
}

void MainWindow::pressOverloadButton() {
    elevators.at(0).overloadButtonPressed();
}

void MainWindow::pressPowerOutageButton() {
    elevators.at(0).powerOutageButtonPressed();
}

void MainWindow::pressDestinationButton() {
    int destFloor = ui->DestinationInput->text().toInt();
    if (destFloor > DEFAULT_NUM_FLOORS || destFloor < 1 || user->getCarNum() == 0 || destFloor == elevators.at(0).getFloorNum()) {
        std::cout << "Invalid floor entry or user not in elevator or selected current floor" << std::endl;
        return;
    }
    elevators.at(0).carRequest(destFloor);
}


void MainWindow::pressOpenDoorButton() {
    elevators.at(0).openDoorButtonPressed();
}

void MainWindow::pressCloseDoorButton() {
    elevators.at(0).closeDoorButtonPressed();
}

void MainWindow::pressChangeStrategy(){
    ecs->changeStrategy();
}

void MainWindow::updateMsgDisplay(const QString& msg) {
    ui->DisplayMessage->setText(msg);
    QTimer::singleShot(5000, this, &MainWindow::resetMsgDisplay);
}

void MainWindow::resetMsgDisplay() {
    ui->DisplayMessage->setText("...");
}

void MainWindow::updateFloorNumDisplay(int newFloor) {
    //convert new floor to QString assuming base 10
    QString s = QString::number(newFloor, 10);
    //display new floor in elevator an floor display (updates floor display to keep user's floorNum and floor's displayNum consistent)
    ui->DisplayNum->setText(s);
    ui->FloorDisplay->setText(s);
}

User* MainWindow::getUser() {
    return user;
}

