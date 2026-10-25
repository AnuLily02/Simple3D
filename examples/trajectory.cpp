#include <iostream>
#include <fstream>
#include <cmath>
#include "simple3d/pose3d.hpp"

int main() {
    std::cout << "=== Simple3D: Generating Robot Trajectory ===" << std::endl;

    // Open a new CSV file for the movement path
    std::ofstream outfile("trajectory_poses.csv");
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open trajectory_poses.csv for writing!" << std::endl;
        return 1;
    }

    // Write CSV header
    outfile << "step,x,y,z,roll,pitch,yaw\n";

    // Simulate movement across 25 steps (a curved path)
    int total_steps = 25;
    for (int i = 0; i < total_steps; ++i) {
        double t = static_cast<double>(i) * 0.2; // Time/distance multiplier
        
        // Calculate changing coordinates over time (moving forward and curving)
        double x = t;
        double y = std::sin(t);       // Gentle weaving motion
        double z = 0.1 * t;         // Rising slightly uphill
        double yaw = std::cos(t);     // Turning heading dynamically

        simple3d::Pose3D step_pose(x, y, z, 0.0, 0.0, yaw);

        // Write each step to the file
        outfile << i << "," 
                << step_pose.position.x << "," 
                << step_pose.position.y << "," 
                << step_pose.position.z << "," 
                << step_pose.orientation.roll << "," 
                << step_pose.orientation.pitch << "," 
                << step_pose.orientation.yaw << "\n";
    }

    outfile.close();
    std::cout << "Successfully saved trajectory data to 'trajectory_poses.csv'!" << std::endl;
    return 0;
}