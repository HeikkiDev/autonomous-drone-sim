// Phase 1 — World simulation.
// Goal: target moves linearly, velocity constant.
// Output: data/results/phase1_state.csv [time, pos_x, pos_y, vel_x, vel_y]
//
// TODO(phase1):
//   1. Build World(constants::kDt) and Target(initial pos/vel from Constants.h).
//   2. Create DataLogger with the column names above.
//   3. Loop kDefaultSteps: world.step(); target.update(dt); log row.
//   4. Verify the plotted trajectory is a straight line.

#include "core/Constants.h"
#include "simulation/Target.h"
#include "simulation/World.h"
#include "DataLogger.h"

int main() {
    return 0;
}
