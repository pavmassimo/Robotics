#include "ros/ros.h"
#include "geometry_msgs/Vector3Stamped.h"
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

class Service
{
public:
	Service()
	{	
		

		sub_front_.subscribe(n_, "/front_enu", 10000);
		sub_obs_.subscribe(n_, "/obs_enu", 10000);
		
		sync.reset(new Sync(MySyncPolicy(10), sub_front_, sub_obs_));  


		sync->registerCallback(boost::bind(&Service::callback, this, _1, _2));

		ROS_INFO("buildato");
	}


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

		n_.getParam("/unsafe", unsafe);
		n_.getParam("/crash", crash);
		
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
			ROS_INFO("NaN");
		}
		
		

	}

private:

	ros::NodeHandle n_; 
	message_filters::Subscriber<geometry_msgs::Vector3Stamped> sub_front_;
	message_filters::Subscriber<geometry_msgs::Vector3Stamped> sub_obs_;
	typedef message_filters::sync_policies::ApproximateTime<geometry_msgs::Vector3Stamped, geometry_msgs::Vector3Stamped> MySyncPolicy;

	typedef message_filters::Synchronizer<MySyncPolicy> Sync;

	boost::shared_ptr<Sync> sync;

};//End

int main(int argc, char** argv)
{

	ros::init(argc, argv, "subscriber");
	
	Service service;

	ros::spin();

  return 0;
}
