#include "MenuFunctions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Define the menu functions.
// Initializing main(): This could be made into a proper initialization function, but I am more comfortable with this implementation for now.
int MenuFunctions::initialize(string input_file, string output_file) {
    // Open our file
    ifstream input(input_file);
    if (!input) {
        cout << "Error: could not open the file." << endl;
        return 1;
    }

    // Create a map to store the grocery item frequencies
    map<string, int> freq;

    // Create a set to store the itemKey keys for each grocery item
    set<string> itemKey;

    // Read each grocery from the file and update the map and the set
    string grocery;
    while (input >> grocery) {
        freq[grocery]++;
        itemKey.insert(grocery);
    }

    // Close the file
    input.close();

    // Open frequency.dat for writing
    ofstream output(output_file);
    if (!output) {
        cout << "Error: could not open the output file." << endl;
        return 1;
    }

    // Iterate over the set and print the items and their frequencies
    for (auto iterable = itemKey.begin(); iterable != itemKey.end(); iterable++) {
        output << *iterable << " (" << freq[*iterable] << ")" << endl;
    }

    output.close();

    return 0;
}

int MenuFunctions::frequencyList(string file) {
    // Open the input file
    ifstream input(file);
    if (!input) {
        // Handle the error if the file cannot be opened
        cerr << "Error: could not open the file." << endl;
        return 1;
    }

    // Read and print each line from the file
    string line;
    while (getline(input, line)) {
        // Print the line to the standard output
        cout << line << endl;
    }

    // Close the file
    input.close();

    return 0;
}


int MenuFunctions::frequencyBySearch(string file) {
    // Open the file "input.txt" for reading
    ifstream input(file);
    if (!input) {
        cout << "Error: could not open the file." << endl;
        return 1;
    }

    // Create a map to store the grocery frequencies
    map<string, int> freq;

    // Read each grocery from the file and update the map
    string grocery;
    while (input >> grocery) {
        transform(grocery.begin(), grocery.end(), grocery.begin(), ::tolower);
        freq[grocery]++;
    }

    // Close the file
    input.close();

    // Prompt the user to input a grocery to search
    cout << "Enter an item to search: ";
    cin >> grocery;
    transform(grocery.begin(), grocery.end(), grocery.begin(), ::tolower);

    // Check if the grocery is in the map and print the frequency
    if (freq.count(grocery) > 0) {
        cout << "The item '" << grocery << "' appears " << freq[grocery] << " times in the file." << endl;
    }
    else {
        cout << "The item '" << grocery << "' does not appear in the file." << endl;
    }

    return 0;
}

int MenuFunctions::histogram(string file, string chosen_char) {
    // Open the file "input.txt" for reading
    ifstream input(file);
    if (!input) {
        cout << "Error: could not open the file." << endl;
        return 1;
    }

    // Create a map to store the grocery frequencies
    map<string, int> freq;

    // Create a set to store the itemKey items
    set<string> itemKey;

    // Read each grocery from the file and update the map and the set
    string grocery;
    while (input >> grocery) {
        freq[grocery]++;
        itemKey.insert(grocery);
    }

    // Close the file
    input.close();

    // Iterate over the set and print the items and their frequencies as asterisks
    for (auto iterable = itemKey.begin(); iterable != itemKey.end(); iterable++) {
        cout << *iterable << " ";
        for (int i = 0; i < freq[*iterable]; i++) {
            cout << chosen_char;
        }
        cout << endl;
    }

    return 0;
}

