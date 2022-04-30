#pragma once
#include "DigitalMedia.h"
#include <vector>
// <string> and <fstream> libraries are included from parent class

// Class interface for AudioCD class

class AudioCD :
    public DigitalMedia
{
public:
    AudioCD();

    // Constructor for AudioCD class
    AudioCD(
        const std::string& title,
        double price,
        int numInStock,
        const std::string& language,
        const std::string& genre,
        const std::string& releaseDate,
        bool isElectronic,
        const std::string& musician,
        double runtime,
        const std::vector<std::string>& trackList);

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

    // Getters for all AudioCD attributes
    std::string getMusician() const;
    double getRuntime() const;
    const std::vector<std::string>& getTrackList() const;

protected:
    // Mutator methods (Setters), defined as protected because they are called through changeAttribute method
    void setMusician(const std::string& newMusician);
    void setRuntime(double newRuntime);
    void setTrackList(const std::vector<std::string>& newTrackList);

private:
    // Data fields for AudioCD class
    std::string musician;
    double runtime;       // in hours (so 90 minutes is 1.5 hours)
    std::vector<std::string> trackList;
};

