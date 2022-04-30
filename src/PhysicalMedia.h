#pragma once
#include "Product.h"
// <string> and <fstream> libraries are included in "Product.h"

// Class interface for abstract PhysicalMedia class

class PhysicalMedia :
    public Product
{
public:
    // Constructors for abstract PhysicalMedia class
    PhysicalMedia();

    PhysicalMedia(
        const std::string& title,
        double price,
        int numStock,
        const std::string& language,
        const std::string& publisher,
        int publishingYear,
        int numPages);

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

    // Getters for all PhysicalMedia attributes
    std::string getPublisher() const;
    int getPublishingYear() const;
    int getNumPages() const;

protected:
    // Mutator methods (Setters), defined as protected because they are called through changeAttribute method
    void setPublisher(const std::string& newPublisher);
    void setPublishingYear(int newYear);
    void setNumPages(int newNumPages);

private:
    // Data fields for PhysicalMedia class
    std::string publisher;
    int publishingYear;
    int numPages;
};

