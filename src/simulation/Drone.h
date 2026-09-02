#pragma once

#include "core/State.h"
#include "core/Vector2D.h"

namespace simulation {

// Double-integrator drone: acceleration is the control input.
class Drone {
public:
    Drone() = default;
    Drone(const core::Vector2D& position, const core::Vector2D& velocity);

    // Control input; should saturate at constants::kDroneMaxAcceleration.
    void setAcceleration(const core::Vector2D& acceleration);

    // velocity += acceleration * dt; position += velocity * dt (saturate speed).
    void update(double dt);

    const core::State& state() const;
    core::Vector2D position() const;
    core::Vector2D velocity() const;
    core::Vector2D acceleration() const;

private:
    core::State state_;
};

}  // namespace simulation
