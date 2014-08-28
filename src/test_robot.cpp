#include <controller_manager/controller_manager.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <stdio.h>

namespace test_robot{

	class phoenix_test : public hardware_interface::RobotHW
	{
	public:
		phoenix_test(){
			//connect and register the joint state interface
			hardware_interface::JointStateHandle state_handle_x("x", &pos[0], &vel[0], &eff[0]);
			joint_state_interface.registerHandle(state_handle_x);

			hardware_interface::JointStateHandle state_handle_y("y", &pos[1], &vel[1], &eff[1]);
			joint_state_interface.registerHandle(state_handle_y);

			hardware_interface::JointStateHandle state_handle_z("z", &pos[2], &vel[2], &eff[2]);
			joint_state_interface.registerHandle(state_handle_z);


			hardware_interface::JointStateHandle state_handle_yaw("yaw", &pos[3], &vel[3], &eff[3]);
			joint_state_interface.registerHandle(state_handle_yaw);

			hardware_interface::JointStateHandle state_handle_pitch("pitch", &pos[4], &vel[4], &eff[4]);
			joint_state_interface.registerHandle(state_handle_pitch);

			hardware_interface::JointStateHandle state_handle_roll("roll", &pos[5], &vel[5], &eff[5]);
			joint_state_interface.registerHandle(state_handle_pitch);		

			registerInterface(&joint_state_interface);


			//connect and register the joint position interface
			hardware_interface::JointHandle pos_handle_x(joint_state_interface.getHandle("x"), &cmd[0]);
			jnt_pos_interface.registerHandle(pos_handle_x);

			registerInterface(&jnt_pos_interface);	
			state_x_position = 0;
			state_x_velocity = 0;

		}
		int read(void);
		int write(ros::Publisher);

	private:
		hardware_interface::JointStateInterface jnt_state_interface;
		hardware_interface::PositionJointInterface jnt_pos_interface;

		hardware_interface::JointStateInterface joint_state_interface;

		double cmd[6];
		double pos[6];
		double vel[6];
		double eff[6];

		double state_x_position, state_x_velocity;


	};

	int phoenix_test::read(void){
		state_x_velocity ++;
		state_x_position ++;

	}

	int phoenix_test::write(ros::Publisher shoutout){

		std_msgs::String msg;
		std::stringstream ss;
		ss << "test_robot: cc= " << eff[0] << ", out= " << state_x_position; 
		msg.data = ss.str();

		shoutout.publish(msg);
	}
} //namespace

int main(int argc, char **argv){
	ros::init(argc, argv, "test_robot");
	ros::NodeHandle n;
	ros::Publisher shoutout = n.advertise<std_msgs::String>("test_robot", 100);

	ros::Rate loop_rate(120);

	test_robot::phoenix_test robot;
	controller_manager::ControllerManager cm(&robot);

	ros::Time last_time;
	ros::Time current_time = ros::Time::now();


	while(ros::ok()){

		last_time = current_time;
		current_time = ros::Time::now();

		robot.read();
		cm.update(current_time, ros::Duration(current_time - last_time));
		robot.write(shoutout);

		ros::spinOnce();
		loop_rate.sleep();

	}
}














