// Phase 6 — Virtual drone (no estimation yet).
// Goal: correct kinematics; drone accelerates toward the true target.
// Output: data/results/phase6_state.csv [time, target_x, target_y, drone_x, drone_y]
//
// TODO(phase6):
//   1. Build Target and Drone; use ground-truth target state on purpose here.
//   2. Loop: dummy control -> (target.pos - drone.pos).normalized() * gain;
//      drone.setAcceleration(...); drone.update(dt); log.
//   3. Expect overshoot/oscillation — that motivates the PD controller.

#include "core/Constants.h"
#include "simulation/Drone.h"
#include "simulation/Target.h"
#include "simulation/World.h"
#include "DataLogger.h"

int main() {
    return 0;
}
