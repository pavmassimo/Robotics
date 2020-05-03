cmake_minimum_required(VERSION 2.8.3)
project(lla2enu)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  message_filters
  message_generation
  dynamic_reconfigure
)

add_message_files(
  FILES 
  custom_msg.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  #msg
)

generate_dynamic_reconfigure_options(
  cfg/slider.cfg
#  cfg/DynReconf2.cfg
)

catkin_package( CATKIN_DEPENDS
  geometry_msgs
  message_filters
  message_runtime
)



include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

#add_dependencies(slider ${PROJECT_NAME}_gencfg)

add_executable(subscriber_node src/subscriber_node.cpp)
add_executable(service src/service.cpp)

target_link_libraries(subscriber_node ${catkin_LIBRARIES})
target_link_libraries(service ${catkin_LIBRARIES})
