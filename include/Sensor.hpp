#pragma once
/**
 * Copyright (c) 2018, Adarsh Jagan Sathyamoorthy
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file       Sensor.hpp
 * @author     Adarsh Jagan Sathyamoorthy
 * @copyright  3-clause BSD
 * @brief      Sensor class declartion
 * Class to subscribe to /scan topic and check for imminent collisions.
 */
#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"

/**
 * @brief Class Sensor
 * Sensor class contains methods to listen to laserscan messages and check
 * the proximity to objects in the environment.
 */

class Sensor{
 private:
  bool collisionFlag = false;

 public:
  /**
   * @brief constructor Sensor
   * @param none
   * @return none
   * Initializes the value of the flag that denotes a collision
   */
  Sensor();
  /**
   * @brief destructor Sensor
   * @param none
   * @return none
   * Destroys Sensor class' object.
   */
  ~Sensor();
  /**
   * @brief function scanCb
   * @param scan of type sensor_msgs::LaserScan
   * @return none
   * A call back function to subscribe to /scan topic
   * and raise flag in case of collisions.
   */
  void scanCb(const sensor_msgs::LaserScan::ConstPtr& scan);
  /**
   * @brief function returnCollisionFlag
   * @param none
   * @return true for if collision is detected and false if not
   * Return the current value of collisionFlag
   */
  bool returnCollisionFlag();
};
