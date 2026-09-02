#pragma once

#include <cstdint>
#include <random>

namespace sensors {

// Deterministic Gaussian noise source (seeded for reproducible runs).
class NoiseModel {
public:
    explicit NoiseModel(double std_dev, std::uint32_t seed);

    // Draws one sample from N(0, std_dev^2).
    double sample();

    double stdDev() const;
    void reset(std::uint32_t seed);

private:
    double std_dev_{0.0};
    std::mt19937 generator_;
    std::normal_distribution<double> distribution_;
};

}  // namespace sensors
