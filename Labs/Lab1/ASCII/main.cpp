/*
    StdIO Lab
    ASCII Art - using literals and variables
    
    Updated By: Alistair Clark //Fixed
    Date: 02/03/2026 //Fixed
    
    This program produces an ASCII art on the console.

    Algorithm steps: 
    1. Use variables to store data/values
    2. Write a series of cout statements to print the data/values
*/

#include <iostream> //library for input and output
#include <string> //library for string data
 
using namespace std; //resolve cout, cin, and endl names
 
//main entry point of the program
int main()
{
    //FIXED3: declare a variable to store name
    string alistair; 

    //FIXED4: prompt user to enter their name and store the value into name variable using getline function
    cout << "Please enter your name: ";
    cin >> alistair;

    cout << "Nice to meet you " << alistair << "!" << endl;

    //FIXED5: greet the name using the variable as the following output
    //must output: Nice meeting you, <name>!


    cout << "Hope you like my Tom & Jerry ASCII art...\n\n";

    string line1 = "  |\\_/|   **********************    (\\_/)\n";
    cout << line1;

    string line2 = " / @ @ \\        * ASCII Lab *      (='.'=) \n";
    cout << line2;
//FIXED6: use variable to print the second line line of the graphic
    string line3 = "( > 0 < )         *" +alistair+ "*     ( \" )_(\" )";
    cout << line3 << endl;
 //FIXED7: print the third line of the graphics
    string line4 = "  >>x<<        *<Spring 2026>* ";
    cout << line4 << endl;
//FIXED8: use variable to print the fourth line
    string line5 = "  / O \\          *CSCI 130*  \n";
    cout << line5 << endl;
 //FIXED9: use variable to print the fifth line
    string line6 = "        ***************************** \n";
    cout << line6 << endl;

    
   
    
   
    //Note: You can add more lines or print more ASCII arts of your choice if you'd like...

    cout << "\nGood bye... hit enter to exit the program: " << '\n';
    cin.get();
    //FIXED10: make the console wait for user input

    return 0; //exit program by returning 0 status to the system
}