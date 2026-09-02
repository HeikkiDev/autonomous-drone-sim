// Phase 6-8 unit tests: drone kinematics, controller, trajectory prediction.
#include <gtest/gtest.h>

#include "control/Controller.h"
#include "control/Trajectory.h"
#include "simulation/Drone.h"

TEST(Drone, IntegratesAccelerationIntoVelocity) { GTEST_SKIP() << "TODO(phase6)"; }
TEST(Drone, SaturatesAcceleration) { GTEST_SKIP() << "TODO(phase6)"; }
TEST(Controller, ZeroErrorGivesZeroCommand) { GTEST_SKIP() << "TODO(phase7)"; }
TEST(Controller, StabilizesAroundTarget) { GTEST_SKIP() << "TODO(phase7)"; }
TEST(Trajectory, PredictionAccuracyConstantVelocity) { GTEST_SKIP() << "TODO(phase8)"; }
