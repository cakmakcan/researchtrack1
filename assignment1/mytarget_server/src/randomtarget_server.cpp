#include "ros/ros.h"
#include "mytarget_server/randomtarget.h"


float randMToN(float Min, float Max)
{
return ((float(rand()) / float(RAND_MAX)) * (Max - Min)) + Min;
}

bool myrandom (mytarget_server::randomtarget::Request &req, mytarget_server::randomtarget::Response &res){
res.x = randMToN(req.min, req.max);
res.y = randMToN(req.min, req.max);
return true;
}



int main(int argc, char **argv)
{
    ros::init(argc, argv, "randomtarget_server");
    ros::NodeHandle n;
    ros::ServiceServer service=n.advertiseService("/randomtarget",myrandom);
    ros::spin();

    return 0;
}
