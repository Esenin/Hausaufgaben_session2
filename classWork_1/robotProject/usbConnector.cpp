#include "usbConnector.h"

UsbConnector::UsbConnector(RobotModel *model)
    : Connector(model)
{
}

void UsbConnector::sendCommand(QString command)
{
    command.prepend('U');
    mRobot->executeCmd(command);
}
