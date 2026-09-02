#pragma once

#include <Eigen/Dense>

#include "core/State.h"
#include "core/Vector2D.h"

namespace estimation {

// Linear Kalman filter for a constant-velocity target.
//   state x = [px, py, vx, vy]^T
//   measurement z = [px, py]^T
// Matrix sizes come from constants::kStateDim / kMeasurementDim.
class KalmanFilter {
public:
    using StateVector = Eigen::Vector4d;
    using StateMatrix = Eigen::Matrix4d;
    using MeasurementVector = Eigen::Vector2d;
    using MeasurementMatrix = Eigen::Matrix2d;
    using ObservationMatrix = Eigen::Matrix<double, 2, 4>;
    using GainMatrix = Eigen::Matrix<double, 4, 2>;

    KalmanFilter();

    // x0 and P0; call before the first predict().
    void initialize(const core::State& initial_state, double initial_covariance);

    // x = F x ; P = F P F^T + Q   (F depends on dt)
    void predict(double dt);

    // y = z - H x ; S = H P H^T + R ; K = P H^T S^-1
    // x = x + K y ; P = (I - K H) P
    void update(const MeasurementVector& measurement);
    void update(const core::Vector2D& measurement);

    core::State getState() const;
    const StateVector& stateVector() const;
    const StateMatrix& covariance() const;

    void setProcessNoise(double std_dev);      // builds Q
    void setMeasurementNoise(double std_dev);  // builds R

private:
    // Rebuilds F for the given dt (constant-velocity model).
    void buildTransitionMatrix(double dt);

    StateVector x_{StateVector::Zero()};
    StateMatrix P_{StateMatrix::Identity()};
    StateMatrix F_{StateMatrix::Identity()};
    StateMatrix Q_{StateMatrix::Zero()};
    ObservationMatrix H_{ObservationMatrix::Zero()};
    MeasurementMatrix R_{MeasurementMatrix::Zero()};
    bool initialized_{false};
};

}  // namespace estimation
