#include "ros/ros.h"
#include <std_msgs/Float64.h>

void temperatureCallback(const std_msgs::Float64::ConstPtr &msg)
{
    ROS_INFO("Received temperature: %f", msg->data);
    // Add your code here to process the received message
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "temperature_node");
    ros::NodeHandle nh;
    ros::Publisher temperaturePublisher = nh.advertise<std_msgs::Float64>("/temperature", 10);
    ros::Subscriber temperatureSubscriber = nh.subscribe<std_msgs::Float64>("/temperature", 10, temperatureCallback);

    ros::Rate loop_rate(1); // 1Hz

    while (ros::ok())
    {
        std_msgs::Float64 msg;
        msg.data = 30.0; // replace with code to read temperature sensor data
        temperaturePublisher.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
