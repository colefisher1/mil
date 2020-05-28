#ifndef MIL_INCLINOMETER_GAZEBO_HPP
#define MIL_INCLINOMETER_GAZEBO_HPP

#include <mil_msgs/IncrementalLinearVelocityStamped.h>
#include <ros/ros.h>
#include <gazebo/common/common.hh>
#include <gazebo/sensors/sensors.hh>
#include <ignition/math/Vector3.hh>
#include <mil_gazebo/mil_gazebo_utils.hpp>

namespace mil_gazebo
{
class MilInclinometerGazebo : public gazebo::SensorPlugin
{
public:
  MilInclinometerGazebo();
  ~MilInclinometerGazebo();
  void Load(gazebo::sensors::SensorPtr _parent, sdf::ElementPtr _sdf);

private:
  void OnUpdate();

  ros::NodeHandle nh_;
  ros::Publisher pub_;
  int queue_size;
  std::string topic_name;

  gazebo::sensors::SensorPtr sensor_;
  gazebo::physics::LinkPtr parent_;
  gazebo::event::ConnectionPtr update_connection_;

  ignition::math::Vector3d current_velocity;
  ignition::math::Vector3d previous_velocity;
  ignition::math::Vector3d incremental_velocity;

  std::string frame_name;
  mil_msgs::IncrementalLinearVelocityStamped msg_;
};
}  // namespace mil_gazebo

#endif
