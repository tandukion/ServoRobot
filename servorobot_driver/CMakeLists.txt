cmake_minimum_required(VERSION 2.8.3)
project(servorobot_driver)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin
  REQUIRED
  COMPONENTS
    industrial_robot_client
)

find_package(Boost REQUIRED COMPONENTS system thread)

catkin_package(
  CATKIN_DEPENDS
    industrial_robot_client
)

# these nodes run on the host computer, so use Linux sockets for
# simple_message sockets
add_definitions(-DLINUXSOCKETS=1)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
  include
  ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

## Robot State Node
add_executable(${PROJECT_NAME}_robot_state
  src/robot_state_node.cpp)
target_link_libraries(${PROJECT_NAME}_robot_state
  industrial_robot_client
  simple_message
  ${catkin_LIBRARIES})
set_target_properties(${PROJECT_NAME}_robot_state
  PROPERTIES OUTPUT_NAME robot_state
  PREFIX "")

add_executable(${PROJECT_NAME}_robot_state_bswap
  src/robot_state_node.cpp)
target_link_libraries(${PROJECT_NAME}_robot_state_bswap
  industrial_robot_client_bswap
  simple_message_bswap
  ${catkin_LIBRARIES})
set_target_properties(${PROJECT_NAME}_robot_state_bswap
  PROPERTIES OUTPUT_NAME robot_state_bswap
  PREFIX "")

## Motion Streaming Node
add_executable(${PROJECT_NAME}_motion_streaming_interface
  src/joint_streamer_node.cpp)
target_link_libraries(${PROJECT_NAME}_motion_streaming_interface
  industrial_robot_client
  simple_message
  ${catkin_LIBRARIES})
set_target_properties(${PROJECT_NAME}_motion_streaming_interface
  PROPERTIES OUTPUT_NAME motion_streaming_interface
  PREFIX "")

add_executable(${PROJECT_NAME}_motion_streaming_interface_bswap
  src/joint_streamer_node.cpp)
target_link_libraries(${PROJECT_NAME}_motion_streaming_interface_bswap
  industrial_robot_client_bswap
  simple_message_bswap
  ${catkin_LIBRARIES})
set_target_properties(${PROJECT_NAME}_motion_streaming_interface_bswap
  PROPERTIES OUTPUT_NAME motion_streaming_interface_bswap
  PREFIX "")

#############
## Install ##
#############


## binaries
install(TARGETS
  ${PROJECT_NAME}_robot_state
  ${PROJECT_NAME}_robot_state_bswap
  ${PROJECT_NAME}_motion_streaming_interface
  ${PROJECT_NAME}_motion_streaming_interface_bswap

  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
