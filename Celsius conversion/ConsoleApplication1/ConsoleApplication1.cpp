// 
// fahrenheitToCelsius.cpp // Broke build tools, had to revert to ConsoleApplication1. // Had to change to a different version of build tools because of this breaking. Should work now, but a new error C4244 data loss warning from double to int on line 18 is popping up, which did not occur before.
// Justin Phillips
// CS210
// Prof Adamo
// 9/28/23
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void fToC(int &temp) { // Generic function to change Fahrenheight to Celsius
    temp = ((double)temp - 32.0) * (0.5556); // "&" allows modifying the exact value of the input variable in memory location
}

int main()
{
    ifstream inFS; // Declare infilestream infilestream
    ofstream outFS; // Declare outfilestream outfilestream
    string cityName; // Declare string City Name
    int cityTemp; // Declare int City Temp
    vector<string> citiesVector;  // Declare a vector to log cities
    vector<int> tempsVector; // Declare a vector to log temps

    // Open the file FahrenheitTemperature.txt and verify it is open.
    cout << "Opening file: FahrenheitTemperature.txt" << endl;
    inFS.open("FahrenheitTemperature.txt");
    if (!inFS.is_open()) {
        cout << "Error: Unable to open the file!" << endl;
        return -1;
    }

    // Read the file
    cout << "Reading temperatures from FahrenheitTemperature.txt" << endl;
    inFS >> cityName; // Take an alternating name and temp
    inFS >> cityTemp;
    while (!inFS.fail()) { // While there is still a valid stream
        citiesVector.push_back(cityName); // Add the current iteration of the input to the end of the corresponding vector 
        tempsVector.push_back(cityTemp); // while maintaining the alternating city > temp pattern

        inFS >> cityName; // Restart the cycle
        inFS >> cityTemp; // and continue taking corresponding inputs
    }

    // For each city and temperature print the pair out
    for (int i = 0; i < (citiesVector.size() + tempsVector.size())/2; i++) {
        cout << citiesVector.at(i) << " " << tempsVector.at(i) << endl;
    }

    // Check if file ended normally after reading
    if (!inFS.eof()) {
        cout << "Error: Abnormality in reading end of file, likely an issue with FahrenheightTemperature.txt's input." << endl;
    }

    cout << "Opening file: CelsiusTemperature.txt" << endl;
    outFS.open("CelsiusTemperature.txt");

    // checks if file is already opened
    if (!outFS.is_open()) {
        cout << "Error: Could not open CelsiusTemperature.txt. Possibly a permissions issue?" << endl;
        return -1;
    }

    cout << "\nWriting out to CelsiusTemperature.txt:" << endl;

    for (int i = 0; i < (citiesVector.size() + tempsVector.size()) / 2; i++) {
        fToC(tempsVector.at(i));
        outFS << citiesVector.at(i) << " " << tempsVector.at(i) << endl;
        cout << citiesVector.at(i) << " " << tempsVector.at(i) << endl;
    }

    cout << "Closing CelsiusTemperature.txt";
    outFS.close();
}
