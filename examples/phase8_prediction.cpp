// Phase 8 — Trajectory prediction.
// Goal: drone leads the target; pursuit smoother than phase 7.
// Output: data/results/phase8_state.csv [..., pred_x, pred_y]
//
// TODO(phase8):
//   1. Same pipeline as phase 7 plus Trajectory(kPredictionHorizon).
//   2. predicted = trajectory.predictState(est);
//      a = controller.compute(drone.state(), predicted.position, predicted.velocity).
//   3. Sweep the horizon and compare tracking error against phase 7.

#include "control/Controller.h"
#include "control/Trajectory.h"
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
