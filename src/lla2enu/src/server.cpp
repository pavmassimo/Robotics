#include <ros/ros.h>
#include <lla2enu/distance.h>


bool callback(lla2enu::distance::Request &req, lla2enu::distance::Response &res){

	// calculating distance given input and returning it inside res
	
	float xEastFront = req.xEastFront;
	float yNorthFront = req.yNorthFront;
	float zUpFront = req.zUpFront;
	float xEastObs = req.xEastObs;
	float yNorthObs = req.yNorthObs;
	float zUpObs = req.zUpObs;

	float result = sqrt(pow((xEastFront - xEastObs), 2) + pow((yNorthFront - yNorthObs), 2) + pow((zUpFront - zUpObs), 2)); 
	
	res.distance = result;	

	return true;
}



int main(int argc, char** argv)
{

	ros::init(argc, argv, "server");
	
	ros::NodeHandle n;

	// creating service for calculating distance given
	ros::ServiceServer service= n.advertiseService("calculate_distance", callback);

	ros::spin();

 	return 0;

}
