/*
 * MoveRobot.cpp
 *
 *  Created on: Nov 18, 2018
 *      Author: root
 */

#include "MoveRobot.hpp"

MoveRobot::MoveRobot() {
  vel.linear.x = 0.0;
  vel.linear.y = 0.0;
  vel.linear.z = 0.0;
  vel.angular.x = 0.0;
  vel.angular.y = 0.0;
  vel.angular.z = 0.0;
  pub = nh.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity",
                                           100);
  sub = nh.subscribe<sensor_msgs::LaserScan>("/scan", 50, &Sensor::scanCb,
                                             &scan);
  pub.publish(vel);
}

MoveRobot::~MoveRobot() {
  vel.linear.x = 0.0;
  vel.linear.y = 0.0;
  vel.linear.z = 0.0;
  vel.angular.x = 0.0;
  vel.angular.y = 0.0;
  vel.angular.z = 0.0;
  pub.publish(vel);
}

void MoveRobot::publishVelocity() {
  if (scan.returnCollisionFlag() == true) {
    vel.linear.x = 0.0;
    vel.angular.z = 1.0;
  } else {
    vel.linear.x = 0.5;
    vel.angular.z = 0.0;
  }
  pub.publish(vel);
}
