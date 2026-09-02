// Phase 2 — Virtual sensor.
// Goal: noisy measurements dance around ground truth with the right distribution.
// Output: data/results/phase2_state.csv [time, real_x, real_y, meas_x, meas_y]
//
// TODO(phase2):
//   1. Build Target and VirtualSensor(target, kSensorNoiseStdDev, kRandomSeed).
//   2. Loop: target.update(dt); measurement = sensor.getMeasurement(); log both.
//   3. Sanity check the empirical mean/std of (measurement - truth).

#include "core/Constants.h"
#include "sensors/VirtualSensor.h"
#include "simulation/Target.h"
#include "simulation/World.h"
#include "DataLogger.h"

int main() {
    return 0;
}
