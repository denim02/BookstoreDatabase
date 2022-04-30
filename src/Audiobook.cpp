#include "Audiobook.h"
// <string> and <fstream> libraries included from parent class
// <vector> library included in header file
#include <iostream>		// needed for changeAttribute method
#include <sstream>      // Needed to convert numeric types into string

// Implementation for Audiobook class

// Constructor for Audiobook class (also calls constructor for parent DigitalMedia class)
Audiobook::Audiobook()
	: DigitalMedia(), author(""), duration(0), bookType(""), reader("") {
	setCategory("Audiobook");
}

Audiobook::Audiobook(
	const std::string& title,
	double price,
	int numInStock,
	const std::string& language,
	const std::string& genre,
	const std::string& releaseDate,
	bool isElectronic,
	const std::string& author,
	double duration,
	const std::string& bookType,
	const std::string& reader)
	: DigitalMedia(title, price, numInStock, language, genre, releaseDate, isElectronic), author(author),
	duration(duration), bookType(bookType), reader(reader) {
	setCategory("Audiobook");
}

/// 
/// Accessors (Getters)
/// 
// Returns a string containing all product attributes.
std::string Audiobook::getDescription() const {
	std::stringstream stringConv;
	std::string durationStr;

	stringConv << duration;
	stringConv >> durationStr;

	return DigitalMedia::getDescription() + '\n'
		+ "Author: " + author + '\n'
		+ "Duration: " + durationStr + '\n'
		+ "Book Type: " + bookType + '\n'
		+ "Reader: " + reader;
}

// Outputs all product attributes to an external file through the outs stream in a format readable by the program.
void Audiobook::outputToFile(std::ofstream& outs) const {
	DigitalMedia::outputToFile(outs);
	outs << author << std::endl
		<< duration << std::endl
		<< bookType << std::endl
		<< reader << std::endl;
}

// Prints all attributes the user can change along with the number they need to select to change them.
void Audiobook::printChangeableAttributes() const {
	DigitalMedia::printChangeableAttributes();
	std::cout << "8 - Author" << std::endl
		<< "9 - Duration (in hours)" << std::endl
		<< "10 - Book Type" << std::endl
		<< "11 - Reader" << std::endl;
}

std::string Audiobook::getAuthor() const {
	return author;
}

double Audiobook::getDuration() const {
	return duration;
}

std::string Audiobook::getBookType() const {
	return bookType;
}
std::string Audiobook::getReader() const {
	return reader;
}

/// 
/// Mutator methods (Setters)
///
void Audiobook::setAuthor(const std::string& newAuthor) {
	author = newAuthor;
}

void Audiobook::setDuration(double newDuration) {
	duration = newDuration;
}

void Audiobook::setBookType(const std::string& newBookType) {
	bookType = newBookType;
}

void Audiobook::setReader(const std::string& newReader) {
	reader = newReader;
}

 // Based on which attribute a user chose to change, this method will print the old value of that attribute and allow the user to enter
// a new one.
void Audiobook::changeAttribute(int userChoice) {
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
			std::cin.ignore();							// Input stream must be cleared in case '\n' characters are left in the line
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
			std::string newAuthor;
			std::cout << "Old author: " << getAuthor() << std::endl;
			std::cout << "Enter new author: ";
			std::cin.ignore();						// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newAuthor);
			setAuthor(newAuthor);
		}
		else if (userChoice == 9) {
			double newDuration;
			std::cout << "Old duration: " << getDuration() << std::endl;
			std::cout << "Enter new audiobook duration (in hours, numeric): ";
			std::cin >> newDuration;
			setDuration(newDuration);
		}
		else if (userChoice == 10) {
			std::string newBookType;
			std::cout << "Old book type: " << getBookType() << std::endl;
			std::cout << "Enter new book type: ";
			std::cin.ignore();						// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newBookType);
			setBookType(newBookType);
		}
		else if (userChoice == 11) {
			std::string newReader;
			std::cout << "Old reader: " << getReader() << std::endl;
			std::cout << "Enter new reader: ";
			std::cin.ignore();						// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newReader);
			setReader(newReader);
		}
	}
}

// Initializes an object of this class by reading data from an external file through the ins stream.
void Audiobook::initalizeFromFile(std::ifstream& ins) {
	DigitalMedia::initalizeFromFile(ins);
	std::stringstream stringConv;
	std::string tmpStr;

	std::getline(ins, author);

	std::getline(ins, tmpStr);
	stringConv << tmpStr;
	stringConv >> duration;

	std::getline(ins, bookType);
	std::getline(ins, reader);
}