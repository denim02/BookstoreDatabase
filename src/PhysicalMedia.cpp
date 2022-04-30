#include "PhysicalMedia.h"
// <string> and <fstream> libraries included from parent class
#include <sstream>		// Needed to convert numeric types into string
#include <iostream>

// Implementation for PhysicalMedia class

// Constructor for PhysicalMedia class (also calls constructor for parent Product class)
PhysicalMedia::PhysicalMedia()
    : Product(), publisher(""), publishingYear(0), numPages(0) {
    setFormat("Physical");
}

PhysicalMedia::PhysicalMedia(
    const std::string& title,
    double price,
    int numInStock,
    const std::string& language,
    const std::string& publisher,
    int publishingYear,
    int numPages)
    : Product(title, price, numInStock, language), publisher(publisher), publishingYear(publishingYear), numPages(numPages) {
    setFormat("Physical");
}

/// 
/// Accessors (Getters)
/// 
// Returns a string containing all product attributes.
std::string PhysicalMedia::getDescription() const {
    std::string publishingYearStr, numPagesStr;
    std::stringstream stringConv;

    stringConv << publishingYear;
    stringConv >> publishingYearStr;

    stringConv.clear();                 // stringstream needs to be cleared between conversions.

    stringConv << numPages;
    stringConv >> numPagesStr;

    return Product::getDescription() + '\n'
        + "Publisher: " + publisher + '\n'
        + "Publishing Year: " + publishingYearStr + '\n'
        + "Number of Pages: " + numPagesStr;
}

// Outputs all product attributes to an external file through the outs stream in a format readable by the program.
void PhysicalMedia::outputToFile(std::ofstream& outs) const {
    Product::outputToFile(outs);
    outs << publisher << std::endl
        << publishingYear << std::endl
        << numPages << std::endl;
}

// Prints all attributes the user can change along with the number they need to select to change them.
void PhysicalMedia::printChangeableAttributes() const {
    Product::printChangeableAttributes();
    std::cout << "5 - Publisher" << std::endl
        << "6 - Publishing Year" << std::endl
        << "7 - Number of pages" << std::endl;
}

std::string PhysicalMedia::getPublisher() const {
    return publisher;
}

int PhysicalMedia::getPublishingYear() const {
    return publishingYear;
}

int PhysicalMedia::getNumPages() const {
    return numPages;
}

/// 
/// Mutator methods (Setters)
/// 
void PhysicalMedia::setPublisher(const std::string& newPublisher) {
    publisher = newPublisher;
}
void PhysicalMedia::setPublishingYear(int newYear) {
    publishingYear = newYear;
}
void PhysicalMedia::setNumPages(int newNumPages) {
    numPages = newNumPages;
}

// virtual void changeAttribute(int userChoice) = 0;

// Initializes an object of this class by reading data from an external file through the ins stream.
// This method is not called to create an object of this class (PhysicalMedia is abstract), but it is overrided in child classes.
void PhysicalMedia::initalizeFromFile(std::ifstream& ins) {
    Product::initalizeFromFile(ins);
    std::stringstream stringConv;
    std::string tmpStr;

    std::getline(ins, publisher);

    std::getline(ins, tmpStr);
    stringConv << tmpStr;
    stringConv >> publishingYear;

    stringConv.clear();             // stringstream needs to be cleared between conversions.

    std::getline(ins, tmpStr);
    stringConv << tmpStr;
    stringConv >> numPages;
}