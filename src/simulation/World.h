#pragma once

namespace simulation {

// Owns simulation time and the fixed timestep.
class World {
public:
    explicit World(double dt);

    // Advances simulation time by one timestep.
    void step();

    double time() const;
    double dt() const;
    int stepCount() const;
    void reset();

private:
    double dt_{0.0};
    double time_{0.0};
    int step_count_{0};
};

}  // namespace simulation
