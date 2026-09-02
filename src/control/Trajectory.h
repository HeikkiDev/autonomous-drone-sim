#pragma once

#include "core/State.h"

namespace control {

// Constant-velocity extrapolation of the estimated target state.
class Trajectory {
public:
    Trajectory() = default;
    explicit Trajectory(double horizon);

    // Propagates state forward by `horizon` seconds.
    core::State predictState(const core::State& state, double horizon) const;
    core::State predictState(const core::State& state) const;

    void setHorizon(double horizon);
    double horizon() const;

private:
    double horizon_{0.0};
};

}  // namespace control
