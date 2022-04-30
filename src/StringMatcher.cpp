#include "StringMatcher.h"
// <string> library included in "StringMatcher.h" header
#include <cctype>	// included to convert all characters to lowercase (so English is seen as a match with english for example)

// Implementation for StringMatcher class

/// 
/// Constructor
/// 
StringMatcher::StringMatcher(std::string& text, std::string& pattern)		// Only one constructor with two parameters
	: text(text), pattern(pattern), matchPosition(0) {				// Member initializer list is used to initialize class members.
	patternLength = pattern.length();

	for (int i = 0; i < 256; i++)							// This for-loop iterates through positions array (required for Boyer-Moore SM algorithm)
		positions[i] = 0;								   // and initializes each array value to 0.

	for (int i = 0; pattern[i]; i++)						// The second for-loop goes through all characters of string "pattern" and sets the corresponding
		positions[pattern[i]] = i;						   // value in the positions array equal to the rightmost index where each character appears.
}

///
/// Mutator methods
/// 
int StringMatcher::init() {									// The init() function initializes the BMAlgo object for a search by setting the matchPosition member to -1
	matchPosition = -1;									   // and returning the first match found (or 0 if nothing is found).
	return operator++();
}

int StringMatcher::operator++() {										// The operator++() function overloads the pre-increment operator to return the index of the next
																	   // match found in a text.
	int maxPosition = text.length() - patternLength;				  // The bound for the loop is set to the last element in the text from which the pattern could start.
	matchPosition += 1;

	while (matchPosition <= maxPosition) {
		int patPosition = patternLength - 1;											// The starting position for the comparison is set to the right of the pattern												
																					   // since the BM algorithm compares each character in the pattern and text right to left.
		while ((patPosition >= 0) && (tolower(pattern[patPosition]) == tolower(text[matchPosition + patPosition])))	 // If the elements are found to be equal, the comparison continues
			patPosition--;																			   // towards the left.

		if (patPosition < 0)														   // If the index used for traversing the pattern has become less than 0,
			return 1;																  // all elements in the pattern have been found to be equal to elements in
																					 // the text (while-loop did not end early), so we have found a match.

		int shift = patPosition - positions[text[matchPosition + patPosition]];			  // If the index has not become negative, we have encountered a mismatch at
																						 // the current index value, so a shift according to the positions table is calculated.
		if (shift < 1)																	// If this shift is negative, we instead shift forward by 1 (no sense in going backwards).
			matchPosition += 1;
		else
			matchPosition += shift;													// If it is positive, we move forward by the shift amount and start comparing again.
	}

	matchPosition = -1;															// In the case when the while-loop finishes iterating without a return from inside, we
	return 0;																   // know for sure that no match has been found, so we set matchPosition to -1
}																			  // and return 0.

/// 
/// Accessor methods
/// 
bool StringMatcher::operator!() const {											// Checks if all possible matches have been exhausted.
	return ((matchPosition >= 0) && (matchPosition < text.length()));
}

