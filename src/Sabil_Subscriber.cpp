#include "ros/ros.h"
#include "test_program/person_data.h"

/*
void writeMsgToLog(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("Hi i'm subscriber");
    ROS_INFO("I'm receiving: %s", msg->data.c_str());

}
*/

void writeMsgToLog(const test_program::person_data &person_data){
    ROS_INFO("Name : %s", person_data.name.c_str());
    ROS_INFO("Age : %i", person_data.age);
    ROS_INFO("Fav color : %s", person_data.color.c_str());

}

int main (int args, char **argv) {
    ros::init(args, argv, "Sabil_Subscriber");
    ros::NodeHandle n;

    ros::Subscriber topic_sub = n.subscribe("/sabil_data",1000,writeMsgToLog);
    ros::Rate loop_rate(1);

    ros::spin();

    return 0;
}