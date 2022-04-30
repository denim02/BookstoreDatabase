#pragma once
#include "PhysicalMedia.h"
// <string> and <fstream> libraries are included from parent class

// Class interface for Book class

class Book :
    public PhysicalMedia
{
public:
    // Constructors for Book class
    Book();

    Book(
        const std::string& title,
        double price,
        int numInStock,
        const std::string& language,
        const std::string& publisher,
        int publishingYear,
        int numPages,
        const std::string& genre,
        const std::string& author,
        const std::string& bookType);

    // Mutator methods
    void changeAttribute(int userChoice);
    void initalizeFromFile(std::ifstream& ins);

    // Accessor methods (Getters)
    // getDescription() returns string containing all attributes associated with the product.
    std::string getDescription() const;
    // outputToFile outputs class attributes to an output file stream, in a format readable by initializeFromFile method.
    void outputToFile(std::ofstream& outs) const;
    // printChangeableAttribute outputs to console all possible attributes the user can change; used in conjunction with changeAttribute method.
    void printChangeableAttributes() const;

    // Getters for all Book attributes
    std::string getGenre() const;
    std::string getAuthor() const;
    std::string getBookType() const;

protected:
    // Mutator methods (Setters), defined as protected because they are called through changeAttribute method
    void setGenre(const std::string& newGenre);
    void setAuthor(const std::string& newAuthor);
    void setBookType(const std::string& newBookType);

private:
    // Data fields for Book class
    std::string genre;
    std::string author;
    std::string bookType;       // Novel, textbook, poem collection, etc
};

