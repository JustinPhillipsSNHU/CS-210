// MenuFunctions.h
#ifndef MENUFUNCTIONS_H
#define MENUFUNCTIONS_H
#include <string>
using namespace std;

// Declare the class MenuFunctions, which will act as a library for the menu's functions. 
class MenuFunctions {
public:
	// Initialize the read and write files, a file in for input, and a file out for output.
	int initialize(string readfile, string write_file);

	// Display the frequency of each word in the read file. Since initialize creates frequency.dat, which looks like this, this function can actually just print the document frequency.dat line by line for greater efficiency.
	int frequencyList(string readfile);

	// Search for a word in the read file and display its frequency
	int frequencyBySearch(string readfile);

	// Display a histogram of the word frequencies in the read file
	int histogram(string readfile, string displayChar);
};

#endif
