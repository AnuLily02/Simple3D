#include <iostream>
#include <fstream>
#include "simple3d/pose3d.hpp"

int main() {
    std::cout << "=== Simple3D: Generating Poses ===" << std::endl;

    // Create some poses
    simple3d::Pose3D origin_pose;
    simple3d::Pose3D robot_pose(1.5, 2.0, 0.5, 0.0, 0.0, 1.57); // Yaw = ~90 degrees

    std::cout << "Origin Pose: " << origin_pose << std::endl;
    std::cout << "Robot Pose:  " << robot_pose << std::endl;

    // Export poses to a CSV file for visualization
    std::ofstream outfile("poses.csv");
    if (outfile.is_open()) {
        // Write CSV header
        outfile << "x,y,z,roll,pitch,yaw\n";
        
        // Write origin data
        outfile << origin_pose.position.x << "," 
                << origin_pose.position.y << "," 
                << origin_pose.position.z << "," 
                << origin_pose.orientation.roll << "," 
                << origin_pose.orientation.pitch << "," 
                << origin_pose.orientation.yaw << "\n";

        // Write robot data
        outfile << robot_pose.position.x << "," 
                << robot_pose.position.y << "," 
                << robot_pose.position.z << "," 
                << robot_pose.orientation.roll << "," 
                << robot_pose.orientation.pitch << "," 
                << robot_pose.orientation.yaw << "\n";

        outfile.close();
        std::cout << "Successfully saved pose data to 'poses.csv'!" << std::endl;
    } else {
        std::cerr << "Error: Could not open file for writing!" << std::endl;
    }

    return 0;
}