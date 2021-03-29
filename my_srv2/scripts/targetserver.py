#!/usr/bin/env python
import rospy
from my_srv2.srv import target, targetResponse
import random


def handle_random(req):
	return targetResponse(random.randint(req.min, req.max))

def randomserver():
	rospy.init_node('targetserver')
	s=rospy.Service('twotarget', target, handle_random)
	rospy.spin()

if __name__=="__main__":
	randomserver()	
