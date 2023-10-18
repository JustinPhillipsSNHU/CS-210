#include <iostream>
#include <string>
#include "menuFunctions.h"
using namespace std;

// Declare globals
string original_input = "GroceryList.txt"; // The input file, which can be changed to a new input file if needed.
string histogram_char_string = "*"; // A cosmetic choice to change the character used for the histogram. Takes a string.
string frequency_output_file = "frequency.dat"; // The name of the output file. 
MenuFunctions menu; // Declare a MenuFunctions object to use the library. 


int main()
{
    // User input will be stored in an int 'choice'.
    int choice;
    menu.initialize(original_input, frequency_output_file);

    // Switch statements are amazing. Using a switch and a while-true infinite loop, run the menu until the user decides to quit the program (input 4)
    while (true) { // Runs until a return or break on this loop is called. 
        // Print the menu.
        cout << "Please choose one of the following options:" << endl;
        cout << "1. Query the grocery list for the frequency of an item" << endl;
        cout << "2. Display the grocery list with frequencies of each item" << endl;
        cout << "3. Display a histogram representing item frequency" << endl;
        cout << "4. Exit the program" << endl;
        cout << "Please make a numerical selection: ";
        cin.clear();
        choice = 0;
        cin >> choice;
        switch (choice) {
        case 1:
            // Search for the frequency of a value by a search term
            menu.frequencyBySearch(original_input);
            break;
        case 2:
            // Print a full frequency list
            menu.frequencyList(frequency_output_file);
            break;
        case 3:
            // Print a histogram of the frequencies of the words.
            menu.histogram(original_input, histogram_char_string);
            break;
        case 4:
            // Exit the program. Return 0.
            return 0;
            break;
        default:
            // Handle any input that isn't valid.
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        system("pause");
    } 
}
