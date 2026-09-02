#pragma once

#include "core/State.h"
#include "core/Vector2D.h"

namespace control {

// PD control law: outputs the acceleration command for the drone.
class Controller {
public:
    Controller() = default;
    Controller(double gain_position, double gain_velocity);

    // Acceleration = Kp * (goal_pos - drone_pos) + Kd * (goal_vel - drone_vel),
    // saturated to the drone's acceleration limit.
    core::Vector2D compute(const core::State& drone_state,
                           const core::Vector2D& goal_position,
                           const core::Vector2D& goal_velocity) const;

    void setGains(double gain_position, double gain_velocity);

private:
    double gain_position_{0.0};
    double gain_velocity_{0.0};
};

}  // namespace control
