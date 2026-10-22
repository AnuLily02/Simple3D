#ifndef SIMPLE_3D_POSE3D_HPP
#define SIMPLE_3D_POSE3D_HPP

#include <iostream>
#include <cmath>

namespace simple3d {

/// @brief Represents a 3D position vector (x, y, z).
struct Vector3 {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

/// @brief Represents orientation using Euler angles in radians (Roll, Pitch, Yaw).
struct EulerAngles {
    double roll = 0.0;
    double pitch = 0.0;
    double yaw = 0.0;
};

/// @brief Represents a full 3D rigid-body pose (Position + Orientation).
struct Pose3D {
    Vector3 position;
    EulerAngles orientation;

    // 1. Default Constructor (Origin with zero rotation)
    Pose3D() = default;

    // 2. Parameterized Constructor using primitive values
    Pose3D(double x, double y, double z, double roll, double pitch, double yaw)
        : position{x, y, z}, orientation{roll, pitch, yaw} {}

    // 3. Parameterized Constructor using Vector3 and EulerAngles objects
    Pose3D(const Vector3& pos, const EulerAngles& orient)
        : position(pos), orientation(orient) {}

    // Overload the << operator to easily print the pose using std::cout
    friend std::ostream& operator<<(std::ostream& os, const Pose3D& pose) {
        os << "Pose3D {"
           << "Position: (" << pose.position.x << ", " << pose.position.y << ", " << pose.position.z << "), "
           << "Orientation [RPY]: (" << pose.orientation.roll << ", " << pose.orientation.pitch << ", " << pose.orientation.yaw << ")"
           << "}";
        return os;
    }
};

} // namespace simple3d

#endif // SIMPLE_3D_POSE3D_HPP