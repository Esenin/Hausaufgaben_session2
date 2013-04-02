#pragma once

#include <QtCore/QString>

#include "robotModel.h"

//! @class Connector provide translation of commands to robot
class Connector
{
public:
    //! @param model robot model to connect with
    Connector(RobotModel *model);
    //! makes end of session
    virtual ~Connector();
    //! @param command your command to robot will be translated here
    virtual void sendCommand(QString const command) = 0;
    //! returns result of command execution
    QString listenAnswer();

protected:
    RobotModel *mRobot;
};

