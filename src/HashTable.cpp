#include "HashTable.h"
// <list>, <vector>, and "Product.h" are included in the header file
#include "Book.h"
#include "Newspaper.h"
#include "Magazine.h"
#include "Audiobook.h"
#include "AudioCD.h"
#include "MovieDVD.h"
#include <iostream>
#include "StringMatcher.h"

// Implementation for HashTable class

// Constructor
HashTable::HashTable(int noOfBuckets) {
    buckets = noOfBuckets;
    table = new std::list<Product*>[buckets];
}

  // Reads from an external file and initializes the database with its data. The first line of each new product indicates the
 // product type. Subsequent lines contain all product attributes. The initializeFromFile methods of the individual classes are called
// to read this data.
void HashTable::initializeFromFile(std::ifstream& ins) {
    std::string tmpStr;

    while (!ins.eof()) {
        getline(ins, tmpStr);

        if (tmpStr == "Book") {
            Book* newBook = new Book();
            newBook->initalizeFromFile(ins);
            insertElement(newBook);
        }
        else if (tmpStr == "Newspaper") {
            Newspaper* newNewspaper = new Newspaper();
            newNewspaper->initalizeFromFile(ins);
            insertElement(newNewspaper);
        }
        else if (tmpStr == "Magazine") {
            Magazine* newMagazine = new Magazine();
            newMagazine->initalizeFromFile(ins);
            insertElement(newMagazine);
        }
        else if (tmpStr == "Audiobook") {
            Audiobook* newAudiobook = new Audiobook();
            newAudiobook->initalizeFromFile(ins);
            insertElement(newAudiobook);
        }
        else if (tmpStr == "AudioCD") {
            AudioCD* newAudioCD = new AudioCD();
            newAudioCD->initalizeFromFile(ins);
            insertElement(newAudioCD);
        }
        else if (tmpStr == "MovieDVD") {
            MovieDVD* newMovieDVD = new MovieDVD();
            newMovieDVD->initalizeFromFile(ins);
            insertElement(newMovieDVD);
        }
    }
}

// Inserts a new product into the hash table, by first determining its key and pushing it into the list at that index.
void HashTable::insertElement(Product* item) {
    int index = hashFunction(item);
    bool itemFound = false;

    // If item already exists in the table, increments the number in stock of the product, but does not add a new element to the table.
    for (auto iter = table[index].begin(); iter != table[index].end(); iter++) {
        if ((*iter)->getTitle() == item->getTitle()) {
            (*iter)->setNumInStock((*iter)->getNumInStock() + 1);
            itemFound = true;
            break;
        }
    }
    
    if(!itemFound)
        table[index].push_back(item);
}

