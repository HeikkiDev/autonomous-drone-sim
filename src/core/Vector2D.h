#pragma once

#include <iosfwd>

namespace core {

// Minimal 2D vector used for positions, velocities and accelerations.
class Vector2D {
public:
    double x{0.0};
    double y{0.0};

    Vector2D() = default;
    Vector2D(double x, double y);

    Vector2D operator+(const Vector2D& rhs) const;
    Vector2D operator-(const Vector2D& rhs) const;
    Vector2D operator*(double scalar) const;
    Vector2D operator/(double scalar) const;

    Vector2D& operator+=(const Vector2D& rhs);
    Vector2D& operator-=(const Vector2D& rhs);
    Vector2D& operator*=(double scalar);

    bool operator==(const Vector2D& rhs) const;

    double norm() const;
    double squaredNorm() const;
    double dot(const Vector2D& rhs) const;
    Vector2D normalized() const;  // returns zero vector if norm is ~0
    Vector2D clamped(double max_norm) const;
};

Vector2D operator*(double scalar, const Vector2D& v);
std::ostream& operator<<(std::ostream& os, const Vector2D& v);

}  // namespace core
