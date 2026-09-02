# autonomous-drone-sim

> **A personal learning project** — not a library or product. A 2D autonomous drone
> simulator built from first principles to learn state estimation and control.

Built in 8 incremental phases, each with its own executable, so every concept can be run
and plotted before the next is layered on.

**Currently a scaffold, deliberately** — headers declare the interfaces, `.cpp` files hold
only `TODO(phaseN)` notes. Filling them in *is* the exercise, so please don't send PRs
implementing the phases.

## Learning goals

- Understand the Kalman filter by coding `predict`/`update`, not calling a black box.
- Feel the difference between ground truth, a noisy measurement and an estimate — and why
  a controller must never secretly use the first one.
- See what happens when sensing degrades (phase 5) and why prediction beats reaction
  (phase 8).
- Practise incremental C++ structure: small classes, unit tests, reproducible runs.

Clarity beats performance and generality throughout. Eigen is the one concession to
practicality, so the focus stays on the filter rather than on matrix inversion.

## Design decisions

| Topic | Choice |
|---|---|
| Linear algebra | **Eigen** (fetched automatically if not installed) |
| Visualization | **Gnuplot** via generated scripts + CSV logs |
| Randomness | `std::mt19937` + `std::normal_distribution`, deterministically seeded |
| Executables | **One per phase** (`phase1_world` … `phase8_prediction`) |
| Configuration | Single global `src/core/Constants.h` |
| Tests | GoogleTest + CTest |

## Layout

```
src/core/         Vector2D, State, Constants.h
src/simulation/   World (time), Target (ground truth), Drone (double integrator)
src/sensors/      NoiseModel (Gaussian), VirtualSensor (noise + loss windows)
src/estimation/   KalmanFilter (Eigen-based)
src/control/      Controller (PD law), Trajectory (lead prediction)
visualization/    DataLogger (CSV), Plotter (gnuplot scripts)
phases/           phase1..phase8 entry points (one main() each)
tests/            GoogleTest suites (skipped placeholders)
data/results/     Generated CSVs and plots (gitignored)
```

## Build & run

```bash
cmake -B build && cmake --build build -j
./build/phase1_world
ctest --test-dir build --output-on-failure
gnuplot data/results/phase4_plot.gnuplot
```

Disable tests with `-DDRONE_SIM_BUILD_TESTS=OFF`.

To compare phases, overlay their CSVs in a single gnuplot `plot` command; each phase also
prints its own error metrics on exit.

## Phases

| Phase | Executable | Success criterion |
|---|---|---|
| 1 | `phase1_world` | Target moves linearly, velocity constant |
| 2 | `phase2_sensor` | Measurements dance around truth with correct noise stats |
| 3 | `phase3_kalman` | Estimate converges; error < measurement error |
| 4 | `phase4_visualization` | Plots readable and consistent with the CSV |
| 5 | `phase5_loss` | Filter predicts through the dropout, reconverges after |
| 6 | `phase6_drone` | Drone kinematics correct; accelerates toward target |
| 7 | `phase7_control` | Drone pursues using *only* the estimate, never ground truth |
| 8 | `phase8_prediction` | Drone leads the target; smoother pursuit than phase 7 |

## Workflow

Design → stub → implement → unit test → visualize → tune → document → freeze.
Later phases add to the pipeline; they don't rewrite earlier code. A phase is done only
when its plot looks right *and* I can explain why.

**Status:** scaffold complete, phase 1 not started.
