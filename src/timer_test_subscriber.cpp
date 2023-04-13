#include "ros/ros.h"
#include <std_msgs/String.h>
#include <std_msgs/Float64.h>


void temperatureCallback(const std_msgs::Float64::ConstPtr &msg)
    {
        ROS_INFO("Received temperature: %f", msg->data);
    }

int main(int args, char **argv)
{
    ros::init(args, argv, "Subscriber");
    ros::NodeHandle nh;
    ros::Subscriber temperatureSubscriber;

    temperatureSubscriber = nh.subscribe<std_msgs::Float64>("/temperature", 10, temperatureCallback);
    ros::Rate loop_rate(1); 

    while (ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}