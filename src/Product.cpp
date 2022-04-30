#include "Product.h"
// <string> and <fstream> libraries included in header "Product.h"
#include <sstream>		// Needed to convert numeric types into string
#include <iostream>

// Implementation for Product class

// Constructor for Product class
Product::Product()
	: title(""), price(0), numInStock(0), language("") {}

Product::Product(
	const std::string& title,
	double price,
	int numInStock,
	const std::string& language)
	: title(title), price(price), numInStock(numInStock), language(language) {}

/// 
/// Accessors (Getters)
///

// Returns a string containing all product attributes.
std::string Product::getDescription() const {
	std::string priceStr, numStockStr;
	std::stringstream stringConv;

	stringConv << price;
	stringConv >> priceStr;

	stringConv.clear();		// stringstream needs to be cleared between conversions.

	stringConv << numInStock;
	stringConv >> numStockStr;

	return "Title: " + title + '\n'
		+ "Category: " + category + '\n'
		+ "Format: " + format + '\n'
		+ "Price: " + priceStr + '\n'
		+ "Number in stock: " + numStockStr + '\n'
		+ "Language: " + language;
}

// Outputs all product attributes to an external file through the outs stream in a format readable by the program.
void Product::outputToFile(std::ofstream& outs) const {
	outs << category << std::endl
		<< title << std::endl
		<< price << std::endl
		<< numInStock << std::endl
		<< language << std::endl;
}

// Prints all attributes the user can change along with the number they need to select to change them.
void Product::printChangeableAttributes() const {
	std::cout << "1 - Title" << std::endl
		<< "2 - Price" << std::endl
		<< "3 - Number in stock" << std::endl
		<< "4 - Language" << std::endl;
}

std::string Product::getTitle() const {
	return title;
}

std::string Product::getFormat() const {
	return format;
}

std::string Product::getCategory() const {
	return category;
}

double Product::getPrice() const {
	return price;
}

int Product::getNumInStock() const {
	return numInStock;
}


std::string Product::getLanguage() const {
	return language;
}

/// 
/// Mutator methods (Setters)
/// 
void Product::setTitle(const std::string& newTitle) {
	title = newTitle;
}

void Product::setFormat(const std::string& newFormat) {
	format = newFormat;
}

void Product::setCategory(const std::string& newCategory) {
	category = newCategory;
}

void Product::setPrice(double newPrice) {
	price = newPrice;
}

void Product::setNumInStock(int newNumInStock) {
	numInStock = newNumInStock;
}

void Product::setLanguage(const std::string& newLanguage) {
	language = newLanguage;
}

// virtual void changeAttribute(int userChoice) = 0;

// Initializes an object of this class by reading data from an external file through the ins stream.
// This method is not called to create an object of this class (Product is abstract), but it is overrided in child classes.
void Product::initalizeFromFile(std::ifstream& ins) {
	std::stringstream stringConv;
	std::string tmpStr;

	std::getline(ins, title);

	std::getline(ins, tmpStr);
	stringConv << tmpStr;
	stringConv >> price;

	stringConv.clear();				// stringstream needs to be cleared between conversions.

	std::getline(ins, tmpStr);
	stringConv << tmpStr;
	stringConv >> numInStock;

	std::getline(ins, language);
}