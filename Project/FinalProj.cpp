// Written by Alistair Clark
// Final Project
// This program generates distance tables for projectile motion
// It also finds angle/velocity pairs that hit 30m

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

// Function prototype
void get_distance(double angle, double velocity, double &distance, double &time, double &max_height);

int main() {

// constants
    const double g = 9.81;

// variables
    double distance, time, max_height;

//  PART 1: 10x10 TABLE
    ofstream table10("table10.txt");

    table10 << fixed << setprecision(2);

// header row (velocities)
    table10 << setw(8) << "Angle";
    for (int j = 0; j < 10; j++) {
        double velocity = j * (50.0 / 9.0);
        table10 << setw(10) << velocity;
    }
    table10 << endl;

// table values
    for (int i = 0; i < 10; i++) {
        double angle = 5 + i * (80.0 / 9.0);
        table10 << setw(8) << angle;

        for (int j = 0; j < 10; j++) {
            double velocity = j * (50.0 / 9.0);

            get_distance(angle, velocity, distance, time, max_height);

            table10 << setw(10) << distance;
        }
        table10 << endl;
    }

    table10.close();


//  PART 2: 100x100 SEARCH
    ofstream matches("matches.txt");

    matches << fixed << setprecision(2);

    for (int i = 0; i < 100; i++) {
        double angle = 5 + i * (80.0 / 99.0);

        for (int j = 0; j < 100; j++) {
            double velocity = j * (50.0 / 99.0);

            get_distance(angle, velocity, distance, time, max_height);

            if (fabs(distance - 30.0) <= 0.1) {
                matches << angle << "," << velocity << endl;
            }
        }
    }

    matches.close();

    cout << "Program complete. Files generated." << endl;

    return 0;
}


// FUNCTION 
void get_distance(double angle, double velocity, double &distance, double &time, double &max_height) {

    const double g = 9.81;
    const double PI = 3.1415;

// convert to radians
    double angle_rad = angle * PI / 180.0;

// flight time
    time = (2 * velocity * sin(angle_rad)) / g;

// max height
    max_height = (pow(velocity, 2) * pow(sin(angle_rad), 2)) / (2 * g);

// horizontal distance
    distance = (pow(velocity, 2) * sin(2 * angle_rad)) / g;
}