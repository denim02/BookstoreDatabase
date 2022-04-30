#pragma once
#include "DigitalMedia.h"
#include <vector>
// <string> and <fstream> libraries are included from parent class

// Class interface for MovieDVD class

class MovieDVD :
    public DigitalMedia
{
public:
    MovieDVD();

    // Constructor for MovieDVD class
    MovieDVD(
        const std::string& title,
        double price,
        int numInStock,
        const std::string& language,
        const std::string& genre,
        const std::string& releaseDate,
        bool isElectronic,
        double duration,
        const std::vector<std::string>& mainCast);

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

    // Getters for all MovieDVD attributes
    double getDuration() const;
    const std::vector<std::string>& getMainCast() const;

protected:
    // Mutator methods (Setters), defined as protected because they are called through changeAttribute method
    void setDuration(double newDuration);
    void setMainCast(const std::vector<std::string>& newMainCast);

private:
    // Data fields for MovieDVD class
    double duration;
    std::vector<std::string> mainCast;
};

