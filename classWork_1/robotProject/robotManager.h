#pragma once

#include <iostream>

#include "robotModel.h"
#include "usbConnector.h"
#include "bToothConnector.h"

//! all connections types
namespace connectionType
{
enum ConnectionType
{
    usb,
    blueTooth
};
}

//! @class RobotManager provides high level command of robot interaction
class RobotManager
{
public:
    //! makes choice what connector to use
    RobotManager(connectionType::ConnectionType const connection);
    ~RobotManager();
    //! sets same power to left and right engine
    void goForward(qreal const powerRate);
    //! sets zero power to all engines
    void fullStop();
    //! writes sensor @param sensorId state to console
    void readSensorState(int const sensorId);

protected:
    //! try send command to robot
    void sendToRobot(QString const &command);

private:
    RobotModel *robot;
    Connector *translator;
};

