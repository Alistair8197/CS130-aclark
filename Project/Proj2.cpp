// This Program is written by Alistair Clark
// This program makes a list of numbers evenly spaced between the start adn end values that a user provides
// Date: 3/12/26


#include <iostream>
#include <iomanip> 

using namespace std;

// Function that fills an array with linearly spaced values
// Inputs: start value, end value, number of elements, array to fill
void linspace_cpp(double start, double end, int num_elements, double lin_vals[]) {
    // If only one element, just set it to start
    if (num_elements == 1) {
        lin_vals[0] = start;
        return;
    }

    // Calculate the step between elements
    double step = (end - start) / (num_elements - 1);

    // Fills the array
    for (int i = 0; i < num_elements; ++i) {
        lin_vals[i] = start + i * step;
    }

    // makes sure the last element is exactly the end value
    lin_vals[num_elements - 1] = end;
}

int main() {
    double start, end;
    int num_elements;

    // Ask the user for input
    cout << "Enter start value: ";
    cin >> start;
    cout << "Enter end value: ";
    cin >> end;
    cout << "Enter number of elements: ";
    cin >> num_elements;

    // Check for valid number of elements
    if (num_elements <= 0) {
        cout << "Number of elements must be positive." << endl;
        return 1;
    }

    // Create the array to hold the values
    double lin_vals[num_elements];

    // Call the function to fill the array
    linspace_cpp(start, end, num_elements, lin_vals);

    // Print the array values 
    cout << fixed << setprecision(5);
    for (int i = 0; i < num_elements; ++i) {
        cout << lin_vals[i];
        if (i != num_elements - 1) {
            cout << ", "; 
        }
    }
    cout << endl;

    return 0;
}