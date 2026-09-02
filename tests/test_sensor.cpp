// Phase 2 unit tests: noise model statistics and sensor behaviour.
#include <gtest/gtest.h>

#include "sensors/NoiseModel.h"
#include "sensors/VirtualSensor.h"

TEST(NoiseModel, GaussianDistribution) { GTEST_SKIP() << "TODO(phase2): mean ~ 0, std ~ configured."; }
TEST(NoiseModel, DeterministicWithSameSeed) { GTEST_SKIP() << "TODO(phase2)"; }
TEST(VirtualSensor, AddsNoise) { GTEST_SKIP() << "TODO(phase2): measurement != ground truth."; }
TEST(VirtualSensor, LossWindowMarksUnavailable) { GTEST_SKIP() << "TODO(phase5)"; }
