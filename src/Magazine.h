#pragma once
#include "PhysicalMedia.h"
// <string> and <fstream> libraries are included from parent class

// Class interface for Magazine class

class Magazine :
    public PhysicalMedia
{
public:
    // Constructors for Magazine class
    Magazine();

    Magazine(
        const std::string& title,
        double price,
        int numInStock,
        const std::string& language,
        const std::string& publisher,
        int publishingYear,
        int numPages,
        const std::string& magazineType
    );

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

    // Getters for all Magazine attributes
    std::string getMagazineType() const;

protected:
    // Mutator methods (Setters), defined as protected because they are called through changeAttribute method
    void setMagazineType(const std::string& newMagazineType);

private:
    // Data fields for Magazine class
    std::string magazineType;

};

