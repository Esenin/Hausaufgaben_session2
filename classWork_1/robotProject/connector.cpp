#include "connector.h"

Connector::Connector(RobotModel *model)
    : mRobot(model)
{
    mRobot->executeCmd(QString("startSession"));
}

Connector::~Connector()
{
    mRobot->executeCmd(QString("endSession"));
}

QString Connector::listenAnswer()
{
    return mRobot->getResult();
}

