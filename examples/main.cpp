#include <iostream>
#include "simple3d/pose3d.hpp"

int main() {
    std::cout << "=== Welcome to Simple3D Test Suite ===" << std::endl;

    // Test 1: Default constructor (origin)
    simple3d::Pose3D origin_pose;
    std::cout << "Origin Pose: " << origin_pose << std::endl;

    // Test 2: Custom parameterized constructor
    simple3d::Pose3D robot_pose(1.5, 2.0, 0.5, 0.0, 0.0, 1.57);
    std::cout << "Robot Pose:  " << robot_pose << std::endl;

    std::cout << "=======================================" << std::endl;
    return 0;
}