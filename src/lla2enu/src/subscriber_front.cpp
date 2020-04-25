#include <ros/ros.h>
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Float64MultiArray.h"
#include "sensor_msgs/NavSatFix.h"
#include <math.h>  
class SubscribeAndPublish
{
public:
  SubscribeAndPublish()
  {
    //Topic you want to publish
    pub_ = n_.advertise<std_msgs::Float64MultiArray>("/front_enu", 1000);

    //Topic you want to subscribe
    sub_ = n_.subscribe("/swiftnav/front/gps_pose", 1000, &SubscribeAndPublish::callback, this);
  }

  void callback(const sensor_msgs::NavSatFix::ConstPtr& msg){
    //ROS_INFO("Input position: [%f,%f, %f]", msg->latitude, msg->longitude,msg->altitude);

    // fixed values

    double a = 6378137;
    double b = 6356752.3142;
    double f = (a - b) / a;
    double e_sq = f * (2-f);
    float deg_to_rad = 0.0174533;

    // input data from msg
    float latitude = msg->latitude;
    float longitude = msg->longitude;
    float h = msg->altitude;

    // fixed position
    float latitude_init = 0.0;
    float longitude_init = 0.0;
    float h0 = 0.0;
    n_.getParam("/starting_latitude_init", latitude_init);
    n_.getParam("/starting_longitude_init", longitude_init);
    n_.getParam("/starting_h0_init", h0);


    //lla to ecef
    float lamb = deg_to_rad*(latitude);
    float phi = deg_to_rad*(longitude);
    float s = sin(lamb);
    float N = a / sqrt(1 - e_sq * s * s);

    float sin_lambda = sin(lamb);
    float  cos_lambda = cos(lamb);
    float  sin_phi = sin(phi);
    float  cos_phi = cos(phi);

    float  x = (h + N) * cos_lambda * cos_phi;
    float  y = (h + N) * cos_lambda * sin_phi;
    float  z = (h + (1 - e_sq) * N) * sin_lambda;

    //ROS_INFO("ECEF position: [%f,%f, %f]", x, y,z);


    // ecef to enu

    lamb = deg_to_rad*(latitude_init);
    phi = deg_to_rad*(longitude_init);
    s = sin(lamb);
    N = a / sqrt(1 - e_sq * s * s);

    sin_lambda = sin(lamb);
    cos_lambda = cos(lamb);
    sin_phi = sin(phi);
    cos_phi = cos(phi);

    float  x0 = (h0 + N) * cos_lambda * cos_phi;
    float  y0 = (h0 + N) * cos_lambda * sin_phi;
    float  z0 = (h0 + (1 - e_sq) * N) * sin_lambda;

    float xd = x - x0;
    float  yd = y - y0;
    float  zd = z - z0;

    float  xEast = -sin_phi * xd + cos_phi * yd;
    float  yNorth = -cos_phi * sin_lambda * xd - sin_lambda * sin_phi * yd + cos_lambda * zd;
    float  zUp = cos_lambda * cos_phi * xd + cos_lambda * sin_phi * yd + sin_lambda * zd;

    //ROS_INFO("ENU position: [%f,%f, %f]", xEast, yNorth,zUp);


    std_msgs::Float64MultiArray output;
    output.data.push_back(xEast);
    output.data.push_back(yNorth);
    output.data.push_back(zUp);
    pub_.publish(output);
  }

private:
  ros::NodeHandle n_; 
  ros::Publisher pub_;
  ros::Subscriber sub_;

};//End of class SubscribeAndPublish

int main(int argc, char **argv)
{
  //Initiate ROS
  ros::init(argc, argv, "listener");

  //Create an object of class SubscribeAndPublish that will take care of everything
  SubscribeAndPublish SAPObject;

  ros::spin();

  return 0;
}