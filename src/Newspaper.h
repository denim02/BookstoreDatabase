#pragma once
#include "PhysicalMedia.h"
// <string> and <fstream> libraries are included from parent class

// Class interface for Newspaper class

class Newspaper :
    public PhysicalMedia
{
public:
    // Constructors for Newspaper class
    Newspaper();

    Newspaper(
        const std::string& title,
        double price,
        int numInStock,
        const std::string& language,
        const std::string& publisher,
        int publishingYear,
        int numPages,
        const std::string& date,
        const std::string& mainArticleTitle);

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

    // Getters for all Newspaper attributes
    std::string getDate() const;
    std::string getMainArticleTitle() const;

protected:
    // Mutator methods (Setters), defined as protected because they are called through changeAttribute method
    void setDate(const std::string& newDate);
    void setMainArticleTitle(const std::string& newMainArticleTitle);

private:
    // Data fields for Newspaper class
    std::string date;
    std::string mainArticleTitle;
};

