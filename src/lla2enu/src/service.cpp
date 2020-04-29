#include <ros/ros.h>
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include <math.h>  
#include <nav_msgs/Odometry.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <geometry_msgs/Vector3Stamped.h>

#include <message_filters/sync_policies/exact_time.h>
#include <message_filters/sync_policies/approximate_time.h>



void callback(const geometry_msgs::Vector3StampedConstPtr& msg_front, const geometry_msgs::Vector3StampedConstPtr& msg_obs){

	/*

	float xEastObs_ = msg_obs -> pose.pose.position.x;
	float yNorthObs_ = msg_obs -> pose.pose.position.y;
	float zUpObs_ = msg_obs -> pose.pose.position.z;

	float xEastFront_ = msg_front -> pose.pose.position.x;
	float yNorthFront_ = msg_front -> pose.pose.position.y;
	float zUpFront_ = msg_front -> pose.pose.position.z;

	float unsafe = 3;	
	float crash = 5;
	
        

	if(xEastObs_){
		if(!isnan(xEastObs_) && !isnan(xEastFront_)){
			
			float result = sqrt(pow((xEastFront_ - xEastObs_), 2) + pow((yNorthFront_ - yNorthObs_), 2) + pow((zUpFront_ - zUpObs_), 2)); 
			

			if(result > unsafe)
				ROS_INFO("SAFE %f", result);
			else if (result > crash)
				ROS_INFO("UNSAFE %f", result);
			else
				ROS_INFO("CRASH %f", result);

			// ROS_INFO("%f", result);
		}
		else {
			ROS_INFO("one value is NAN");
		}
	
	}
	else {
		ROS_INFO("obs value still missing");
	}
	
	*/
}



int main(int argc, char **argv){
  	
	ros::init(argc, argv, "listener");

	ros::NodeHandle n_; 
	
	// n_.getParam("/unsafe", unsafe);
        // n_.getParam("/crash", crash);

	message_filters::Subscriber<geometry_msgs::Vector3Stamped> sub_front(n_, "/front_enu", 1);
	message_filters::Subscriber<geometry_msgs::Vector3Stamped> sub_obs(n_, "/obs_enu", 1);

	typedef message_filters::sync_policies::ApproximateTime<geometry_msgs::Vector3Stamped, geometry_msgs::Vector3Stamped> MySyncPolicy;

	message_filters::Synchronizer<MySyncPolicy> sync(MySyncPolicy(10), sub_front, sub_obs);
  	sync.registerCallback(boost::bind(&callback, _1, _2));
	

  	ros::spin();

 	return 0;
}

