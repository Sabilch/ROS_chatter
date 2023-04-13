#include "ros/ros.h"
#include <std_msgs/Int32.h>
//#include <termios.h>
#include "test_program/initPlayer.h"
#include <iostream>
#include <utility>
#include <ncurses.h>
#include <list>
#include <map>
#include <string>


#define KEYCODE_RIGHT 0x43
#define KEYCODE_LEFT 0x44

ros::Publisher key_pub;

/*
 void initiate_game(){


}*/

// Function to read terminal inputs non-blocking; i.e., without ENTER being pressed
/*
int getch()
{
 static struct termios  newt;
 //tcgetattr( STDIN_FILENO, &oldt);           // save old settings
 //newt = oldt;
 newt.c_lflag &= ~(ICANON);                 // disable buffering
 //tcsetattr( STDIN_FILENO, TCSANOW, &newt);  // apply new setting
 int ch = getchar();                        // read character (non-blocking
 //tcsetattr( STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
 return ch;
}
*/
/***********************************************************************************************/

int main(int argc, char **argv)
{
  initscr();
  curs_set(0);
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  noecho();

  ros::init(argc, argv, "teleop_snake");
  ros::NodeHandle n;
  // double linear_, angular_, l_scale_, a_scale_;
  //  twist_pub_ = n.advertise<geometry_msgs::Twist>("position", 1);
  key_pub = n.advertise<std_msgs::Int32>("key", 1000);

  ros::init(argc, argv, "player_init");
  ros::NodeHandle n2;
  ros::ServiceClient client = n2.serviceClient<test_program::initPlayer>("init_player");
  test_program::initPlayer srv;
  srv.request.player_name = "Sabil";

  if (client.call(srv))
  {
    ROS_INFO("Player name: %s", srv.request.player_name.c_str());
    ROS_INFO("Players ID : %i", srv.response.player_ID);
  }

  else
  {
    ROS_INFO("Failed to call the service ");
    return 1;
  }
  ros::Rate loop_rate(10);

  while (ros::ok())
  {

    std_msgs::Int32 c;
    if ((c.data = getch()) != -1)
       {
          key_pub.publish(c);
       } 
      
   // c.data = getch(); // call your non-blocking input function
   
      
    ros::spinOnce();
    loop_rate.sleep();
  }

  return (0);
}
