# Research Track I - second assignment

The assignment requires controlling a robot in a given map.
The architecture should be able to get the user request, and let the robot execute one of the following behaviors
(depending on the input of users):
- 1) move randomly in the environment, by choosing 1 out of 6 possible target positions:
[(-4,-3);(-4,2);(-4,7);(5,-7);(5,-3);(5,1)], implementing a random position service as in the assignment 1
- 2) directly ask the user for the next target position (checking that the position is one of the possible six)
and reach it
- 3) start following the external walls
- 4) stop in the last position
- 5) (optional) change the planning algorithm to dijkstra (move_base) to the bug0
 
The simulator can be launched by executing the command:

```
roslaunch final_assignment simulation_gmapping.launch
roslaunch final_assignment move_base.launch

### information regarding final_assignment and my_srv2 package

-final_assignment package contains folders such as config, launch, param, scripts, urdf, and world. Our source files in scripts folder. Source files are go_to_point_service_m.py, wall_follow_service_m.py and user_interface.py. In addition, there is a random target server package whose name is my_srv2. In that package, we have a service node(targetserver.py) and a service(target.srv).

-The nodes can be launched by executing the command:

rosrun final_assignment wall_follow_service_m.py
rosrun my_srv2 targetserver.py
rosrun final_assignment user_interface.py

### Report of the assignment 

-Initially, we have an environment as a given map and also six possible targets that has been decided before. To be able to send our robots to those targets, we should publish x and y position to /move_base/status topic. After that, we use MoveBaseActionGoal message belonging to our topic. However, we have two options to move our robot in the environment by asking to users to choose target randomly or directly. For generating our random targets, I used service and client method. By sending request from client node to our service server, we acquire our random target as a response. For getting information regarding completion of the movement, we subscribed move_base/status topic including GoalStatusArray message.

-Secondly, our third option is the robot to follow external walls. wall_follow_service_m.py service is used to obtain the behaviour that our robot must perform. By activating this service in our third condition, we accomplish this objective succesfully. In addition, we publish velocity through /cmd_vel topic twist message for fourth objective.

-As a result, Local planner gets information from sensor and path plan in limited space. Furthermore, global planner builds global map and considers all possible information to accomplish the goal. Dijkstra's algorithm decides to path to get the desired position. A global and local map are built in run time for collision avoidance. To improve the behaviour, sleep is used for the robot in order to complete its behaviour. Also, in case of unreachable target, a syntax warning is implemented for the user's awareness.


Author : Can Çakmak






