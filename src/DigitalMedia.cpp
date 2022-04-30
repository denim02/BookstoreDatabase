#include "DigitalMedia.h"
// <string> and <fstream> libraries included from parent class
#include <iostream>

// Implementation for DigitalMedia class

// Constructor for abstract DigitalMedia class
DigitalMedia::DigitalMedia()
	: Product(), genre(""), releaseDate(""), isElectronic(false) {
	setFormat("Digital");
}

DigitalMedia::DigitalMedia(
	const std::string& title,
	double price,
	int numInStock,
	const std::string& language,
	const std::string& genre,
	const std::string& releaseDate,
	bool isElectronic)
	: Product(title, price, numInStock, language), genre(genre), releaseDate(releaseDate), isElectronic(isElectronic) {
	setFormat("Digital");
}

/// 
/// Accessors (Getters)
/// 
// Returns a string containing all product attributes.
std::string DigitalMedia::getDescription() const {
	return Product::getDescription() + '\n'
		+ "Release Date: " + releaseDate + '\n'
		+ "Genre: " + genre + '\n'
		+ "Electronic: " + ((isElectronic) ? "true" : "false");
}

// Outputs all product attributes to an external file through the outs stream in a format readable by the program.
void DigitalMedia::outputToFile(std::ofstream& outs) const {
	Product::outputToFile(outs);
	outs << genre << std::endl
		<< releaseDate << std::endl
		<< ((isElectronic) ? "true" : "false") << std::endl;	 // bool variable must be translated into a string (ternary operator is used).
}

// Prints all attributes the user can change along with the number they need to select to change them.
void DigitalMedia::printChangeableAttributes() const {
	Product::printChangeableAttributes();
	std::cout << "5 - Release Date" << std::endl
		<< "6 - Genre" << std::endl
		<< "7 - IsElectronic" << std::endl;
}

std::string DigitalMedia::getGenre() const {
	return genre;
}

std::string DigitalMedia::getReleaseDate() const {
	return releaseDate;
}

bool DigitalMedia::getIsElectronic() const {
	return isElectronic;
}

/// 
/// Mutator methods (Setters)
/// 
void DigitalMedia::setGenre(const std::string& newGenre) {
	genre = newGenre;
}

void DigitalMedia::setReleaseDate(const std::string& newReleaseDate) {
	releaseDate = newReleaseDate;
}

void DigitalMedia::setIsElectronic(bool newIsElectronic) {
	isElectronic = newIsElectronic;
}

// virtual void changeAttribute(int userChoice) = 0;

// Initializes an object of this class by reading data from an external file through the ins stream.
// This method is not called to create an object of this class (DigitalMedia is abstract), but it is overrided in child classes.
void DigitalMedia::initalizeFromFile(std::ifstream& ins) {
	Product::initalizeFromFile(ins);
	std::string tmpStr;

	std::getline(ins, genre);

	std::getline(ins, releaseDate);

	std::getline(ins, tmpStr);
	isElectronic = (tmpStr == "true") ? true : false;		// string input must be converted into a boolean (ternary operator is used).
}