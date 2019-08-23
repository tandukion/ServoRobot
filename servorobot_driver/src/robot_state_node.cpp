/*

*/

#include <industrial_robot_client/robot_state_interface.h>

using industrial_robot_client::robot_state_interface::RobotStateInterface;

int main(int argc, char** argv)
{
  // initialize node
  ros::init(argc, argv, "state_interface");

  // launch Robot State Interface connection handlers
  RobotStateInterface rsi;
  rsi.init();

  //run the node
  ris.run();

  return 0;
}
