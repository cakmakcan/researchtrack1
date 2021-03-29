# Research Track I - first assignment

The assignment requires controlling a holonomic robot in a 2d space with a simple 2d simulator, Stage. 
The simulator can be launched by executing the command:

```
rosrun stage_ros stageros $(rospack find assignment1)/world/exercise.world

### information regarding my_assignment1 package

-This package contains first node source file (assignment1/my_assignment1/src/my_assignment1.cpp) that implements a ROS publisher(cmd_vel, for setting the robot speed), a ROS subscriber (odom, for knowing the actual robot position) and a ROS client (for receiving the random target).

-The node can be launched by executing the command:

rosrun my_assignment1 my_assignment1

### information regarding mytarget_server package

-This package contains second node source file (assignment1/mytarget_server/src/randomtarget_server.cpp) that implemets a ROS server to generate random target.
-To be able to get random target, random target service(mytarget_server/srv/randomtarget.srv) is used. 

-The node can be launched by executing the command:

rosrun mytarget_server randomtarget_server


