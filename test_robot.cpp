#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <stdio.h>

using namespace test_robot;

class phoenix_test : publich hardware_interface::RobotHW{
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
	int write(void);

private:
	hardware_interface::JoinStateInterface jnt_state_interface;
	hardware_interface::PositionJointInterface jnt_pos_interface;

	double cmd[6];
	double pos[6];
	double vel[6];
	double eff[6];

	double state_x_position, state_x_velocity;


};

int phoenix_test::read(void){


}

int phoenix_test::write(void){
	state_x_velocity ++;
	state_x_position ++:
}


int main(int argc, char **argv){
	ros::init(argc, argv, "test_robot");
	ros::NodeHandle n;
	ros::Publisher shoutout = n.advertise<std_msgs::String>("test_robot", 100);

	ros::Rate loop_rate(120);

	phoenix_test robot;
	controller_manager::ControllerManager cm(&robot);

	while(ros::ok()){


		robot.read();
		cm.update(robot.get_time(), robot.get_period());
		robot.write()

		std_msgs::String msg;
		sprintf(msg, "test_robot: cc= %f, out= %f\n", eff[0] , state_x_position);

		shoutout.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();

	}
}












