// Phase 7 — Control driven by estimation.
// Goal: drone pursues the target using ONLY the Kalman estimate.
// Output: data/results/phase7_state.csv [time, real, meas, est, drone, control]
//
// TODO(phase7):
//   1. Wire Target -> VirtualSensor -> KalmanFilter -> Controller -> Drone.
//   2. Loop: predict/update, est = kf.getState(),
//      a = controller.compute(drone.state(), est.position, est.velocity).
//   3. Ground truth may be logged for evaluation, never fed into the controller.

#include "control/Controller.h"
#include "core/Constants.h"
#include "estimation/KalmanFilter.h"
#include "sensors/VirtualSensor.h"
#include "simulation/Drone.h"
#include "simulation/Target.h"
#include "simulation/World.h"
#include "DataLogger.h"

int main() {
    return 0;
}
