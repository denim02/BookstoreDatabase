#pragma once
#include <string>
#include <fstream>

// Class interface for abstract Product class

class Product
{
public:
	// Constructors for Product class which will be used by child classes (Product is abstract)
	Product();

	Product(
		const std::string& title,
		double price,
		int numInStock,
		const std::string& language);

	// Mutator methods
	// Polymorphic changeAttribute method allows user to change attributes associated with a product (needs to
	// be polymorphic as different products have different attributes)
	virtual void changeAttribute(int userChoice) = 0;
	virtual void initalizeFromFile(std::ifstream& ins);
	// setNumInStock is defined as public, because it is called every time a duplicate element is added into the bookstore database
	void setNumInStock(int newNumInStock);

	// Accessor methods (Getters)
	// Polymorphic method getDescription() returns string containing all attributes associated with the product.
	virtual std::string getDescription() const;
	// outputToFile outputs class attributes to an output file stream, in a format readable by initializeFromFile method.
	virtual void outputToFile(std::ofstream& outs) const;
	// printChangeableAttribute outputs to console all possible attributes the user can change; used in conjunction with changeAttribute method.
	virtual void printChangeableAttributes() const;

	// Getters for all product attributes
	std::string getTitle() const;
	std::string getFormat() const;
	std::string getCategory() const;
	double getPrice() const;
	int getNumInStock() const;
	std::string getLanguage() const;

protected:
	// Mutator methods (Setters), defined as protected because they are called through changeAttribute method
	void setTitle(const std::string& newTitle);
	void setFormat(const std::string& newFormat);
	void setCategory(const std::string& newCategory);
	void setPrice(double newPrice);
	void setLanguage(const std::string& newLanguage);

private:
	// Data fields for Product class
	std::string title;
	std::string format; // Physical or Digital; auto-set based on which object is created
	std::string category; // Book, magazine, CD, etc; auto-set based on which object is created
	double price;
	int numInStock;
	std::string language;

};

