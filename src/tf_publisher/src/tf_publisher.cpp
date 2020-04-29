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
		subFront_ = n_.subscribe("/front_enu", 1000, &tf_publisher::callbackFront, this);
		subObs_ = n_.subscribe("/obs_enu", 1000, &tf_publisher::callbackObs, this);
	}

	void callbackFront(const nav_msgs::Odometry::ConstPtr& msg){

		float xEast = msg -> pose.pose.position.x;
		float yNorth = msg -> pose.pose.position.y;
		float zUp = msg -> pose.pose.position.z;

		
		if(isnan(xEast)){
			return;
		}

		tf::Transform transform;
		transform.setOrigin( tf::Vector3(xEast/100, yNorth/100, zUp/100) );
		tf::Quaternion q;
		q.setRPY(0, 0, 0);
		transform.setRotation(q);
		br_.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "front"));
	}

	void callbackObs(const nav_msgs::Odometry::ConstPtr& msg){

		float xEast = msg -> pose.pose.position.x;
		float yNorth = msg -> pose.pose.position.y;
		float zUp = msg -> pose.pose.position.z;

		
		if(isnan(xEast)){
			return;
		}

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
};

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");
	tf_publisher my_tf_publisher;
	ros::spin();
	return 0;
}	
