#include "ros/ros.h"
#include "geometry_msgs/Vector3Stamped.h"
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/exact_time.h>
#include <message_filters/sync_policies/approximate_time.h>



void callback(const geometry_msgs::Vector3StampedConstPtr& msg_front, const geometry_msgs::Vector3StampedConstPtr& msg_obs)
{

	float xEastFront_ = msg_front -> vector.x;
	float yNorthFront_ = msg_front -> vector.y;
	float zUpFront_ = msg_front -> vector.z;

 	float xEastObs_ = msg_obs -> vector.x;
	float yNorthObs_ = msg_obs -> vector.y;
	float zUpObs_ = msg_obs -> vector.z;

	float unsafe = 2;	
	float crash = 3;

	// n_.getParam("/unsafe", unsafe);
	// n_.getParam("/crash", crash);
	
	if(!isnan(xEastObs_) && !isnan(xEastFront_)){
		
		float result = sqrt(pow((xEastFront_ - xEastObs_), 2) + pow((yNorthFront_ - yNorthObs_), 2) + pow((zUpFront_ - zUpObs_), 2)); 
		
		if(result > unsafe)
			ROS_INFO("SAFE %f", result);
		else if (result > crash)
			ROS_INFO("UNSAFE %f", result);
		else
			ROS_INFO("CRASH %f", result);
	}
	else {
		ROS_INFO("obs value still missing");
	}
	
	

}


int main(int argc, char** argv)
{

	ros::init(argc, argv, "subscriber");
	ros::NodeHandle n_; 
	message_filters::Subscriber<geometry_msgs::Vector3Stamped> sub_front(n_, "/front_enu", 10000);
	message_filters::Subscriber<geometry_msgs::Vector3Stamped> sub_obs(n_, "/obs_enu", 10000);

	ros::Subscriber sub1_, sub2_;

	sub1_ = n_.subscribe("/front_enu", 1000, &callbackFront);
	sub2_ = n_.subscribe("/obs_enu", 1000, &callbackSub);

	typedef message_filters::sync_policies::ApproximateTime<geometry_msgs::Vector3Stamped, geometry_msgs::Vector3Stamped> MySyncPolicy;
	message_filters::Synchronizer<MySyncPolicy> sync(MySyncPolicy(100000), sub_front, sub_obs);
	sync.registerCallback(boost::bind(&callback, _1, _2));


	ros::spin();

  return 0;
}
