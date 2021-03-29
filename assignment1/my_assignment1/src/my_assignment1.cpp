#include "ros/ros.h"
#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"
#include "mytarget_server/randomtarget.h"
#include <math.h>

ros::Publisher pub;
ros::ServiceClient client1;
mytarget_server::randomtarget target;

//calculate distance between target position and robot position
int distance(int x, int y)
{
	return sqrt(x^2+y^2);

}	

void positionCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
	//looking robot position and target position
	ROS_INFO("Robot position : [%f, %f]", msg->pose.pose.position.x, msg->pose.pose.position.y);	
	ROS_INFO("Robot target : [%f, %f]", target.response.x, target.response.y);	
	geometry_msgs::Twist vel;

	//calculate distance between target position and robot position
	int dx=target.response.x-msg->pose.pose.position.x;
	int dy=target.response.y-msg->pose.pose.position.y;	
	int d=distance(dx,dy);

	//if distance is smaller than 0.1,we ask new target
	//if distance is bigger than 0.1, we set vel and publish it
	if(d<=0.1){
		ROS_INFO("target has been reached");
		target.request.min= -6.0;
		target.request.max= 6.0;
		client1.call(target);
	}
	else if(d>0.1){
	
		vel.linear.x=1*dx;
		vel.linear.y=1*dy;
		pub.publish(vel);
	}		
	
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "my_assignment1");
	//declare new node
	ros::NodeHandle n;

	//initialize publisher to topic /cmd_vel
	pub= n.advertise<geometry_msgs::Twist>("/cmd_vel",1000);

	//initialize subscribe to see position of robot to /odom topic
	ros::Subscriber sub=n.subscribe("/odom",1000,positionCallback);

	//initialize client for random target
	client1=n.serviceClient<mytarget_server::randomtarget>("/randomtarget");

	// callİng target for first movement
	target.request.min= -6.0;
	target.request.max= 6.0;
	client1.call(target);
	ros::spin();
	return 0;

}
