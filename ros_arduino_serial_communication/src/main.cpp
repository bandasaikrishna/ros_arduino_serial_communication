#include<iostream>
#include<stdlib.h>
#include<ros_arduino_serial_communication/SerialPort.h>
#include<ros/ros.h>

using namespace std;
using namespace mn::CppLinuxSerial;


int main(int argc, char** argv){

    ros::init(argc, argv, "main");
    ros::NodeHandle nh;
    ros::Rate loop_rate(1);
    std::string device0Name_="/dev/ttyS2"; // Give the port name of arduino
    std::string readData;
	SerialPort serialPort0(device0Name_, BaudRate::B_9600);
	serialPort0.Open();
while (ros::ok())
{
    serialPort0.Write("ONx");
    serialPort0.Read(readData);
    ROS_INFO("data: %s", readData.c_str());
    loop_rate.sleep();

	
	serialPort0.Write("OFFx");
	serialPort0.Read(readData);
    ROS_INFO("data: %s", readData.c_str());
	loop_rate.sleep();
	
	ros::spinOnce();
}
	return 0;
}
