// ChadaTech.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Justin Phillips
// 9/8/23 
// SNHU Programming Languages CS210
// GOAL: Create a simulated clock which the user can input a starting time and add updates to manually.

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Generic function to add an extra 0 to a digit
// For whatever reason fixed and precion() weren't yeilding expected results
// So I did this
string two_digit(int number) {
    string string_num = to_string(number);
    if (string_num.length() == 1) {
        string_num = "0" + string_num;
    }
    return string_num;
}

// Generic function to check for a character in a string. Useful for parsing delimiters.
bool containsChar(string str, char c) {
    for (char ch : str) {
        if (ch == c) {
            return true;
        }
    }
    return false;
}

// Generic function for splitting a string at a given delimiter. Takes advantage of stream input (like in Java). 
vector<int> splitString(string str, char delimiter) { 
    vector<int> result; // This is the resulting int string for the time vector later.
    stringstream ss(str); // An input string stream.
    string token; // This is the segment of the string between each delimiter.
    while (getline(ss, token, delimiter)) {
        result.push_back(std::stoi(token));
    }
    return result; 
}

// This is our init function. It gets an initial time.
vector<int> get_time() {
    vector<int> timeVector(3); // Declare the vector.
    string time;
    vector<char> delimiters(4); // Declare the list of delimiters.
    bool found_delimiter; // Later on, this variable will determine if a for loop has a natural end, as C++ does not seem to have a for-else/while-else component.
    delimiters = { ';', '.', ',', ':' };
    int hour;
    int minute;
    int second;
        SET_TIME : // A label for a go-to for the start of time getting after variable declaration. 
    cout << "Please enter the time. Minutes, then hours, then seconds.\nApproved delimiters: Semicolon, colon, comma, period.\n";
    cin >> time;
    found_delimiter = false; // Ensure the natural for end is false.
    for (char d : delimiters) {
        if (containsChar(time, d)) { // Check for a specific delimiter. It's assumed the user is inputting a consistent delimiter.
            timeVector = splitString(time, d); // Break on that delimiter.
            found_delimiter = true;
            break; // If a delimiter is found, it breaks the for loop. This is for efficiency.
        }
    }
    if (!found_delimiter) { // If the for loop ends naturally, i.e. no delimiter is found
        goto SET_TIME; // Restart time getting.
    }
    hour = timeVector.at(0);
    minute = timeVector.at(1);
    second = timeVector.at(2);
    if (!(hour < 24 && minute < 60 && second < 60)) { // Check if the inputs are valid.
        goto SET_TIME; // If not, go to the start of getting time.
    }
    else { // Otherwise, if the input is valid
        return timeVector; // Produce the time vector.
    }
}

// Function to print the time whenever the user wants.
void print_time(vector<int> time_vector_in, bool use_mil_time) {
    int hour = time_vector_in.at(0);
    int minute = time_vector_in.at(1);
    int second = time_vector_in.at(2);
    if (use_mil_time) { // Could add checks to print correct variations of hour(s), minute(s), second(s) with pluralization. Will save for later.
        //cout << "Time is " << hour << " hour(s), " << minute << " minute(s), " << " and " << second << " second(s).";
        cout << "Time is " << two_digit(hour) << ":" << two_digit(minute) << ":" << two_digit(second) << " (24-hour clock).";
    }
    else {
        if (hour > 12) {
            cout << "Time is " << two_digit(hour - 12) << ":" << two_digit(minute) << ":" << two_digit(second) << " PM.";
        }
        else
        {
            cout << "Time is " << two_digit(hour) << ":" << two_digit(minute) << ":" << two_digit(second) << " AM.";
        }
    }
    cout << "\n";
    return;
}

// The menu function - Meat and potatos. 
vector<int> time_menu(vector<int> time_vector_in) {
    // Cache the starting values when the time does get modified.
    int orig_hour = time_vector_in.at(0);
    int orig_minute = time_vector_in.at(1);
    int orig_second = time_vector_in.at(2);
    int choice;
    do {
        // Actually print the menu.
        cout << "Choose an option:\n";
        cout << "1. Modify hour\n";
        cout << "2. Modify minute\n";
        cout << "3. Modify second\n";
        cout << "4. Print 12-hour time\n";
        cout << "5. Print 24-hour time\n";
        cout << "6. Exit\n";
        cin >> choice;
        switch (choice) { // Switches are the best. Determine what to do based on the selection of the user with respect to the menu printed above.
        case 1:
        SET_HOUR:
            cout << "Old hour: " << orig_hour << "\nEnter new hour: ";
            cin >> time_vector_in.at(0);
            if (!(time_vector_in.at(0) < 24 && time_vector_in.at(1) < 60 && time_vector_in.at(2) < 60)) {
                cout << "\nInvalid input.\n";
                goto SET_HOUR;
            }
            break;
        case 2:
        SET_MIN:
            cout << "Old minute: " << orig_minute << "\nEnter new minute: ";
            cin >> time_vector_in.at(1);
            if (!(time_vector_in.at(0) < 24 && time_vector_in.at(1) < 60 && time_vector_in.at(2) < 60)) {
                cout << "\nInvalid input.\n";
                goto SET_MIN;
            }
            break;
        case 3:
            SET_SEC:
            cout << "Old second: " << orig_second << "\nEnter new second: ";
            cin >> time_vector_in.at(2);
            if (!(time_vector_in.at(0) < 24 && time_vector_in.at(1) < 60 && time_vector_in.at(2) < 60)) {
                cout << "\nInvalid input.\n";
                goto SET_SEC;
            }
            break;
        case 4:
            print_time(time_vector_in, false);
            break;
        case 5:
            print_time(time_vector_in, true);
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
    return time_vector_in;
}

// Main just gets an initial time and lets the user use the menu to modify it. 
int main()
{
    vector<int> user_time = get_time();
    time_menu(user_time);
}

