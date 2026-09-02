// Phase 4 — Visualization.
// Goal: plot the three traces (real, measured, estimated) with gnuplot.
// Output: data/results/phase4_state.csv, phase4_plot.gnuplot, phase4_plot.png
//
// TODO(phase4):
//   1. Reuse the phase 3 loop.
//   2. Build a Plotter over the CSV, add three Series (real/measured/estimated).
//   3. writeScript() then render(); warn (don't fail) if gnuplot is missing.

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
