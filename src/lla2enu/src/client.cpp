#include "ros/ros.h"
#include <nav_msgs/Odometry.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <dynamic_reconfigure/server.h>
#include <lla2enu/custom_msg.h>
#include <lla2enu/sliderConfig.h>
#include <lla2enu/distance.h>


class Client
{
public:
	Client()
	{	
		
		// binding subscriber for both front and obs enu odoetry position
		sub_obs_.subscribe(n_, "/obs_enu", 10000);
		sub_front_.subscribe(n_, "/front_enu", 10000);
		// binding publisher to publish the custom message -> it will be published under the topic "results"
		pub_ = n_.advertise<lla2enu::custom_msg>("/results", 1000);

		// binding client to server
		client_ = n_.serviceClient<lla2enu::distance>("calculate_distance");
		
		// binding synchronizer to callback function
		sync.reset(new Sync(MySyncPolicy(10), sub_front_, sub_obs_));  
		sync->registerCallback(boost::bind(&Client::callback, this, _1, _2));

		// binding slider config to callnack function
		f_ = boost::bind(&Client::sliderCallback, this, _1, _2);
		server_.setCallback(f_);

		// getting parameters from launch file
		n_.getParam("/unsafe", unsafe_);
		n_.getParam("/crash", crash_);
	}

	// void sliderCallback function to change the value of unsafe and crash trough the slider
	void sliderCallback(lla2enu::sliderConfig &config, uint32_t level){
		unsafe_ = config.unsafe;
		crash_ = config.crash;
	}

	// void callback; this function is called when two messages are received
	// it creates a distance.srv if the values of the two enu positions are not NAN
	// it sends the positions to the service server and once it has the position, it publishes it with the correct status flag
	void callback(const nav_msgs::OdometryConstPtr& msg_front, const nav_msgs::OdometryConstPtr& msg_obs)
	{
		// instantiate .srv message to send to the server
		lla2enu::distance srv;

		// instantiate .msg message to publish
		lla2enu::custom_msg output;		

		// setting up the message to send to the server
		srv.request.xEastFront = msg_front ->  pose.pose.position.x;
		srv.request.yNorthFront = msg_front ->  pose.pose.position.y;
		srv.request.zUpFront = msg_front ->  pose.pose.position.z;

		srv.request.xEastObs =  msg_obs ->  pose.pose.position.x;
		srv.request.yNorthObs = msg_obs ->  pose.pose.position.y;
		srv.request.zUpObs = msg_obs ->  pose.pose.position.z;
		
		// checking if one of the message is server
		if(!isnan(srv.request.xEastObs) && !isnan(srv.request.xEastFront)){
			
			// checking server is available
			if(client_.call(srv)){
				
				output.distance = (float)srv.response.distance;
						
				if(output.distance > unsafe_)
					output.status_flag = "safe";
					//ROS_INFO("SAFE %f", result);
				else if (output.distance > crash_)
					output.status_flag = "unsafe";
					//ROS_INFO("UNSAFE %f", result);
				else
					output.status_flag = "crash";
					//ROS_INFO("CRASH %f", result);
			} else {
				output.status_flag = "server not reachable";
				output.distance = NAN;
			}
		}
		else {
			output.distance = NAN;
			output.status_flag = "unknown";
			//ROS_INFO("NaN");
		}

		// publishing result
		pub_.publish(output);

	}

private:

	// instantiate node handles, two subscribers (one for each enu position) and the publisher
	ros::NodeHandle n_; 
	message_filters::Subscriber<nav_msgs::Odometry> sub_front_;
	message_filters::Subscriber<nav_msgs::Odometry> sub_obs_;
	ros::Publisher pub_;

	// instantiate service client
	ros::ServiceClient client_;

	// instantiate the synchrnizer with an Approximate Time policy
	typedef message_filters::sync_policies::ApproximateTime<nav_msgs::Odometry, nav_msgs::Odometry> MySyncPolicy;
	typedef message_filters::Synchronizer<MySyncPolicy> Sync;
	boost::shared_ptr<Sync> sync;

	// instantiate the dynami reconfigure
	dynamic_reconfigure::Server<lla2enu::sliderConfig> server_;
	dynamic_reconfigure::Server<lla2enu::sliderConfig>::CallbackType f_;

	// instantiate unsafe and crash parameters
	int unsafe_ = 5;	
	int crash_ = 1;

};//End

int main(int argc, char** argv)
{

	ros::init(argc, argv, "client");
	
	// create instance of the class Client
	Client client;

	ros::spin();

  return 0;
}
