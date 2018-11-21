# Turtlebot Walker - Random walk and obstacle avoidance implementation

[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

The Turtlebot moves forward until an obstacle is detected in its vicinity. When the obstacle is detected, the robot rotates until it finds a free path and once found, it moves forward again.

## Prerequisites
The following software packages need to be installed before preceeding with this demo. The setup is installed on Ubuntu 16.04. 
1. Ros Kinetic: http://wiki.ros.org/kinetic/Installation
2. Turtlebot simulation packages:

```
sudo apt-get install ros-kinetic-turtlebot-gazebo ros-kinetic-turtlebot-apps ros-kinetic-turtlebot-rviz-launchers
```
3. Gazebo: http://gazebosim.org/tutorials?tut=install_ubuntu
4. Catkin: http://wiki.ros.org/catkin

The following assumed you have a working ROS workspace.
## Download demo

'''
cd ~/catkin_ws
catkin_make
source devel/setup.bash
cd src/
git clone --recursive https://github.com/AdarshJS/Turtlebot-Walker.git
cd ..
catkin_make
'''

Tip: Include source ~/catkin_ws/devel/setup.bash in the ~/.bashrc file to run it everytime a new terminal is created.

## Running the simulation
To simulate the turtlebot in Gazebo and view its walker behavior, follow:

```
cd ~/catkin_ws
source devel/setup.bash
roslaunch turtlebot_walker walker.launch
```
Press ctrl+c to quit the simulation.

## Observing topics in the ROSbag

Please check the results folder for a ROSbag file called walker.bag. This file has a record of all topics except the camera topics for 30 seconds from the simulated turtlebot. To run this rosbag file:

```
cd ~/catkin_ws/src/turtlebot_walker/results
rosbag play walker.bag
```

To view the topics that have been recorded, run the rosbag first:
```
rostopic list
```

or
```
cd ~/catkin_ws/src/turtlebot_walker/results
rosbag info walker.bag
```

## To record your own rosbag
There is an argument that you can specify with the roslaunch file which can be set to record all topics except camera topics.
```
roslaunch turtlebot_walker walker.launch runRosbag:=true
```
The rosbag file will be stored in the results folder inside the turtlebot_walker package. To run the simulation without the rosbag:

```
roslaunch turtlebot_walker walker.launch runRosbag:=false
``` 


