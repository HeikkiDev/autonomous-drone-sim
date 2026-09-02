#pragma once

#include <cstdint>

// Universal simulation constants shared by every phase.
// Keep values here so phases stay comparable across runs.
namespace constants {

// --- Time ---
inline constexpr double kDt = 0.01;          // simulation timestep [s]
inline constexpr int kDefaultSteps = 1000;   // steps per run

// --- Target ---
inline constexpr double kTargetInitPosX = 0.0;
inline constexpr double kTargetInitPosY = 0.0;
inline constexpr double kTargetInitVelX = 1.0;
inline constexpr double kTargetInitVelY = 0.5;

// --- Sensor / noise ---
inline constexpr double kSensorNoiseStdDev = 0.5;   // [m]
inline constexpr std::uint32_t kRandomSeed = 42;    // deterministic by default

// --- Sensor loss window (phase 5) ---
inline constexpr int kSensorLossStart = 500;
inline constexpr int kSensorLossEnd = 700;

// --- Kalman filter ---
inline constexpr int kStateDim = 4;                  // [px, py, vx, vy]
inline constexpr int kMeasurementDim = 2;            // [px, py]
inline constexpr double kProcessNoiseStdDev = 0.1;   // Q scaling
inline constexpr double kInitialCovariance = 1.0;    // P0 diagonal

// --- Drone ---
inline constexpr double kDroneInitPosX = -5.0;
inline constexpr double kDroneInitPosY = -5.0;
inline constexpr double kDroneMaxAcceleration = 5.0;  // [m/s^2]
inline constexpr double kDroneMaxSpeed = 10.0;        // [m/s]

// --- Controller ---
inline constexpr double kControlGainPosition = 2.0;  // Kp
inline constexpr double kControlGainVelocity = 1.5;  // Kd

// --- Trajectory prediction (phase 8) ---
inline constexpr double kPredictionHorizon = 1.0;  // [s]

// --- Output ---
inline constexpr const char* kResultsDir = "data/results";

}  // namespace constants
