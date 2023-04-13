#include "ros/ros.h"
#include "test_program/person_data.h"
//#include "test_program/AddTwoInts.h"

/*
bool add(test_program::AddTwoInts::Request &req, test_program::AddTwoInts::Response &res){
    res.sum = req.a + req.b;
    return true;
}
*/

int main (int args, char **argv) {
    ros::init(args, argv, "Sabil_Publisher");
    ros::NodeHandle n;

    ros::Publisher topic_pub = n.advertise<test_program::person_data>("/sabil_data",1000);
    ros::Rate loop_rate(1);
/*
    ros::init(args, argv, "Service_Node");
    ros::NodeHandle nh;
    ros::ServiceServer service = nh.advertiseService("add_two_ints",add);
    ros::spin();
*/
    
    while(ros::ok()) {
        test_program::person_data person_data;
        person_data.name = "sabil";
        person_data.age = 25;
        person_data.color = "green";

        topic_pub.publish(person_data);
        ros::spinOnce();
        loop_rate.sleep();

    }

    return 0;
}