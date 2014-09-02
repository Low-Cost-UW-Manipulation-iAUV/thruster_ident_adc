/* Author: Raphael Nagel
	Desc: ros_control_interface for testing purpose of the ros_control_iso controller
	Date: 02/Sept/2014
*/

#ifndef _ROS_CONTROL_ISO_TEST_ROBOT_
#define _ROS_CONTROL_ISO_TEST_ROBOT_

#include <controller_manager/controller_manager.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <stdio.h>

namespace test_robot
{

	class phoenix_test : public hardware_interface::RobotHW
	{
	public:
		phoenix_test();
		~phoenix_test();
		int read(void);
		int write(void);
		void update(const ros::TimerEvent&);
	private:
		ros::NodeHandle nh_;

		hardware_interface::JointStateInterface joint_state_interface;		
		hardware_interface::EffortJointInterface jnt_eff_interface;

		boost::shared_ptr<controller_manager::ControllerManager> controller_manager_;

		ros::Duration control_period_;
		ros::Duration elapsed_time_;
		double loop_hz_;

		ros::Timer non_realtime_loop_;

		double cmd[6];
		double pos[6];
		double vel[6];
		double eff[6];

		double state_x_position, state_x_velocity;

		ros::Publisher shoutout;

	};


}

#endif