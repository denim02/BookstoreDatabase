#pragma once
#include <string>

// Class interface for StringMatcher class (Boyer-Moore string matching algorithm)

class StringMatcher
{
public:
	// Constructor
	StringMatcher(std::string& text, std::string& pattern);

	// Mutator methods
	int init();
	int operator++();

	// Accessor methods
	bool operator!() const;

private:
	// Data fields for StringMatcher class
	std::string& text;
	std::string& pattern;
	unsigned int patternLength;
	int matchPosition;
	int positions[256];

};

