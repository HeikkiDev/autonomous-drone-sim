#pragma once

#include "core/State.h"
#include "core/Vector2D.h"

namespace simulation {

// Ground-truth target moving with constant velocity.
class Target {
public:
    Target() = default;
    Target(const core::Vector2D& position, const core::Vector2D& velocity);

    // Integrates position from velocity over dt.
    void update(double dt);

    const core::State& state() const;
    core::Vector2D position() const;
    core::Vector2D velocity() const;
    void setVelocity(const core::Vector2D& velocity);

private:
    core::State state_;
};

}  // namespace simulation
