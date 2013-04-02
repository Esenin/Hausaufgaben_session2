#include "robotModel.h"


RobotModel::RobotModel()
{
    answer.clear();
}

RobotModel::~RobotModel()
{
    answer.clear();
}

void RobotModel::executeCmd(const QString command)
        throw(robotExceptions::LowBattery, robotExceptions::RestrictedCommand)
{
    if (command.indexOf(QString("Session")) >= 0)
        return; // to not throw anything on connection

    unsigned int const goodRange = 100500;
    int const battaryEmpty = 10;
    answer.clear();

    processCommand(command);

    if (answer.toUInt() > goodRange)
        throw robotExceptions::RestrictedCommand(command);

    if (qrand() % battaryEmpty * 2 < battaryEmpty)
        throw robotExceptions::LowBattery();
}

QString RobotModel::getResult() throw(robotExceptions::DataCorrupted)
{
    int const probability = 99;
    if (!(rand() % probability))
        throw robotExceptions::DataCorrupted();
    return answer;
}

void RobotModel::processCommand(QString const &command)
{
    unsigned int prime = 31;
    unsigned int result = 0;
    unsigned int ring = 2013;
    for (int i = 0; i < command.size(); i++)
    {
        result += ((command.at(i).toAscii() - 'a' + 1) * prime) % ring;
        prime *= prime;
    }
    answer = QString::number(result);
}