// Allows the user to add a new product into the hash table.
void HashTable::insertElement() {
    int userChoice;
    
    std::cout << "Enter what type of product you want to add..." << std::endl       // First the user is asked, to enter the desired product type.
        << "1 - Book" << std::endl
        << "2 - Newspaper" << std::endl
        << "3 - Magazine" << std::endl
        << "4 - Audiobook" << std::endl
        << "5 - AudioCD" << std::endl
        << "6 - MovieDVD" << std::endl
        << "0 - Cancel" << std::endl
        << "Enter your choice: ";
    std::cin >> userChoice;
    std::cin.ignore();
    std::cout << std::endl;

    if (userChoice > 6 || userChoice < 1) {                           // If the choice selected is 0 or invalid, return is called to exit the  
        return;                                                      // method.
    }
    else {
        std::string title;                              // If a valid option was selected, first attributes pertaining to the Product class
        double price;                                  // are received from the user.
        int numInStock;
        std::string language;
        
        std::cout << "Enter product title: ";
        std::getline(std::cin, title);
        
        std::cout << "Enter product price (numeric): ";
        std::cin >> price;

        std::cout << "Enter number in stock (numeric): ";
        std::cin >> numInStock;
        std::cin.ignore();                           // Input stream must be cleared in case '\n' characters are left in the line

        std::cout << "Enter language: ";
        std::getline(std::cin, language);

        if (userChoice >= 1 && userChoice <= 3) {          // If a PhysicalMedia product was chosen, attributes pertaining to the PhysicalMedia
            std::string publisher;                        // class are received from the user.
            int publishingYear;
            int numPages;

            std::cout << "Enter publisher name: ";
            std::getline(std::cin, publisher);

            std::cout << "Enter publishing year (numeric): ";
            std::cin >> publishingYear;

            std::cout << "Enter number of pages (numeric): ";
            std::cin >> numPages;
            std::cin.ignore();                          // Input stream must be cleared in case '\n' characters are left in the line

            if (userChoice == 1) {                      // If a Book product was chosen, attributes pertaining to the Book class are 
                std::string genre;                     // received from the user.
                std::string author;
                std::string bookType;

                std::cout << "Enter book genre: ";
                std::getline(std::cin, genre);

                std::cout << "Enter author: ";
                std::getline(std::cin, author);

                std::cout << "Enter book type: ";
                std::getline(std::cin, bookType);

                Book* newBook = new Book(title, price, numInStock, language, publisher, publishingYear, numPages, genre, author, bookType);
                insertElement(newBook);

            }
            else if (userChoice == 2) {              // If a Newspaper product was chosen, attributes pertaining to the Newspaper class are 
                std::string date;                   // received from the user.
                std::string mainArticleTitle;

                std::cout << "Enter date: ";
                std::getline(std::cin, date);

                std::cout << "Enter main article title: ";
                std::getline(std::cin, mainArticleTitle);

                Newspaper* newNewspaper = new Newspaper(title, price, numInStock, language, publisher, publishingYear, numPages, date, mainArticleTitle);
                insertElement(newNewspaper);
            }
            else {                                  // If a Magazine product was chosen, attributes pertaining to the Magazine class are
                std::string magazineType;          // received from the user.
                
                std::cout << "Enter magazine type: ";
                std::getline(std::cin, magazineType);

                Magazine* newMagazine = new Magazine(title, price, numInStock, language, publisher, publishingYear, numPages, magazineType);
                insertElement(newMagazine);
            }
        }
        else {                                   // If a DigitalMedia product was chosen, attributes pertaining to the DigitalMedia
            std::string releaseDate;            // class are received from the user.
            std::string genre;
            char isElectronicCh;
            bool isElectronic;

            std::cout << "Enter release date: ";
            std::getline(std::cin, releaseDate);

            std::cout << "Enter genre: ";
            std::getline(std::cin, genre);

            std::cout << "Enter if the product is electronic or not (y/n): ";
            std::cin >> isElectronicCh;
            // string input must be translated into a boolean (ternary operator is used).
            isElectronic = (isElectronicCh == 'y' || isElectronicCh == 'Y') ? true : false;

            if (userChoice == 4) {                 // If an Audiobook product was chosen, attributes pertaining to the Audiobook class are 
                std::string author;               // class are received from the user.
                double duration;
                std::string bookType;
                std::string reader;

                std::cout << "Enter author: ";
                std::cin.ignore();                  // Input stream must be cleared in case '\n' characters are left in the line
                std::getline(std::cin, author);

                std::cout << "Enter audiobook duration (in hours, numeric): ";
                std::cin >> duration;

                std::cout << "Enter book type: ";
                std::cin.ignore();                  // Input stream must be cleared in case '\n' characters are left in the line
                std::getline(std::cin, bookType);

                std::cout << "Enter audiobook reader: ";
                std::getline(std::cin, reader);

                Audiobook* newAudiobook = new Audiobook(title, price, numInStock, language, genre, releaseDate, isElectronic, author,
                    duration, bookType, reader);
                insertElement(newAudiobook);
            }
            else if (userChoice == 5) {             // If an AudioCD product was chosen, attributes pertaining to the AudioCD class are 
                std::string musician;              // class are received from the user.
                double runtime;
                std::vector<std::string> trackList;

                std::cout << "Enter musician name: ";
                std::cin.ignore();                  // Input stream must be cleared in case '\n' characters are left in the line
                std::getline(std::cin, musician);

                std::cout << "Enter runtime (in hours, numeric): ";
                std::cin >> runtime;

                std::string newInput;
                std::cout << "Enter new track or leave blank to stop: ";
                std::cin.ignore();                          // Input stream must be cleared in case '\n' characters are left in the line
                std::getline(std::cin, newInput);
                while (newInput != "") {
                    trackList.push_back(newInput);
                    std::cout << "Enter new track or leave blank to stop: ";
                    std::getline(std::cin, newInput);
                }

                AudioCD* newAudioCD = new AudioCD(title, price, numInStock, language, genre, releaseDate, isElectronic, musician,
                    runtime, trackList);
                insertElement(newAudioCD);
            }
            else {                                  // If an MovieDVD product was chosen, attributes pertaining to the MovieDVD class are 
                double duration;                   // class are received from the user.
                std::vector<std::string> mainCast;

                std::cout << "Enter duration (in hours, numeric): ";
                std::cin >> duration;

                std::string newInput;
                std::cout << "Enter new actor from main cast or leave blank to stop: ";
                std::cin.ignore();                  // Input stream must be cleared in case '\n' characters are left in the line
                std::getline(std::cin, newInput);
                while (newInput != "") {
                    mainCast.push_back(newInput);
                    std::cout << "Enter new actor from main cast or leave blank to stop: ";
                    std::getline(std::cin, newInput);
                }

                MovieDVD* newMovieDVD = new MovieDVD(title, price, numInStock, language, genre, releaseDate, isElectronic, duration, mainCast);
                insertElement(newMovieDVD);
            }
        }
    }

}

// Deletes an item with the specified title from the hash table.
void HashTable::deleteElement(const std::string& title) {
    int index = hashFunction(title);
    auto iter = searchByFullTitle(title);

    if (iter != table[index].end())
        table[index].erase(iter);
}

