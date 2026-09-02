#pragma once

#include <Eigen/Dense>

#include "core/Vector2D.h"

namespace core {

// Kinematic state shared by target, drone and estimator.
// Acceleration is unused by the Kalman state vector but handy for the drone.
struct State {
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;

    State() = default;
    State(const Vector2D& position, const Vector2D& velocity);
    State(const Vector2D& position, const Vector2D& velocity, const Vector2D& acceleration);

    // Conversions to/from the Kalman state vector [px, py, vx, vy].
    Eigen::Vector4d toVector() const;
    static State fromVector(const Eigen::Vector4d& v);

    // Measurement vector [px, py].
    Eigen::Vector2d toMeasurement() const;
};

}  // namespace core
