QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

source_dir = src
forms_dir = ui
resources_dir = res

SOURCES += \
    $${source_dir}/main.cpp \
    $${source_dir}/mainwindow.cpp

HEADERS += \
    $${source_dir}/Basic.h \
    $${source_dir}/Button.h \
    $${source_dir}/CloseDoorButton.h \
    $${source_dir}/DestinationButton.h \
    $${source_dir}/Display.h \
    $${source_dir}/Door.h \
    $${source_dir}/ECS.h \
    $${source_dir}/Elevator.h \
    $${source_dir}/FireButton.h \
    $${source_dir}/Floor.h \
    $${source_dir}/FloorButton.h \
    $${source_dir}/FloorSensor.h \
    $${source_dir}/HelpButton.h \
    $${source_dir}/IStrategy.h \
    $${source_dir}/OpenDoorButton.h \
    $${source_dir}/Opportunistic.h \
    $${source_dir}/Person.h \
    $${source_dir}/Speaker.h \
    $${source_dir}/mainwindow.h

FORMS += \
    $${forms_dir}/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    A3_ElevatorSystem.pro.user

RESOURCES += \ \
    res/elevator_sim.qrc

