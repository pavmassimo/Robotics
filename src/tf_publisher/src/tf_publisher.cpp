#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include <tf/transform_broadcaster.h>
#include "std_msgs/String.h"
#include <math.h>  
#include <nav_msgs/Odometry.h>


class tf_publisher
{
public:
	tf_publisher(){

		// create the subscribers to the enu of both front and obs
		subFront_ = n_.subscribe("/front_enu", 1000, &tf_publisher::callbackFront, this);
		subObs_ = n_.subscribe("/obs_enu", 1000, &tf_publisher::callbackObs, this);

		// create the publisher to publish the odometry message of both front and obs
		pubFront_ = n_.advertise<nav_msgs::Odometry>("/front_odometry", 1000);
		pubObs_ = n_.advertise<nav_msgs::Odometry>("/obs_odometry", 1000);
	}

	void callbackFront(const geometry_msgs::Vector3Stamped::ConstPtr& msg){

		float xEast = msg -> vector.x;
		float yNorth = msg -> vector.y;
		float zUp = msg -> vector.z;

		// if the message is empty, we don't publish odometry or tf
		if(isnan(xEast)){
			return;
		}
		
		// Publish Odometry front
		nav_msgs::Odometry output;
		output.header.stamp = current_time;
		output.header.frame_id = "odom_front";
		output.pose.pose.position.x = xEast;
		output.pose.pose.position.y = yNorth;
		output.pose.pose.position.z = zUp;
		pubFront_.publish(output);

		// Publish TF front
		tf::Transform transform;
		transform.setOrigin( tf::Vector3(xEast/100, yNorth/100, zUp/100) );
		tf::Quaternion q;
		q.setRPY(0, 0, 0);
		transform.setRotation(q);
		br_.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "front"));
	}

	void callbackObs(const geometry_msgs::Vector3Stamped::ConstPtr& msg){

		float xEast = msg -> vector.x;
		float yNorth = msg -> vector.y;
		float zUp = msg -> vector.z;
		
		// if the message is empty, we don't publish odometry or tf	
		if(isnan(xEast)){
			return;
		}

		// Publish Odometry obs
		nav_msgs::Odometry output;
		output.header.stamp = current_time;
		output.header.frame_id = "odom_obs";
		output.pose.pose.position.x = xEast;
		output.pose.pose.position.y = yNorth;
		output.pose.pose.position.z = zUp;
		output.pose.orientation = 1
		pubObs_.publish(output);

		// Publish TF obs
		tf::Transform transform;
		transform.setOrigin( tf::Vector3(xEast/100, yNorth/100, zUp/100) );
		tf::Quaternion q;
		q.setRPY(0, 0, 0);
		transform.setRotation(q);
		br_.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "obs"));
	}

private:
	ros::NodeHandle n_;
	tf::TransformBroadcaster br_;
	ros::Subscriber subFront_;
	ros::Subscriber subObs_;
	ros::Publisher pubFront_;
	ros::Publisher pubObs_;
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");
	tf_publisher my_tf_publisher;
	ros::spin();
	return 0;
}	
