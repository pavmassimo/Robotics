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
  tf
)

add_message_files(
  FILES 
  custom_msg.msg
)

add_service_files(
  FILES
  distance.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

generate_dynamic_reconfigure_options(
  cfg/slider.cfg
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

add_executable(subscriber_node src/subscriber_node.cpp)
target_link_libraries(subscriber_node ${catkin_LIBRARIES})

add_executable(client src/client.cpp)
target_link_libraries(client ${catkin_LIBRARIES})
add_dependencies(client ${catkin_EXPORTED_TARGETS})

add_executable(server src/server.cpp)
target_link_libraries(server ${catkin_LIBRARIES})
add_dependencies(server ${catkin_EXPORTED_TARGETS})

