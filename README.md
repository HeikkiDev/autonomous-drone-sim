# autonomous-drone-sim

> **A personal learning project.** This is not a library, product, or anything you should
> depend on. It exists so I can learn state estimation and control by building a 2D
> autonomous drone simulator from first principles — writing the Kalman filter, sensor
> model and control law myself rather than calling into an existing robotics stack.

2D autonomous drone simulator built in 8 incremental phases, each with its own executable,
so every concept can be run and plotted in isolation before the next one is layered on.

**The repository is currently a scaffold, and deliberately so** — headers declare the
interfaces, `.cpp` files contain only `TODO(phaseN)` notes describing what to implement.
No algorithm code is written yet: filling it in *is* the exercise. Please don't send PRs
that implement the phases; that would defeat the purpose.

## Learning goals

- Understand the Kalman filter by deriving and coding `predict`/`update` rather than
  treating it as a black box.
- Feel the difference between ground truth, a noisy measurement and an estimate — and why
  a controller must never secretly use the first one.
- See what happens when sensing degrades (phase 5) and why prediction beats reaction
  (phase 8).
- Practise incremental C++ project structure: small classes, unit tests, reproducible runs.

Design choices favour clarity over performance or generality throughout. Where a decision
was between "practical" and "instructive", instructive usually won — except for the
linear algebra, where Eigen is used so the focus stays on the filter rather than on
reimplementing matrix inversion.

## Design decisions

| Topic | Choice |
|---|---|
| Linear algebra | **Eigen** (`Eigen3::Eigen`, fetched automatically if not installed) |
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
src/estimation/   KalmanFilter (Eigen-based; no hand-rolled matrix class needed)
src/control/      Controller (PD law), Trajectory (lead prediction)
visualization/    DataLogger (CSV), Plotter (gnuplot scripts)
examples/         phase1..phase8 entry points
tests/            GoogleTest suites (currently skipped placeholders)
data/results/     Generated CSVs and plots (gitignored)
scripts/          Helper analysis scripts
```

## Build & run

```bash
cmake -B build && cmake --build build -j
./build/phase1_world
ctest --test-dir build --output-on-failure
gnuplot data/results/phase4_plot.gnuplot
```

Disable tests with `cmake -B build -DDRONE_SIM_BUILD_TESTS=OFF`.

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

## Workflow per phase

Design → stub → implement → unit test → visualize → tune → document → freeze.
Later phases add to the pipeline; they should not rewrite earlier code.

Each phase is only "done" when its plot looks right *and* I can explain why. Tuning
constants until something looks plausible without understanding the mechanism counts as
not done.

## Status

Scaffold complete; phase 1 not started. Tests exist as named placeholders that skip until
the corresponding phase is implemented.
