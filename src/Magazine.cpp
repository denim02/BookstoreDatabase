#include "Magazine.h"
// <string> and <fstream> libraries included from parent class
#include <iostream>		// needed for changeAttribute method

// Implementation for Magazine class

// Constructor for Magazine class (also calls constructor for parent PhysicalMedia class)
Magazine::Magazine()
	: PhysicalMedia(), magazineType("") {
	setCategory("Magazine");
}

Magazine::Magazine(
	const std::string& title,
	double price,
	int numInStock,
	const std::string& language,
	const std::string& publisher,
	int publishingYear,
	int numPages,
	const std::string& magazineType)
	: PhysicalMedia(title, price, numInStock, language, publisher, publishingYear, numPages), magazineType(magazineType) {
	setCategory("Magazine");
}

/// 
/// Accessors (Getters)
/// 
// Returns a string containing all product attributes.
std::string Magazine::getDescription() const {
	return PhysicalMedia::getDescription() + '\n'
		+ "Magazine Type: " + magazineType;
}

// Outputs all product attributes to an external file through the outs stream in a format readable by the program.
void Magazine::outputToFile(std::ofstream& outs) const {
	PhysicalMedia::outputToFile(outs);
	outs << magazineType << std::endl;
}

// Prints all attributes the user can change along with the number they need to select to change them.
void Magazine::printChangeableAttributes() const {
	PhysicalMedia::printChangeableAttributes();
	std::cout << "8 - Magazine Type" << std::endl;
}

std::string Magazine::getMagazineType() const {
	return magazineType;
}


/// 
/// Mutator methods (Setters)
/// 
void Magazine::setMagazineType(const std::string& newMagazineType) {
	magazineType = newMagazineType;
}

 // Based on which attribute a user chose to change, this method will print the old value of that attribute and allow the user to enter
// a new one.
void Magazine::changeAttribute(int userChoice) {
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
			std::string newPublisher;
			std::cout << "Old publisher: " << getPublisher() << std::endl;
			std::cout << "Enter new publisher: ";
			std::cin.ignore();						// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newPublisher);
			setPublisher(newPublisher);
		}
		else if (userChoice == 6) {
			int newPublishingYear;
			std::cout << "Old publishing year: " << getPublishingYear() << std::endl;
			std::cout << "Enter new publishing year (numeric): ";
			std::cin >> newPublishingYear;
			setPublishingYear(newPublishingYear);
		}
		else if (userChoice == 7) {
			int newNumPages;
			std::cout << "Old number of pages: " << getNumPages() << std::endl;
			std::cout << "Enter new number of pages (numeric): ";
			std::cin >> newNumPages;
			setNumPages(newNumPages);
		}
		else if (userChoice == 8) {
			std::string newMagazineType;
			std::cout << "Old magazine type: " << getMagazineType() << std::endl;
			std::cout << "Enter new magazine type: ";
			std::cin.ignore();						// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newMagazineType);
			setMagazineType(newMagazineType);
		}
	}
}

// Initializes an object of this class by reading data from an external file through the ins stream.
void Magazine::initalizeFromFile(std::ifstream& ins) {
	PhysicalMedia::initalizeFromFile(ins);

	std::getline(ins, magazineType);
}
