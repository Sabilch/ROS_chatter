cmake_minimum_required(VERSION 3.0.2)
project(test_program)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
 
)

include_directories(
#  include
  ${catkin_INCLUDE_DIRS}
)




## Generate messages in the 'msg' folder
 add_message_files(
   FILES
   person_data.msg  
 )

## Generate services in the 'srv' folder


## Generate actions in the 'action' folder

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs 
  
)

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
find_package(catkin REQUIRED COMPONENTS
genmsg
roscpp
rospy
)

#add_action_files(DIRECTORY action FILES initiateIDPlayer.action)

#generate_messages(DEPENDENCIES actionlib_msgs)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES test_program
  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
 # actionlib_msgs
)


add_executable(Sabil_Publisher src/Sabil_Publisher.cpp)
add_dependencies(Sabil_Publisher ${Sabil_Publisher_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries( Sabil_Publisher ${catkin_LIBRARIES} )


 install(TARGETS Sabil_Publisher
   RUNTIME DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
 )
 
 
## Mark other files for installation (e.g. launch and bag files, etc.)
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
  FILES_MATCHING
  PATTERN "*.launch"
)

