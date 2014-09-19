cmake_minimum_required(VERSION 2.8.3)
project(thruster_ident)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS 
	roscpp
	rospy
	std_msgs
	message_generation
	)

add_message_files(
	DIRECTORY msg 
	FILES
	thrust_force.msg
	)

generate_messages(
	DEPENDENCIES
	std_msgs
	)


## Declare a catkin package
catkin_package(
	 CATKIN_DEPENDS 
	 roscpp
	 INCLUDE_DIRS
	 )

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(ident_me src/ident_me.cpp)
target_link_libraries(ident_me ${catkin_LIBRARIES})
add_dependencies(ident_me thruster_ident_generate_messages_cpp)
