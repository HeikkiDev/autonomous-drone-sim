#include "estimation/KalmanFilter.h"

namespace estimation {

// TODO(phase3): constructor -> set H_ = [[1,0,0,0],[0,1,0,0]], default Q_ and R_
//               from constants::kProcessNoiseStdDev / kSensorNoiseStdDev.
// TODO(phase3): initialize() -> x_ from state, P_ = initial_covariance * I.
// TODO(phase3): buildTransitionMatrix(dt) -> F = [[1,0,dt,0],[0,1,0,dt],[0,0,1,0],[0,0,0,1]].
// TODO(phase3): predict(dt) -> x_ = F x_ ; P_ = F P_ F^T + Q_.
// TODO(phase3): update(z) -> innovation y, S, gain K, state and covariance update.
//               Prefer the Joseph form for P if numerical stability becomes an issue.
// TODO(phase3): getState() -> core::State::fromVector(x_).
// TODO(phase3): setProcessNoise / setMeasurementNoise -> rebuild Q_ and R_.
//               Q for constant velocity can use the discrete white-noise acceleration model.

}  // namespace estimation
