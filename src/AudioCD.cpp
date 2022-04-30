#include "AudioCD.h"
// <string> and <fstream> libraries included from parent class
// <vector> library included in header file
#include <iostream>		// needed for changeAttribute method
#include <sstream>      // Needed to convert numeric types into string

// Implementation for AudioCD class

// Constructor for AudioCD class (also calls constructor for parent DigitalMedia class)
AudioCD::AudioCD()
	: DigitalMedia(), musician(""), runtime(0) {
	setCategory("AudioCD");
}

AudioCD::AudioCD(
	const std::string& title,
	double price,
	int numInStock,
	const std::string& language,
	const std::string& genre,
	const std::string& releaseDate,
	bool isElectronic,
	const std::string& musician,
	double runtime,
	const std::vector<std::string>& trackList)
	: DigitalMedia(title, price, numInStock, language, genre, releaseDate, isElectronic), musician(musician),
	runtime(runtime), trackList(trackList) {
	setCategory("AudioCD");
}

/// 
/// Accessors (Getters)
/// 
// Returns a string containing all product attributes (tracks in AudioCD are returned in comma-seperated line).
std::string AudioCD::getDescription() const {
	std::stringstream stringConv;
	std::string description, runtimeStr;

	stringConv << runtime;
	stringConv >> runtimeStr;

	description = DigitalMedia::getDescription() + '\n'
		+ "Musician: " + musician + '\n'
		+ "Runtime: " + runtimeStr + '\n'
		+ "Tracklist: ";
	for (int i = 0; i < trackList.size(); i++) {
		if (i != trackList.size() - 1)
			description += (trackList[i] + ", ");
		else
			description += trackList[i];
	}

	return description;
}

// Outputs all product attributes to an external file through the outs stream in a format readable by the program.
void AudioCD::outputToFile(std::ofstream& outs) const {
	DigitalMedia::outputToFile(outs);
	outs << musician << std::endl;
	outs << runtime << std::endl;

	for (int i = 0; i < trackList.size(); i++) {
		if (i != trackList.size() - 1)
			outs << trackList[i] << "#";
		else
			outs << trackList[i];
	}

	outs << std::endl;
}

// Prints all attributes the user can change along with the number they need to select to change them.
void AudioCD::printChangeableAttributes() const {
	DigitalMedia::printChangeableAttributes();
	std::cout << "8 - Musician" << std::endl
		<< "9 - Runtime" << std::endl
		<< "10 - Track list" << std::endl;
}

std::string AudioCD::getMusician() const {
	return musician;
}

double AudioCD::getRuntime() const {
	return runtime;
}

const std::vector<std::string>& AudioCD::getTrackList() const {
	return trackList;
}

/// 
/// Mutator methods (Setters)
///
void AudioCD::setMusician(const std::string& newMusician) {
	musician = newMusician;
}

void AudioCD::setRuntime(double newRuntime) {
	runtime = newRuntime;
}

void AudioCD::setTrackList(const std::vector<std::string>& newTrackList) {
	trackList = newTrackList;
}

 // Based on which attribute a user chose to change, this method will print the old value of that attribute and allow the user to enter
// a new one.
void AudioCD::changeAttribute(int userChoice) {
	if (userChoice) {
		if (userChoice == 1) {				// Cannot use switch when initializing a var in each case, as switch cannot skip initializations.
			std::string newTitle;
			std::cout << "Old title: " << getTitle() << std::endl;
			std::cout << "Enter new title: ";
			std::cin.ignore();					// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newTitle);
			setTitle(newTitle);
		}
		else if (userChoice == 2) {
			double newPrice;
			std::cout << "Old price: " << getPrice() << std::endl;
			std::cout << "Enter new price (numeric): ";
			std::cin >> newPrice;
			setPrice(newPrice);
		}
		else if (userChoice == 3) {
			int newNumInStock;
			std::cout << "Old number in stock: " << getNumInStock() << std::endl;
			std::cout << "Enter how many are in stock (numeric): ";
			std::cin >> newNumInStock;
			setNumInStock(newNumInStock);
		}
		else if (userChoice == 4) {
			std::string newLanguage;
			std::cout << "Old language: " << getLanguage() << std::endl;
			std::cout << "Enter new language: ";
			std::cin >> newLanguage;
			setLanguage(newLanguage);
		}
		else if (userChoice == 5) {
			std::string newReleaseDate;
			std::cout << "Old release date: " << getReleaseDate() << std::endl;
			std::cout << "Enter new release date: ";
			std::cin >> newReleaseDate;
			setReleaseDate(newReleaseDate);
		}
		else if (userChoice == 6) {
			std::string newGenre;
			std::cout << "Old genre: " << getGenre() << std::endl;
			std::cout << "Enter new genre: ";
			std::cin.ignore();					// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newGenre);
			setGenre(newGenre);
		}
		else if (userChoice == 7) {
			char newIsElectronic;
			std::cout << "Old electronic status: " << (getIsElectronic() ? "true" : "false") << std::endl;
			std::cout << "Enter if the product is electronic or not (y/n): ";
			std::cin >> newIsElectronic;
			// char input must be converted into a boolean (ternary operator is used).
			setIsElectronic((newIsElectronic == 'y' || newIsElectronic == 'Y') ? true : false);
		}
		else if (userChoice == 8) {
			std::string newMusician;
			std::cout << "Old musician: " << getMusician() << std::endl;
			std::cout << "Enter new musician: ";
			std::cin.ignore();					// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newMusician);
			setMusician(newMusician);
		}
		else if (userChoice == 9) {
			double newRuntime;
			std::cout << "Old runtime: " << getRuntime() << std::endl;
			std::cout << "Enter new runtime (in hours, numeric): ";
			std::cin >> newRuntime;
			setRuntime(newRuntime);
		}
		else if (userChoice == 10) {
			std::vector<std::string> newTrackList;

			std::string newInput;
			std::cout << "Enter new track or leave blank to stop: ";
			std::cin.ignore();						// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newInput);
			while (newInput != "") {
				newTrackList.push_back(newInput);
				std::cout << "Enter new track or leave blank to stop: ";
				std::getline(std::cin, newInput);
			}
			setTrackList(newTrackList);
		}
	}
}

// Initializes an object of this class by reading data from an external file through the ins stream.
void AudioCD::initalizeFromFile(std::ifstream& ins) {
	DigitalMedia::initalizeFromFile(ins);
	std::stringstream stringConv;
	std::string tmpLine, tmpStr;
	std::vector<std::string> tmpVec;

	std::getline(ins, musician);

	std::getline(ins, tmpLine);
	stringConv << tmpLine;
	stringConv >> runtime;

	std::getline(ins, tmpLine);
	for (int i = 0; i < tmpLine.size(); i++) {
		if (tmpLine[i] == '#') {
			tmpVec.push_back(tmpStr);
			tmpStr = "";
		}
		else {
			tmpStr += tmpLine[i];

		}
	}
	tmpVec.push_back(tmpStr); // last word

	trackList = tmpVec;
}