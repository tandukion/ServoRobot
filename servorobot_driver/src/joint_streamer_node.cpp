/*

*/

#include <industrial_robot_client/joint_trajectory_streamer.h>

using industrial_robot_client::joint_trajectory_streamer::JointTrajectoryStreamer;

int main(int argc, char** argv)
{
  // initialize node
  ros::init(argc, argv, "motion_interface");

  // launch Joint Trajectory Streamer connection handlers
  JointTrajectoryStreamer motionInterface;
  motionInterface.init();

  //run the node
  motionInterface.run();

  return 0;
}
