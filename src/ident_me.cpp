/* Author: Raphael Nagel
	Desc: ros_control_interface for testing purpose of the ros_control_iso controller
	Date: 02/Sept/2014
*/

#include "ros/ros.h"
#include <sstream>
#include <iostream>	
#include <fstream>	
#include <stdio.h>
#include <time.h>
#include "thruster_ident/thrust_force.h"	

#include "thruster_ident/ident_me.hpp"

namespace iso_ros_control{
	read_and_publish::read_and_publish(){


		///Advertise the status topic
		shoutout = nh_.advertise<thruster_ident::thrust_force>("thruster_ident_force", 50);
		

		/// Get the required variables from the parameter server and set standard values if not available
		if (!nh_.getParam("/ros_control_iso/thruster_identification_bbb/pub_rate/", loop_hz_)){
			  
			ROS_ERROR("test_robot: Could not find update rate, assuming 50. \n");
			loop_hz_ = 50;
			nh_.setParam("/ros_control_iso/thruster_identification_bbb/pub_rate/", loop_hz_);
		}		

		///Set up the control loop by creating a timer and a connected callback
		ros::Duration update_freq = ros::Duration(1.0/loop_hz_);
		non_realtime_loop_ = nh_.createTimer(update_freq, &read_and_publish::update, this);


	}

	read_and_publish::~read_and_publish(){
	}

	/** Update(): read the current joint status, run the controller and update the actuator output
	*/
	void read_and_publish::update(const ros::TimerEvent& event){

		/// Read the current status
		read();

		publish();
	}

	/** Read(): testing - increment the joint state
	*		For testing purpose we only increment the joint state. In real this would read relevant data from sensors or encoders.
	*/
	int read_and_publish::read(void){
	 	
	 	std::ifstream adc_file;
	 	adc_file.open("/sys/devices/ocp.3/helper.12/AIN5");
	   
	   if( adc_file == NULL )
	   {
	      ROS_ERROR("Error while opening the file.\n");
	      exit(EXIT_FAILURE);
	   }
	   adc_file >> data;
		//fscanf(adc_file, "%d", &data);	 

		adc_file.close();
		return 0;


	}

	/** Write(): testing - publish the control output
	*		For testing purpose we only publish the output, in real this would change the PWMs of the motor, etc.
	*/
	int read_and_publish::publish(){

		thruster_ident::thrust_force msg;
		msg.header.seq = sequence;
		msg.header.stamp = ros::Time::now();

		msg.data = data;


		shoutout.publish(msg);
	}
} //namespace



int main(int argc, char **argv){
	ros::init(argc, argv, "read_and_publish_thruster_force");
	ros::NodeHandle nh;

	/// An Async spinner creates another thread which will handle the event of this node being executed.
	ros::AsyncSpinner spinner(2);
	spinner.start();
	iso_ros_control::read_and_publish robot;
	ros::spin();

	ROS_INFO("test_robot: Shutting down hardware interface");

}














