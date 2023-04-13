#include "ros/ros.h"
#include "test_program/AddTwoInts.h"


bool add(test_program::AddTwoInts::Request &req, test_program::AddTwoInts::Response &res){
    res.sum = req.a + req.b;
    return true;
}

int main (int args, char **argv) {
    ros::init(args, argv, "Service_Node");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("add_two_ints",add);
    ros::Rate loop_rate(1);

    ros::spin();

    return 0;
}