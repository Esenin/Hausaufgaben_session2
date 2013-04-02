#pragma once

#include <QtCore/QString>
#include <stdlib.h> // for rand

namespace robotExceptions
{
class LowBattery{};
class RestrictedCommand
{
public:
    RestrictedCommand(QString const cmd)
        : command(cmd)
    {}
    QString command;
};

class DataCorrupted{};
}

class RobotModel
{
public:
    RobotModel();
    ~RobotModel();

    void executeCmd(QString const command) throw(robotExceptions::LowBattery, robotExceptions::RestrictedCommand);
    QString getResult() throw(robotExceptions::DataCorrupted);

protected:
    void processCommand(QString const &command);
private:
    QString answer;
};

