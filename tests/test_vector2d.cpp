// Phase 1 unit tests: Vector2D math and Target linear motion.
#include <gtest/gtest.h>

#include "core/Vector2D.h"
#include "simulation/Target.h"

TEST(Vector2D, Add) { GTEST_SKIP() << "TODO(phase1): implement Vector2D::operator+ and assert."; }
TEST(Vector2D, Subtract) { GTEST_SKIP() << "TODO(phase1)"; }
TEST(Vector2D, ScalarMultiply) { GTEST_SKIP() << "TODO(phase1)"; }
TEST(Vector2D, Norm) { GTEST_SKIP() << "TODO(phase1)"; }
TEST(Vector2D, NormalizedHandlesZeroVector) { GTEST_SKIP() << "TODO(phase1)"; }
TEST(Vector2D, ClampedRespectsMaxNorm) { GTEST_SKIP() << "TODO(phase1)"; }

TEST(Target, LinearMotion) { GTEST_SKIP() << "TODO(phase1): position advances by velocity*dt."; }
TEST(Target, VelocityIsConstant) { GTEST_SKIP() << "TODO(phase1)"; }
TEST(World, TimeAccumulates) { GTEST_SKIP() << "TODO(phase1)"; }
