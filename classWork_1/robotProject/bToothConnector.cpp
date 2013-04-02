#include "bToothConnector.h"

BToothConnector::BToothConnector(RobotModel *model)
    : Connector(model)
{
}

void BToothConnector::sendCommand(QString command)
{
    command.prepend('B');
    mRobot->executeCmd(command);
}
