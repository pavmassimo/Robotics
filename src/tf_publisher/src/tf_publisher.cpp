#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include <tf/transform_broadcaster.h>
#include "std_msgs/String.h"
#include <math.h>  
#include <nav_msgs/Odometry.h>
#include <iostream>
#include <string>

class tf_publisher
{
public:
	tf_publisher(std::string arg){
		//ROS_INFO("role: [%s]", arg.c_str());
		role_ = arg.c_str();
		// create the subscribers to the enu of both front and obs
		sub_ = n_.subscribe("/" + role_ + "_enu", 1000, &tf_publisher::callback, this);

		// create the publisher to publish the odometry message of both front and obs
		//pub_ = n_.advertise<nav_msgs::Odometry>("/" + role_ + "_odometry", 1000);
	}

	void callback(const nav_msgs::Odometry::ConstPtr& msg){
		float xEast = msg -> pose.pose.position.x;
		float yNorth = msg -> pose.pose.position.y;
		float zUp = msg -> pose.pose.position.z;
		ros::Time current_time = msg -> header.stamp;
		
		// if the message is empty, we don't publish odometry or tf	
		if(isnan(xEast)){
			return;
		}

		//pub_.publish(output);

		// Publish TF obs
		tf::Transform transform;
		transform.setOrigin( tf::Vector3(xEast/100, yNorth/100, zUp/100) );
		tf::Quaternion q;
		q.setRPY(0, 0, 0);
		transform.setRotation(q);
		br_.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", role_));

	}

private:
	ros::NodeHandle n_;
	tf::TransformBroadcaster br_;
	ros::Subscriber sub_;
	//ros::Publisher pub_;
	std::string role_;
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "tf_node");
	tf_publisher my_tf_publisher(argv[1]);
	ros::spin();
	return 0;
}	
