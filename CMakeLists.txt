cmake_minimum_required(VERSION 2.8.3)
project(test_robot)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS 
	roscpp
	rospy
	std_msgs
	genmsg
	controller_manager
	hardware_interface )



## Declare a catkin package
catkin_package(
	 INCLUDE_DIRS include
	 roscpp
	 controller_manager
	 hardware_interface
	 )

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(test_robot src/test_robot.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker std_msgs_generate_messages_cpp)
