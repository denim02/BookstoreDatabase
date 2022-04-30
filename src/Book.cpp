#include "Book.h"
// <string> and <fstream> libraries included from parent class
#include <iostream>		// needed for changeAttribute method

// Implementation for Book class

// Constructor for Book class (also calls constructor for parent PhysicalMedia class)
Book::Book()
	: PhysicalMedia(), genre(""), author(""), bookType("") {
	setCategory("Book");
}

Book::Book(
	const std::string& title,
	double price,
	int numInStock,
	const std::string& language,
	const std::string& publisher,
	int publishingYear,
	int numPages,
	const std::string& genre,
	const std::string& author,
	const std::string& bookType)
	: PhysicalMedia(title, price, numInStock, language, publisher, publishingYear, numPages), genre(genre), author(author), bookType(bookType) {
	setCategory("Book");
}

/// 
/// Accessors (Getters)
/// 
// Returns a string containing all product attributes.
std::string Book::getDescription() const {
	return PhysicalMedia::getDescription() + '\n'
		+ "Genre: " + genre + '\n'
		+ "Author: " + author + '\n'
		+ "Book Type: " + bookType;
}

// Outputs all product attributes to an external file through the outs stream in a format readable by the program.
void Book::outputToFile(std::ofstream& outs) const {
	PhysicalMedia::outputToFile(outs);
	outs << genre << std::endl
		<< author << std::endl
		<< bookType << std::endl;
}

// Prints all attributes the user can change along with the number they need to select to change them.
void Book::printChangeableAttributes() const {
	PhysicalMedia::printChangeableAttributes();
	std::cout << "8 - Genre" << std::endl
		<< "9 - Author" << std::endl
		<< "10 - Book Type" << std::endl;
}

std::string Book::getGenre() const {
	return genre;
}

std::string Book::getAuthor() const {
	return author;
}

std::string Book::getBookType() const {
	return bookType;
}

/// 
/// Mutator methods (Setters)
/// 
void Book::setGenre(const std::string& newGenre) {
	genre = newGenre;
}

void Book::setAuthor(const std::string& newAuthor) {
	author = newAuthor;
}

void Book::setBookType(const std::string& newBookType) {
	bookType = newBookType;
}

 // Based on which attribute a user chose to change, this method will print the old value of that attribute and allow the user to enter
// a new one.
void Book::changeAttribute(int userChoice) {
	if (userChoice) {
		if (userChoice == 1) {				// Cannot use switch when initializing a var in each case, as switch cannot skip initializations.
			std::string newTitle;
			std::cout << "Old title: " << getTitle() << std::endl;
			std::cout << "Enter new title: ";
			std::cin.ignore();						// Input stream must be cleared in case '\n' characters are left in the line
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
			std::cin.ignore();							// Input stream must be cleared in case '\n' characters are left in the line
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
			std::string newGenre;
			std::cout << "Old genre: " << getGenre() << std::endl;
			std::cout << "Enter new genre: ";
			std::cin.ignore();						// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newGenre);
			setGenre(newGenre);
		}
		else if (userChoice == 9) {
			std::string newAuthor;
			std::cout << "Old author: " << getAuthor() << std::endl;
			std::cout << "Enter new author: ";
			std::cin.ignore();						// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newAuthor);
			setAuthor(newAuthor);
		}
		else if (userChoice == 10) {
			std::string newBookType;
			std::cout << "Old book type: " << getBookType() << std::endl;
			std::cout << "Enter new book type: ";
			std::cin.ignore();						// Input stream must be cleared in case '\n' characters are left in the line
			std::getline(std::cin, newBookType);
			setBookType(newBookType);
		}
	}
}

// Initializes an object of this class by reading data from an external file through the ins stream.
void Book::initalizeFromFile(std::ifstream& ins) {
	PhysicalMedia::initalizeFromFile(ins);

	std::getline(ins, genre);
	std::getline(ins, author);
	std::getline(ins, bookType);
}
