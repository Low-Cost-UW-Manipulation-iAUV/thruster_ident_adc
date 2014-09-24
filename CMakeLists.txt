cmake_minimum_required(VERSION 2.8.3)
project(thruster_ident_adc)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS 
	roscpp
	rospy
	geometry_msgs
	message_generation
	)


generate_messages(
	DEPENDENCIES
	geometry_msgs
	)


## Declare a catkin package
catkin_package(
	 CATKIN_DEPENDS 
	 roscpp
	 INCLUDE_DIRS
	 )

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(adc_pub src/ident_me.cpp)
target_link_libraries(adc_pub ${catkin_LIBRARIES})
add_dependencies(adc_pub geometry_msgs_generate_messages_cpp)
