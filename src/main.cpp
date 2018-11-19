/*
 * main.cpp
 *
 *  Created on: Nov 18, 2018
 *      Author: root
 */

#include "ros/ros.h"
#include "Sensor.hpp"
#include "MoveRobot.hpp"

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "Walker");
  MoveRobot control;
  ros::Rate loopRate(10);
  while (ros::ok()) {
    control.publishVelocity();
    ros::spinOnce();
    loopRate.sleep();
  }
}


