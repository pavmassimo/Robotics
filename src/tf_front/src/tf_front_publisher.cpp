#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include <tf/transform_broadcaster.h>
#include "std_msgs/Float64MultiArray.h"
#include "sensor_msgs/NavSatFix.h"
#include <math.h>  

class tf_front_publisher
{
public:
	tf_front_publisher(){
		sub_ = n_.subscribe("/front_enu", 1000, &tf_front_publisher::callback, this);
	}

	void callback(const std_msgs::Float64MultiArray::ConstPtr& msg){

		std::vector<double> data = msg -> data;

		tf::Transform transform;
		transform.setOrigin( tf::Vector3(0, 0, 0) );
		tf::Quaternion q;
		q.setRPY(data[0], data[1], data[2]);
		transform.setRotation(q);
		br_.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "front"));
	}

private:
	ros::NodeHandle n_;
	tf::TransformBroadcaster br_;
	ros::Subscriber sub_;
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");
	tf_front_publisher my_tf_front_publisher;
	ros::spin();
	return 0;
}	
