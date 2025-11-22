/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class: 	CSC 242
** Assignment: 	Final Project Problem 1
** File: 	source.cpp
** Description: Created a Program that checks to see if a word is inside of a dictionary file,
* displays error code if not found, and displays an error message.
**
** Author: 	Luis Larios Eddi Romero
** Date: 	11/21/2025
** -------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <fstream>


using namespace std;


int main() {
	ifstream dict_file("C:\\Users\\llari\\Downloads\\words (1)");
	ifstream input_file("C:\\Users\\llari\\Downloads\\input");
	vector<string> words;   // created vector words

	if (!dict_file) {
		cout << "ERROR: Could not open dictionary file.\n";
	}
	if (!input_file) {
		cout << "ERROR: Could not open input file.\n";
	}

	if (!dict_file || !input_file) {
		return -1;
	}
	string word;
	while (dict_file >> word) {
		words.push_back(word);   // while loop adding all words from the dictionary file to vector
	}

	vector<string> input;
	string checker;
	while (input_file >> checker) {
		input.push_back(checker);  // while loop adding all input files to vector
	}


	// Load input words
	while (input_file >> word) {
		input.push_back(word);
	}

	// Check each word from input
	for (string& input_Word : input) {
		bool found = false;

		// Search dictionary
		for (string& Dict_word : words) {
			if (input_Word == Dict_word) {
				found = true;
				break;
			}
		}
		if (!found) {
			cout << input_Word << endl;
		}
	}
			return 0;
		}
	