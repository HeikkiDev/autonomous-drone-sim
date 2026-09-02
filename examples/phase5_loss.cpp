// Phase 5 — Sensor loss.
// Goal: during the loss window the filter predicts only; it reconverges afterwards.
// Output: data/results/phase5_state.csv [..., sensor_available]
//
// TODO(phase5):
//   1. sensor.setLossWindow(kSensorLossStart, kSensorLossEnd).
//   2. Loop: always kf.predict(dt); call kf.update() only when sensor.isAvailable(step).
//   3. Log the availability flag and the covariance trace to show uncertainty growth.

#include "core/Constants.h"
#include "estimation/KalmanFilter.h"
#include "sensors/VirtualSensor.h"
#include "simulation/Target.h"
#include "simulation/World.h"
#include "DataLogger.h"
#include "Plotter.h"

int main() {
    return 0;
}
