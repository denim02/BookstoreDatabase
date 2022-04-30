#pragma once
#include <list>		// <list> library is imported to implement seperate chaining collision resolution
#include "Product.h"
#include <vector>

// Class interface for HashTable class

class HashTable
{
public:
	// Constructor
	HashTable(int buckets);
	// Destructor
	~HashTable();

	// Mutator methods
	void initializeFromFile(std::ifstream& ins);

	void insertElement(Product* item);

	void insertElement();
	void deleteElement(const std::string& title);
	void modifyElement(const std::string& title);

	// Hash functions to determine element keys
	int hashFunction(Product* item);
	int hashFunction(const std::string& title);
	unsigned long hash(const std::string& title);

	// Accessor methods
	void printTable();
	void outputToFile(std::ofstream& outs);
	void printElement(const std::string& title);

	std::list<Product*>::iterator searchByFullTitle(const std::string& title);
	std::vector<const Product*> searchKeywordInTitle(std::string& keyword);
	std::vector<const Product*> searchDescription(std::string& keyword);

private:
	// Data fields for HashTable class
	int buckets;
	std::list<Product*>* table;
};

