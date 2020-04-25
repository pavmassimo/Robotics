#include <ros/ros.h>
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Float64MultiArray.h"
#include "sensor_msgs/NavSatFix.h"
#include <math.h>  


class Service
{
public:

	Service()
	{
		//Topic you want to publish
		//pub_ = n_.advertise<std_msgs::Float64MultiArray>("/obs_enu", 1000);

		//Topic you want to subscribe
		sub_front_ = n_.subscribe("/front_enu", 1000, &Service::callbackFront, this);
		sub_obs_ = n_.subscribe("/obs_enu", 1000, &Service::callbackObs, this);
	}

	void callbackFront(const std_msgs::Float64MultiArray::ConstPtr& msg){
		std::vector<double> data = msg -> data;
		float xEastFront_ = data[0];
		ROS_INFO("xEastFront_: [%f]", xEastFront_);
	  
	  
	}

	void callbackObs(const std_msgs::Float64MultiArray::ConstPtr& msg){
		/*data = msg.data
		xEastObs_ = 
		ROS_INFO("ENU position: [%f,%f, %f]", xEast, yNorth,zUp);
	  */
	  
	}

	void calculateDistance(){
		float result = sqrt(pow((xEastFront_ - xEastObs_), 2) + pow((yNortFront_ - yNortObs_), 2) + pow((zUpFront_ - zUpObs_), 2)); 

		ROS_INFO("%f", result);
	}

private:
	float xEastFront_;
	float yNortFront_;
	float zUpFront_;
	float xEastObs_;
	float yNortObs_;
	float zUpObs_;

	ros::NodeHandle n_; 
	//ros::Publisher pub_;
	ros::Subscriber sub_obs_;
	ros::Subscriber sub_front_;

};

int main(int argc, char **argv){
  	
	ros::init(argc, argv, "listener");

	Service service;

  	ros::spin();

  return 0;
}

