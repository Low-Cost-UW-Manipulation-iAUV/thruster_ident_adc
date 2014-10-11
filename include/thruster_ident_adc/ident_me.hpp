/* Author: Raphael Nagel
	Desc: ros_control_interface for testing purpose of the ros_control_iso controller
	Date: 02/Sept/2014
*/

#ifndef _IDENT_THRUSTER_
#define _IDENT_THRUSTER_


#include "ros/ros.h"
#include "std_msgs/String.h"
#include <time.h>

#include <sstream>
#include <stdio.h>

namespace iso_ros_control {

	class read_and_publish {
	public:
		read_and_publish();
		~read_and_publish();
		int read(void);
		int publish(void);
		void update(const ros::TimerEvent&);
	private:
		ros::NodeHandle nh_;

		ros::Duration control_period_;
		ros::Duration elapsed_time_;
		double loop_hz_;

		ros::Timer non_realtime_loop_;

		unsigned int sequence;
		int data;

		ros::Publisher shoutout;

	};
}

#endif