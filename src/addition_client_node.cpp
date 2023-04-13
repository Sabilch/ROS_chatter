#include "ros/ros.h"
#include "test_program/AddTwoInts.h"


int main (int args, char **argv) {
    ros::init(args, argv, "Addition_service_Client_Node");
    ros::NodeHandle n;

    ros::ServiceClient client = n.serviceClient<test_program::AddTwoInts>("add_two_ints");
    test_program::AddTwoInts srv;
    srv.request.a = 5;
    srv.request.b = 7;

    if (client.call(srv))
    {
        ROS_INFO("The sum is equal to : %ld", srv.response.sum);
    }

    else {
        ROS_INFO("Failed to call the service ");
        return 1;
    }
    return 0;
}