#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include "temperatureSensor.hh"

TemperatureSensor::TemperatureSensor(ros::NodeHandle *nh)
{
    // Initialize temperature and ROS publisher
    temperature = 0.0;
    temperaturePublisher = nh->advertise<std_msgs::Float64>("/temperature", 10);
}

double TemperatureSensor::readTemperatureSensorData()
{
    // Code to read data from your sensor
    // Return measured temperature
    return 30.0;
}

void TemperatureSensor::publishTemperature()
{
    std_msgs::Float64 msg;
    msg.data = readTemperatureSensorData();
    temperaturePublisher.publish(msg);
    ROS_INFO("publishing now!! %f", msg.data);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "temperature_sensor_node");
    ros::NodeHandle nh;
    // Create an instance of Temperature sensor
    TemperatureSensor temperatureSensor(&nh);

    // Create a ROS timer for reading data
    ros::Timer timerReadTemperature = nh.createTimer(ros::Duration(0.5), std::bind(&TemperatureSensor::readTemperatureSensorData, temperatureSensor));
    // Create a ROS timer for publishing temperature
    ros::Timer timerPublishTemperature = nh.createTimer(ros::Duration(0.5),
                                                        std::bind(&TemperatureSensor::publishTemperature, temperatureSensor));
    // We can now use spin, or do whatever
    // we want in this node
    ros::spin();
}