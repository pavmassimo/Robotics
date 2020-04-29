cmake_minimum_required(VERSION 2.8.3)
project(lla2enu)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_filters
)



catkin_package( CATKIN_DEPENDS
  geometry_msgs
  message_filters
)


include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)



add_executable(subscriber_front src/subscriber_front.cpp)
add_executable(subscriber_obs src/subscriber_obs.cpp)
add_executable(service src/service.cpp)

target_link_libraries(subscriber_front ${catkin_LIBRARIES})
target_link_libraries(subscriber_obs ${catkin_LIBRARIES})
target_link_libraries(service ${catkin_LIBRARIES})
