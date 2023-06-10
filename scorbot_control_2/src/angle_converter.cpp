#include <ros/ros.h>
#include "scorbot_control_2/angleConverter.h"
#include <math.h>

bool convert_radians_to_degrees(scorbot_control_2::angleConverter::Request &req,
                                scorbot_control_2::angleConverter::Response &res)
{
    res.base = static_cast<int>(((req.base+(M_PI/2))*180)/M_PI);
    res.shoulder =  180-static_cast<int>(((req.shoulder+(M_PI/2))*180)/M_PI);
    res.elbow =  static_cast<int>(((req.elbow+(M_PI/2))*180)/M_PI);
    res.gripper = static_cast<int>(((-req.gripper)*180)/(M_PI));
    return true; 
}

bool convert_degrees_to_radians(scorbot_control_2::angleConverter::Request &req,
                                scorbot_control_2::angleConverter::Response &res)
{
    res.base = static_cast<int>(((req.base+(M_PI/2))*180)/M_PI);
    res.shoulder =  180-static_cast<int>(((req.shoulder+(M_PI/2))*180)/M_PI);
    res.elbow =  static_cast<int>(((req.elbow+(M_PI/2))*180)/M_PI);
    res.gripper = static_cast<int>(((-req.gripper)*180)/(M_PI));
    return true; 
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "angles_converter");
    ros::NodeHandle n;
    ros::ServiceServer radians_to_degrees = n.advertiseService("radians_to_degrees", convert_radians_to_degrees);
    ros::ServiceServer degrees_to_radians = n.advertiseService( "degrees_to_radians", convert_degrees_to_radians);
    ros::spin();
    return 0;

}