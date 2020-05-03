#include "ros/ros.h"
#include <nav_msgs/Odometry.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <lla2enu/custom_msg.h>
#include <lla2enu/sliderConfig.h>
#include <dynamic_reconfigure/server.h>

class Service
{
public:
	Service()
	{	
		
		pub_ = n_.advertise<lla2enu::custom_msg>("/results", 1000);
		sub_front_.subscribe(n_, "/front_enu", 10000);
		sub_obs_.subscribe(n_, "/obs_enu", 10000);
		
		sync.reset(new Sync(MySyncPolicy(10), sub_front_, sub_obs_));  

		sync->registerCallback(boost::bind(&Service::callback, this, _1, _2));

		f_ = boost::bind(&Service::sliderCallback, this, _1, _2);
		server_.setCallback(f_);

		n_.getParam("/unsafe", unsafe_);
		n_.getParam("/crash", crash_);
	}

	void sliderCallback(lla2enu::sliderConfig &config, uint32_t level){
		unsafe_ = config.unsafe;
		crash_ = config.crash;
	}

	void callback(const nav_msgs::OdometryConstPtr& msg_front, const nav_msgs::OdometryConstPtr& msg_obs)
	{
		float xEastFront_ = msg_front ->  pose.pose.position.x;
		float yNorthFront_ = msg_front ->  pose.pose.position.y;
		float zUpFront_ = msg_front ->  pose.pose.position.z;

	 	float xEastObs_ = msg_obs ->  pose.pose.position.x;
		float yNorthObs_ = msg_obs ->  pose.pose.position.y;
		float zUpObs_ = msg_obs ->  pose.pose.position.z;

		lla2enu::custom_msg output;
		
		if(!isnan(xEastObs_) && !isnan(xEastFront_)){
			
			float result = sqrt(pow((xEastFront_ - xEastObs_), 2) + pow((yNorthFront_ - yNorthObs_), 2) + pow((zUpFront_ - zUpObs_), 2)); 
			output.distance = result;
			
			if(result > unsafe_)
				output.status_flag = "safe";
				//ROS_INFO("SAFE %f", result);
			else if (result > crash_)
				output.status_flag = "unsafe";
				//ROS_INFO("UNSAFE %f", result);
			else
				output.status_flag = "crash";
				//ROS_INFO("CRASH %f", result);
		}
		else {
			output.distance = NAN;
			output.status_flag = "unknown";
			//ROS_INFO("NaN");
		}
		pub_.publish(output);

	}

private:

	ros::NodeHandle n_; 
	message_filters::Subscriber<nav_msgs::Odometry> sub_front_;
	message_filters::Subscriber<nav_msgs::Odometry> sub_obs_;
	ros::Publisher pub_;

	dynamic_reconfigure::Server<lla2enu::sliderConfig> server_;
	dynamic_reconfigure::Server<lla2enu::sliderConfig>::CallbackType f_;

	typedef message_filters::sync_policies::ApproximateTime<nav_msgs::Odometry, nav_msgs::Odometry> MySyncPolicy;

	typedef message_filters::Synchronizer<MySyncPolicy> Sync;

	boost::shared_ptr<Sync> sync;

	int unsafe_ = 5;	
	int crash_ = 1;

};//End

int main(int argc, char** argv)
{

	ros::init(argc, argv, "service");
	
	Service service;

	ros::spin();

  return 0;
}
