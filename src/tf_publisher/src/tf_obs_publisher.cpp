#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include <tf/transform_broadcaster.h>
#include "std_msgs/Float64MultiArray.h"
#include "sensor_msgs/NavSatFix.h"
#include <math.h>  

class tf_obs_publisher
{
public:
	tf_obs_publisher(){
		sub_ = n_.subscribe("/obs_enu", 1000, &tf_obs_publisher::callback, this);
	}

	void callback(const std_msgs::Float64MultiArray::ConstPtr& msg){

		std::vector<double> data = msg -> data;
		if(isnan(data[0])){
			return;
		}
		tf::Transform transform;
		transform.setOrigin( tf::Vector3(data[0]/100, data[1]/100, data[2]/100) );
		tf::Quaternion q;
		q.setRPY(0, 0, 0);
		transform.setRotation(q);
		br_.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "obs"));
	}

private:
	ros::NodeHandle n_;
	tf::TransformBroadcaster br_;
	ros::Subscriber sub_;
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");
	tf_obs_publisher my_tf_obs_publisher;
	ros::spin();
	return 0;
}	
