#pragma once
#include "DigitalMedia.h"
// <string> and <fstream> libraries are included from parent class

// Class interface for Audiobook class

class Audiobook :
    public DigitalMedia
{
public:
    Audiobook();

    // Constructor for Audiobook class
    Audiobook(
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
        const std::string& reader);

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

    // Getters for all Audiobook attributes
    std::string getAuthor() const;
    double getDuration() const;
    std::string getBookType() const;
    std::string getReader() const;

protected:
    // Mutator methods (Setters), defined as protected because they are called through changeAttribute method
    void setAuthor(const std::string& newAuthor);
    void setDuration(double newDuration);
    void setBookType(const std::string& newBookType);
    void setReader(const std::string& newReader);

private:
    // Data fields for Audiobook class
    std::string author;
    double duration;    // in hours (so 90 minutes is 1.5 hours)
    std::string bookType;
    std::string reader;
};

