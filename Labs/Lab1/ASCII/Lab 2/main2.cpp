/*
    Loops Lab
    Updated By: Alistair Clark
    //FIXED1
    CSCI 111
    Date: 3/3/2026
    //FIXED2

    Program prints geometric shapes of given height with * using loops
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printTriangle(int height) {
    //Function takes height as an argument to print the triangle
    //of that height with *
    int row = 1;
    // row
    while (row <= height) {
        // column
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row += 1;
        cout << endl;
    }
}


//FIXED3
void printFlippedTriangle(int height) {
    for (int row = height; row >= 1; row--) {
        for (int col = 1; col <= row; col++) {
            cout << "* ";
        }
        cout << endl;
    }
}


/*  
FIXED4
Design and implement a function that takes an integer as height and
prints square of the given height with *.
Square of height 5, e.g., would look like the following.

*  *  *  *  *  
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   
*/

void printSquare(int height) {
    for (int row = 1; row <= height; row++) {
        for (int col = 1; col <= height; col++) {
            cout << "* ";
        }
        cout << endl;
    }
}


// function clears the screen system call
// NOTE: system call is not a security best pracice!
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main(int argc, char* argv[]) {

    char choice;

    do {
        clearScreen();   // FIXED6

        int height;
        cout << "Program prints geometric shapes of given height with *\n";
        cout << "Please enter the height of the shape: ";
        cin >> height;

        // call printTriangle function passing user entered height
        printTriangle(height);

        cout << endl;

        // FIXED7
        // Call printFlippedTriangle passing proper argument
        // Manually test the function
        printFlippedTriangle(height);

        cout << endl;

        // FIXED8
        // Call the function defined in FIXED4 passing proper argument
        // Manually test the function
        printSquare(height);

        // FIXED9
        // prompt user to enter y/Y to continue anything else to quit
        cout << "\nEnter y/Y to continue anything else to quit: ";
        cin >> choice;

        // FIXED10
        // Use conditional statements to break the loop or continue the loop

    } while (choice == 'y' || choice == 'Y');   // FIXED5

    return 0;
}