
#pragma once

#include <cassert>
#include <utility>
#include <vector>

#include "math/vec2d.h"
#include "planning/data_struct.h"

namespace planning {

using math::Vec2d;

class ReferenceLine {
 public:
  ReferenceLine() = default;

  ReferenceLine(const ReferenceLine &rhs, size_t begin, size_t end = -1);

  explicit ReferenceLine(std::vector<TrajectoryPoint> points)
      : reference_points_(std::move(points)) {}

  inline const std::vector<TrajectoryPoint> &reference_points() const {
    return reference_points_;
  }

  TrajectoryPoint GetMatchPoint(double station) const;

  TrajectoryPoint GetProjection(const Vec2d &xy) const;

  Vec2d XYToSL(const Vec2d &xy) const;

  Vec2d GetCartesian(double station, double lateral) const;

  double Length() const { return reference_points_.back().s; }

 private:
  std::vector<TrajectoryPoint>::const_iterator QueryLowerBoundStationPoint(
      double station) const;

  std::vector<TrajectoryPoint>::const_iterator QueryNearestPoint(
      const Vec2d &point, double *out_distance = nullptr) const;

 private:
  std::vector<TrajectoryPoint> reference_points_;
};

}  // namespace planning
