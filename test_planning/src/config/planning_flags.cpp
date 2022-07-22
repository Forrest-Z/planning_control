/**
 * @file
 */

#include "config/planning_flags.h"
#include <gflags/gflags.h>

namespace mujianhua {
namespace planning {

DEFINE_double(car_width, 2.0, "");

DEFINE_double(search_longitudial_spacing, 1.5,
              "longitudinal spacing when searching");

DEFINE_double(rear_length, -1.0, "rear axle to rear edge");

DEFINE_double(front_length, 3.9, "rear axle to front edge");

DEFINE_double(search_lateral_spacing, 0.6, "lateral spacing when searching");

DEFINE_double(search_lateral_range, 10.0, "lateral range when searching");

DEFINE_bool(compute_time_output, true, "Output compute detail on screen.");

DEFINE_bool(enable_dynamic_segmentation, true,
            "dense segmentation when the curvature is large.");

DEFINE_string(smoothing_method, "TENSION2", "Path smoothing method.");

} // namespace planning
} // namespace mujianhua