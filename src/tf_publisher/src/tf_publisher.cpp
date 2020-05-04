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

		// creating role from args
		role_ = arg.c_str();
		// binding the subscriber depending on role
		sub_ = n_.subscribe("/" + role_ + "_enu", 1000, &tf_publisher::callback, this);
	}

	void callback(const nav_msgs::Odometry::ConstPtr& msg){
		float xEast = msg -> pose.pose.position.x;
		float yNorth = msg -> pose.pose.position.y;
		float zUp = msg -> pose.pose.position.z;
		ros::Time current_time = msg -> header.stamp;
		
		// if the message is empty, we don't publish tf	
		if(isnan(xEast)){
			return;
		}

		// Publish TF
		tf::Transform transform;
		transform.setOrigin(tf::Vector3(xEast, yNorth, zUp) );
		tf::Quaternion q;
		q.setRPY(0, 0, 0);
		transform.setRotation(q);
		br_.sendTransform(tf::StampedTransform(transform, current_time, "world", role_));

	}

private:
	// instantiate node handler
	ros::NodeHandle n_; 
	// instantiate subscriber
	ros::Subscriber sub_;
	// instantiate tf broadcaster
	tf::TransformBroadcaster br_;

	std::string role_;
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "tf_node");

	// Create instance of class tf_publisher
	tf_publisher my_tf_publisher(argv[1]);

	ros::spin();
	return 0;
}	
