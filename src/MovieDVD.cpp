#include "MovieDVD.h"
// <string> and <fstream> libraries included from parent class
// <vector> library included in header file
#include <iostream>		// needed for changeAttribute method
#include <sstream>      // Needed to convert numeric types into string

// Implementation for MovieDVD class

// Constructor for MovieDVD class (also calls constructor for parent DigitalMedia class)
MovieDVD::MovieDVD()
	: DigitalMedia(), duration(0) {
	setCategory("MovieDVD");
}

MovieDVD::MovieDVD(
	const std::string& title,
	double price,
	int numInStock,
	const std::string& language,
	const std::string& genre,
	const std::string& releaseDate,
	bool isElectronic,
	double duration,
	const std::vector<std::string>& mainCast)
	: DigitalMedia(title, price, numInStock, language, genre, releaseDate, isElectronic), duration(duration), mainCast(mainCast) {
	setCategory("MovieDVD");
}

/// 
/// Accessors (Getters)
// Returns a string containing all product attributes (cast list in MovieDVD is returned in comma-seperated line).
std::string MovieDVD::getDescription() const {
	std::stringstream stringConv;
	std::string durationStr;

	stringConv << duration;
	stringConv >> durationStr;
	
	std::string description = DigitalMedia::getDescription() + '\n'
		+ "Duration: " + durationStr + '\n'
		+ "Main Cast: ";

	for (int i = 0; i < mainCast.size(); i++) {
		if (i != mainCast.size() - 1)
			description += (mainCast[i] + ", ");
		else
			description += mainCast[i];
	}

	return description;
}

// Outputs all product attributes to an external file through the outs stream in a format readable by the program.
void MovieDVD::outputToFile(std::ofstream& outs) const {
	DigitalMedia::outputToFile(outs);

	outs << duration << std::endl;

	for (int i = 0; i < mainCast.size(); i++) {
		if (i != mainCast.size() - 1)
			outs << mainCast[i] << "#";
		else
			outs << mainCast[i];
	}

	outs << std::endl;
}

// Prints all attributes the user can change along with the number they need to select to change them.
void MovieDVD::printChangeableAttributes() const {
	DigitalMedia::printChangeableAttributes();
	std::cout << "8 - Duration" << std::endl
		<< "9 - Movie Cast" << std::endl;
}

double MovieDVD::getDuration() const {
	return duration;
}

const std::vector<std::string>& MovieDVD::getMainCast() const {
	return mainCast;
}

/// 
/// Mutator methods (Setters)
///
void MovieDVD::setDuration(double newDuration) {
	duration = newDuration;
}

void MovieDVD::setMainCast(const std::vector<std::string>& newMainCast) {
	mainCast = newMainCast;
}

 // Based on which attribute a user chose to change, this method will print the old value of that attribute and allow the user to enter
// a new one.
void MovieDVD::changeAttribute(int userChoice) {
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
			std::cin.ignore();				// Input stream must be cleared in case '\n' characters are left in the line
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
			double newDuration;
			std::cout << "Old duration: " << getDuration() << std::endl;
			std::cout << "Enter new duration (numeric): ";
			std::cin >> newDuration;
			setDuration(newDuration);
		}
		else if (userChoice == 9) {
			std::vector<std::string> newMainCast;

			std::string newInput;
			std::cout << "Enter new actor from main cast or leave blank to stop: ";
			std::cin.ignore();				// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newInput);
			while (newInput != "") {
				newMainCast.push_back(newInput);
				std::cout << "Enter new actor from main cast or leave blank to stop: ";
				std::getline(std::cin, newInput);
			}
			setMainCast(newMainCast);
		}
	}
}

// Initializes an object of this class by reading data from an external file through the ins stream.
void MovieDVD::initalizeFromFile(std::ifstream& ins) {
	DigitalMedia::initalizeFromFile(ins);
	std::stringstream stringConv;
	std::string tmpLine, tmpStr;
	std::vector<std::string> tmpVec;

	std::getline(ins, tmpLine);
	stringConv << tmpLine;
	stringConv >> duration;

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

	mainCast = tmpVec;
}