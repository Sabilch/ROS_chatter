#include "ros/ros.h"
#include "test_program/initPlayer.h"
#include <std_msgs/Int32.h>

ros::Subscriber key_sub;
int count_players ;

bool initPlay(test_program::initPlayer::Request &req, test_program::initPlayer::Response &res){
    res.player_ID = 1;
    count_players += 1 ;
    return 1;
}

void postKeyToLog(const std_msgs::Int32::ConstPtr& key){
    if (key->data == 261)
    {
        //ROS_INFO("Key pressed : %i", key->data);
        ROS_INFO("Key pressed : RIGHT");
    }
    else if (key->data == 260)
    {
       // ROS_INFO("Key pressed : %i", key->data);
        ROS_INFO("Key pressed : LEFT");
    }
    
    else 
        ROS_INFO("Key pressed : %i", key->data);
    
}

/*******************************************************************************************************/

int main (int args, char **argv) {
    count_players=0;
    ros::init(args, argv, "Core_Node");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("init_player",initPlay);
    
    //ros::init(args, argv, "Subscriber");
    
    key_sub = n.subscribe("/key",1,postKeyToLog);
    
    ros::Rate loop_rate(10);
    ros::spin();

    return 0;
}

