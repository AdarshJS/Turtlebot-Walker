#ifndef INCLUDE_MOVEROBOT_HPP_
#define INCLUDE_MOVEROBOT_HPP_

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
 * @file       MoveRobot.hpp
 * @author     Adarsh Jagan Sathyamoorthy
 * @copyright  3-clause BSD
 * @brief      MoveRobot class declartion
 * Declares methods to publish velocities to turtlebot
 */

#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"
#include "Sensor.hpp"
/**
 * @brief Class MoveRobot
 * class to publish velocity commands to turtlebot
 */
class MoveRobot {
 private:
  ros::NodeHandle nh;
  ros::Publisher pub;
  ros::Subscriber sub;
  geometry_msgs::Twist vel;
  Sensor scan;


 public:
  /**
   * @brief constructor of MoveRobot class
   * @param none
   * @return none
   * initializes values of linear and angular velocities for /mobile_base/commands/velocity topic
   * and initializes the publisher and subscriber variables
   */
  MoveRobot();
  /**
   * @brief destructor for MoveRobot class
   * @param none
   * @return none
   * destroys  class object when object goes out of scope.
   */
  ~MoveRobot();
  /**
   * @brief function publishVelocity
   * @param none
   * @return none
   * Publish velocity commands to the Turtlebot to avoid obstacle.
   */
  void publishVelocity();
};



#endif  // INCLUDE_MOVEROBOT_HPP_
