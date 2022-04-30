#pragma once
#include "Product.h"
// <string> and <fstream> libraries are included in "Product.h"

// Class interface for abstract DigitalMedia class

class DigitalMedia :
    public Product
{
public:
    // Constructor for abstract DigitalMedia class
    DigitalMedia();

    DigitalMedia(
        const std::string& title,
        double price,
        int numInStock,
        const std::string& language,
        const std::string& genre,
        const std::string& releaseDate,
        bool isElectronic);

    // Mutator methods
    // Polymorphic changeAttribute method allows user to change attributes associated with a product (needs to
    // be polymorphic as different products have different attributes)
    virtual void changeAttribute(int userChoice) = 0;
    virtual void initalizeFromFile(std::ifstream& ins);

    // Accessor methods (Getters)
    // Polymorphic method getDescription() returns string containing all attributes associated with the product.
    virtual std::string getDescription() const;
    // outputToFile outputs class attributes to an output file stream, in a format readable by initializeFromFile method.
    virtual void outputToFile(std::ofstream& outs) const;
    // printChangeableAttribute outputs to console all possible attributes the user can change; used in conjunction with changeAttribute method.
    virtual void printChangeableAttributes() const;

    // Getters for all DigitalMedia attributes
    std::string getGenre() const;
    std::string getReleaseDate() const;
    bool getIsElectronic() const;

protected:
    // Mutator methods (Setters), defined as protected because they are called through changeAttribute method
    void setGenre(const std::string& newGenre);
    void setReleaseDate(const std::string& newReleaseDate);
    void setIsElectronic(bool newIsElectronic);

private:
    // Data fields for DigitalMedia class
    std::string releaseDate;
    std::string genre;
    bool isElectronic;  // Shows if the product is not sold physically (Audiobooks for example)
};

