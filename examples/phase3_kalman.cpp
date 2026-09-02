// Phase 3 — Kalman filter core.
// Goal: estimate converges; error smaller than raw measurement error.
// Output: data/results/phase3_state.csv [time, real_x, real_y, meas_x, meas_y, est_x, est_y]
//
// TODO(phase3):
//   1. Build Target, VirtualSensor, KalmanFilter; initialize the filter.
//   2. Loop: target.update(dt); kf.predict(dt); z = sensor.getMeasurement();
//      kf.update(z); est = kf.getState(); log everything.
//   3. Accumulate RMSE for measurement vs estimate and print at the end.

#include "core/Constants.h"
#include "estimation/KalmanFilter.h"
#include "sensors/VirtualSensor.h"
#include "simulation/Target.h"
#include "simulation/World.h"
#include "DataLogger.h"

int main() {
    return 0;
}
