#pragma once

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

class Sensor{
 private:
  bool collisionFlag = false;

 public:
  Sensor();
  ~Sensor();
  void scanCb(const sensor_msgs::LaserScan::ConstPtr& scan);
  bool returnCollisionFlag();
};