// Allows the user to modify attributes of an item with a specified title.
void HashTable::modifyElement(const std::string& title) {
    auto iter = searchByFullTitle(title);
    int index = hashFunction(title);

    if (iter == table[index].end()) {           // If the element is not found in the hash table.
        return;
    }

    int userChoice;

    std::cout << std::endl;
    std::cout << "Please choose which attribute to modify!" << std::endl;
    (*iter)->printChangeableAttributes();
    std::cout << "Enter your choice (or 0 to cancel): ";
    std::cin >> userChoice;
    std::cout << std::endl;


    if (userChoice == 0) {
        return;
    }
    else if (userChoice == 1) {                 // If the user changes the title of the product, it must be temporarily removed
        Product* tempPtr = *iter;              // from the hash table and re-inserted as the title is used to calculate its key.
        iter = table[index].erase(iter);
        tempPtr->changeAttribute(1);
        this->insertElement(tempPtr);
    }
    else if (userChoice > 1 && userChoice < 12) {
        (*iter)->changeAttribute(userChoice);
    }
    else {
        std::cerr << "Invalid choice." << std::endl;
    }
}

// Returns an integer key for the specified product (using its title to determine the hash).
int HashTable::hashFunction(Product* prod) {
    return hashFunction(prod->getTitle());
}

int HashTable::hashFunction(const std::string& title) {
    return hash(title) % buckets;
}

// Hash returns an integer hash key for the specified string.
unsigned long HashTable::hash(const std::string& title) {
    unsigned long hash = 5;
    for (int i = 0; i < title.size(); i++) {
        hash = hash * 31 + title[i];
    }

    return hash;
}

// Prints the description of a product with the specified title.
void HashTable::printElement(const std::string& title) {
    int index = hashFunction(title);
    auto iter = searchByFullTitle(title);

    if (iter == table[index].end()) {
        return;
    }

    std::cout << (*iter)->getDescription();
}

// Prints the descriptions of all elements in the hash table.
void HashTable::printTable() {
    for (int i = 0; i < buckets; i++) {
        auto iter = table[i].begin();

        for (; iter != table[i].end(); iter++) {
            std::cout << (*iter)->getDescription() << std::endl << std::endl;

        }
    }
}

// Outputs product data of all items in the hash table to an external file (in a format readable by the program).
void HashTable::outputToFile(std::ofstream& outs) {
    for (int i = 0; i < buckets; i++) {
        auto iter = table[i].begin();

        for (; iter != table[i].end(); iter++) {
            (*iter)->outputToFile(outs);

        }
    }
}

// Searches the hash table for a product with the specified title.
std::list<Product*>::iterator HashTable::searchByFullTitle(const std::string& title) {
    int index = hashFunction(title);

    auto iter = table[index].begin();
    for (; iter != table[index].end(); iter++) {
        if ((*iter)->getTitle() == title) {
            std::cout << "The element you wanted to search is present in the inventory." << std::endl;
            return iter;
        }
    }

    if (iter == table[index].end())
        std::cout << "Element not present in the inventory." << std::endl;

    return iter;
}

// Searches the hash table for products containing a certain keyword in their titles.
std::vector<const Product*> HashTable::searchKeywordInTitle(std::string& keyword) {
    std::vector<const Product*> searchResults;

    for (int i = 0; i < buckets; i++) {                                    // The outer for-loop iterates through all buckets of the hash table.
        for (auto iter = table[i].begin(); iter != table[i].end(); iter++) {    // The inner loop iterates through all items in the linked lists
            if (*iter != nullptr) {                                              // at each index. If an item is present, its title is searched for
                std::string title = (*iter)->getTitle();                          // the keyword.
                StringMatcher patternFinder(title, keyword);
                if (patternFinder.init() > 0)                             // The init() method of the StringMatcher class automatically returns the
                    searchResults.push_back(*iter);                      // index of the first match in the text or -1 if no matches are found.
            }
        }
    }

    if (searchResults.empty())
        std::cerr << "No elements found with that keyword." << std::endl;

    return searchResults;
}

// Searches the hash table for products containing a certain keyword in their descriptions.
std::vector<const Product*> HashTable::searchDescription(std::string& keyword) {
    std::vector<const Product*> searchResults;

    for (int i = 0; i < buckets; i++) {                                    // The outer for-loop iterates through all buckets of the hash table.
        for (auto iter = table[i].begin(); iter != table[i].end(); iter++) {    // The inner loop iterates through all items in the linked lists
            if (*iter != nullptr) {                                              // at each index. If an item is present, its description is 
                std::string title = (*iter)->getDescription();                    // searched for the keyword.
                StringMatcher patternFinder(title, keyword);
                if (patternFinder.init() > 0)                             // The init() method of the StringMatcher class automatically returns the
                    searchResults.push_back(*iter);                      // index of the first match in the text or -1 if no matches are found.
            }
        }
    }

    if (searchResults.empty())
        std::cerr << "No elements found with that keyword." << std::endl;

    return searchResults;
}

// Destructor for HashTable objects - required since we are heap-allocating space for the table array and we are creating
// elements with new operator
HashTable::~HashTable() {
    for (int i = 0; i < buckets; i++) {
        for (auto iter = table[i].begin(); iter != table[i].end(); iter++) {
            delete* iter;
            iter = table[i].erase(iter);
            if (iter == table[i].end())
                break;
        }
    }

    delete[] table;
}