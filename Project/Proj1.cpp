// Written by Alistair Clark
// This program asks a user first to input feet or meters
// This program then ask for a launch angle
// This program then asks for a velocity
// This prgram then asks how far a target is away from the launcher
// This program then tells the user the flight time, max height, horizontal distance, and max possible range all in meters and feet
// Finally the program will tell the user if the terget is hit

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;

int main() {
// Define varibles and conversions
    const double g= 9.81;
    const double ft_meter = 0.3048;
    const double meter_ft = 3.28;
    const double PI = 3.1415;

// Defines varibles for user to choose (angle, velocity, and distance)
    string unitChoice; 
    double alpha;           
    double muzzle_velocity; 
    double target_dist; 

 // asks for user input on units, angle, velocity, and distance
    cout << "Enter units (meters or feet): ";
    cin >> unitChoice;
    cout << "Enter launch angle (degrees between 0 and 90): ";
    cin >> alpha;
    cout << "Enter muzzle velocity: ";
    cin >> muzzle_velocity;
    cout << "Enter target distance: ";
    cin >> target_dist;

// Unit conversions
    if (unitChoice == "feet") {
    muzzle_velocity = muzzle_velocity * ft_meter;
    target_dist = target_dist * ft_meter;
    }

// more unit conversions and variable defining: degree to radians
    double alpha_rad = alpha * PI / 180.0;

// flight time
    double flight_time = (2 * muzzle_velocity * sin(alpha_rad)) / g;

// max height
    double max_height = (pow(muzzle_velocity, 2) * pow(sin(alpha_rad), 2)) / (2 * g);

// horizontal distance or range
    double x_dist = (pow(muzzle_velocity, 2) * sin(2 * alpha_rad)) / g;

// meters back to feet
    double max_height_feet = max_height * meter_ft;
    double x_dist_ft = x_dist * meter_ft;

// respond to user with results
    cout << fixed << setprecision(2);
    cout << endl << "Flight Time: " << flight_time << " seconds" << endl;

    cout << endl << "Max Height:" << endl;
    cout << "  " << max_height << " meters" << endl;
    cout << "  " << max_height_feet << " feet" << endl;

    cout << fixed << setprecision(1);
    cout << endl << "Horizontal Distance:" << endl;
    cout << "  " << x_dist << " meters" << endl;
    cout << "  " << x_dist_ft << " feet" << endl;

// Maximum possible range (at 45 degrees)
    double max_range = (pow(muzzle_velocity, 2)) / g;

    cout << endl << "Maximum Possible Range: " << max_range << " meters" << endl;

    if (target_dist <= max_range) {
        cout << "The target IS within range." << endl;
    } else {
        cout << "The target is NOT within range." << endl;
    }

    return 0;
}