#pragma once

#include "connector.h"

//! @class UsbConnector makes usb connection to robot
class UsbConnector : public Connector
{
public:
    UsbConnector(RobotModel *model);

    void sendCommand(QString command);
};

