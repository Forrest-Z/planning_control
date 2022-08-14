
#include <ros/ros.h>

#include "geometry_msgs/PoseStamped.h"
#include "planner/cartesian_planner.h"
#include "planner/planner.h"
#include "planning/CenterLine.h"
#include "planning/DynamicObstacles.h"
#include "planning/Obstacles.h"
#include "planning/data_struct.h"
#include "planning/discretized_trajectory.h"
#include "planning/indexed_list.h"
#include "planning/local_view.h"
#include "planning/planning_config.h"
#include "planning/reference_line.h"
#include "planning/reference_line_provider.h"
#include "planning_base.h"
#include "visualization/plot.h"

namespace planning {

class PlanningNode {
 public:
  explicit PlanningNode(const ros::NodeHandle &nh);

  ~PlanningNode() = default;

  void CenterLineCallback(const CenterLineConstPtr &msg);

  // TODO: 处理不同plan中的相同障碍物,进行编号
  void StaticObstaclesCallback(const ObstaclesConstPtr &msg);

  void DynamicObstaclesCallback(const DynamicObstaclesConstPtr &msg);

  void PlanCallback(const geometry_msgs::PoseStampedConstPtr &msg);

 private:
  void Animation(const DiscretizedTrajectory &plan_trajectory);

  void PlotVehicle(int id, const math::Pose &pt, double phi);

  std::array<math::Box2d, 4> GenerateTireBoxes(const math::Pose pose,
                                               double phi = 0.0) const;

 private:
  ros::NodeHandle nh_;
  planning::PlanningConfig config_;

  VehicleState vehicle_state_{};

  LocalView local_view_;

  std::unique_ptr<PlanningBase> planning_base_;

  Frame::IndexedDynamicObstacles index_dynamic_obstacles_;
  Frame::IndexedStaticObstacle index_static_obstacles_;

  ros::Subscriber obstacles_subscriber_, dynamic_obstacles_subscriber_,
      goal_subscriber_;
};

}  // namespace planning
