/*
 * MoveRobot.hpp
 *
 *  Created on: Nov 18, 2018
 *      Author: root
 */

#ifndef TURTLEBOT_WALKER_INCLUDE_MOVEROBOT_HPP_
#define TURTLEBOT_WALKER_INCLUDE_MOVEROBOT_HPP_

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"
#include "Sensor.hpp"

class MoveRobot {
 private:
  ros::NodeHandle nh;
  ros::Publisher pub;
  ros::Subscriber sub;
  geometry_msgs::Twist vel;
  Sensor scan;


 public:
  MoveRobot();
  ~MoveRobot();
  void publishVelocity();
};



#endif /* TURTLEBOT_WALKER_INCLUDE_MOVEROBOT_HPP_ */
