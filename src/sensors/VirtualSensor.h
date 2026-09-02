#pragma once

#include <cstdint>

#include "core/Vector2D.h"
#include "sensors/NoiseModel.h"
#include "simulation/Target.h"

namespace sensors {

// Noisy position sensor observing the target, with optional dropout window.
class VirtualSensor {
public:
    VirtualSensor(const simulation::Target& target, double noise_std_dev, std::uint32_t seed);

    // Ground truth position + Gaussian noise on each axis.
    core::Vector2D getMeasurement();

    // Phase 5: measurements are unavailable inside [start_step, end_step).
    void setLossWindow(int start_step, int end_step);
    bool isAvailable(int step) const;

private:
    const simulation::Target& target_;
    NoiseModel noise_;
    int loss_start_{-1};
    int loss_end_{-1};
};

}  // namespace sensors
