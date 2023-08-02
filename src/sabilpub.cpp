#include "ros/ros.h"
//#include "sabilpub/person_data.h"

#include <std_msgs/String.h>

int main (int args, char **argv) {
    ros::init(args, argv, "sabilpub");
    ros::NodeHandle n;

    ros::Publisher topic_pub = n.advertise<std_msgs::String>("/sabilData",1);

    ros::Rate loop_rate(5);
    
    while(ros::ok()) {
        std_msgs::String msg;

         msg.data = "here's the publisher";

        topic_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();

    }

    return 0;
}
