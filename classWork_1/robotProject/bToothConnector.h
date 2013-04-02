#pragma once

#include "connector.h"

//! @class BToothConnector makes bluetooth connection to robot
class BToothConnector : public Connector
{
public:
    BToothConnector(RobotModel *model);

    void sendCommand(QString command);
};
