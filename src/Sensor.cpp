/*
 * Sensor.cpp
 *
 *  Created on: Nov 18, 2018
 *      Author: root
 */

#include "Sensor.hpp"

Sensor::Sensor() {
  collisionFlag = false;
}

Sensor::~Sensor() {

}

void Sensor::scanCb(const sensor_msgs::LaserScan::ConstPtr& scan) {
  for (int i = 0; i < scan->ranges.size(); i++) {
    if (scan->ranges[i] < 1.0) {
      collisionFlag = true;
      ROS_DEBUG_STREAM("Range "<<scan->ranges[i]<<". Collision imminent!");
      return;
    }
  }
  collisionFlag = false;
  ROS_DEBUG_STREAM("No collisions.");
}

bool Sensor::returnCollisionFlag() {
  return collisionFlag;
}

