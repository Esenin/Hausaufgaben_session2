#include "robotManager.h"

using std::cout;
using std::endl;

RobotManager::RobotManager(const connectionType::ConnectionType connection)
{
    robot = new RobotModel;
    switch (connection)
    {
    case connectionType::usb:
    {
        translator = new UsbConnector(robot);
        break;
    }
    case connectionType::blueTooth:
    {
        translator = new BToothConnector(robot);
    }
    }
}

RobotManager::~RobotManager()
{
    delete translator;
    delete robot;
}

void RobotManager::goForward(const qreal powerRate)
{
    QString command("leftEngine, rightEngine set power ");
    command.append(QString::number(powerRate));
    sendToRobot(command);
}

void RobotManager::fullStop()
{
    QString command("leftEngine, rightEngine set power 0");
    sendToRobot(command);
}

void RobotManager::readSensorState(const int sensorId)
{
    QString command("get sensor value from ");
    command.append(QString::number(sensorId));
    cout << "Sensor " << sensorId << ":\n";
    sendToRobot(command);
}

void RobotManager::sendToRobot(const QString &command)
{
    try
    {
        translator->sendCommand(command);
    }
    catch(robotExceptions::LowBattery const &)
    {
        cout << "Warning: too low battery\n";
    }
    catch(robotExceptions::RestrictedCommand const &)
    {
        cout << "Error: cannot execute this command\n";
    }

    try
    {
        QString result = translator->listenAnswer();
        cout << "Answer: " << result.toStdString() << endl;
    }
    catch(robotExceptions::DataCorrupted const &)
    {
        cout << "Warning: bad answer\n";
    }
}

