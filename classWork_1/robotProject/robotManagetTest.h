#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>

#include "robotManager.h"

class RobotManagerTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {
        manager = new RobotManager(connectionType::usb);
    }

    void goStraightTest()
    {
        int const powerRate = 50;
        manager->goForward(powerRate);
    }

    void stopTest()
    {
        manager->fullStop();
    }

    void readSensorTest()
    {
        int const sensorsCount = 5;
        for (int i = 0; i < sensorsCount; i++)
            manager->readSensorState(i);
    }

    void cleanupTestCase()
    {
        delete manager;
    }

private:
    RobotManager *manager;
};
