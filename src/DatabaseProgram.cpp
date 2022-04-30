#include <iostream>
#include <fstream>
#include "DatabaseProgram.h"
#include "Audiobook.h"
#include "Book.h"
#include "AudioCD.h"
#include "Newspaper.h"
#include "MovieDVD.h"
#include "Product.h"

// Initializes the bookstore inventory with the products stored in the input file.
int DatabaseProgram::init(HashTable& inventory) {
    std::cout << "Initializing inventory with data from txt input file..." << std::endl;

    std::ifstream ins;
    ins.open("input.txt");

    if (ins.fail()) {
        std::cerr << "Error opening initialization file. Opened inventory is empty." << std::endl;
        return -1;
    }

    inventory.initializeFromFile(ins);
    ins.close();
    return 0;
}

// Starts the main program loop which continuously queries the user to perform an operation on the database.
int DatabaseProgram::run(HashTable& inventory) {
    char userChoice;
    std::string productTitle;

    std::cout << std::endl;
    std::cout << "Possible operations:" << std::endl
        << "1 - Insert Element" << std::endl
        << "2 - Delete Element" << std::endl
        << "3 - Modify Element" << std::endl
        << "4 - Output table" << std::endl
        << "5 - Search" << std::endl
        << "0 - Quit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> userChoice;                     // Initialize the userChoice variable to be used as a flag for the while-loop
    std::cout << std::endl;

    while (userChoice != '0') {                 // While the user has not entered "Quit", they are continuously asked to specify an operation.
        // Insert Element
        if (userChoice == '1') {
            inventory.insertElement();
        }

        // Delete Element
        else if (userChoice == '2') {
            std::cout << "Enter title of product to be deleted (or leave blank to cancel): ";
            std::cin.ignore();                              // Input stream must be cleared in case '\n' characters are left in the line
            std::getline(std::cin, productTitle);
            std::cout << std::endl;

            if (productTitle != "") {
                inventory.deleteElement(productTitle);
            }
        }

        // Modify Element
        else if (userChoice == '3') {
            std::cout << "Enter title of product to be modified (or leave blank to cancel): ";
            std::cin.ignore();                             // Input stream must be cleared in case '\n' characters are left in the line
            std::getline(std::cin, productTitle);
            std::cout << std::endl;

            if (productTitle != "") {
                inventory.modifyElement(productTitle);

            }
        }

        // Print Table
        else if (userChoice == '4') {
            inventory.printTable();
        }

        // Search through Table
        else if (userChoice == '5') {
            int searchCriteria;
            std::string userInput;
            std::cout << "Search based on which criteria? " << std::endl              // User is asked to specify a searching criteria.
                << "1 - Search by full product title" << std::endl
                << "2 - Search by keyword in product title" << std::endl
                << "3 - Search by keyword in product description" << std::endl
                << "0 - Cancel operation" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> searchCriteria;
            std::cout << std::endl;

            // Search by full product title
            if (searchCriteria == 1) {
                std::cout << "Enter full product title (or leave blank to cancel): ";
                std::cin.ignore();                          // Input stream must be cleared in case '\n' characters are left in the line
                std::getline(std::cin, userInput);
                std::cout << std::endl;
                if (userInput != "") {
                    inventory.printElement(userInput);
                    std::cout << std::endl;
                }
            }

            // Search by keyword in product title or description
            else if (searchCriteria == 2 || searchCriteria == 3) {          // If searching with a keyword is chosen, a vector to store the many
                std::vector<const Product*> searchResults;                 // possible results must be created.
                
                // Search by keyword in product title
                if (searchCriteria == 2) {
                    std::cout << "Enter keyword in product title (or leave blank to cancel): ";
                    std::cin.ignore();                      // Input stream must be cleared in case '\n' characters are left in the line
                    std::getline(std::cin, userInput);
                    std::cout << std::endl;
                    if(userInput != "")
                        searchResults = inventory.searchKeywordInTitle(userInput);

                }

                // Search by keyword in product description
                else {
                    std::cout << "Enter keyword in product description (or leave blank to cancel): ";
                    std::cin.ignore();                      // Input stream must be cleared in case '\n' characters are left in the line
                    std::getline(std::cin, userInput);
                    std::cout << std::endl;
                    if(userInput != "")
                        searchResults = inventory.searchDescription(userInput);
                }

                if (!searchResults.empty()) {              // If results with the specified keyword were found, the user is asked whether
                    int sortCriteria;                     // they want the results sorted or not (and which sorting criteria to use).
                    
                    std::cout << "Select sorting critera for outputting results of search:" << std::endl
                        << "1 - Alphabetical Sort" << std::endl
                        << "2 - Sorted by Price" << std::endl
                        << "0 - Unsorted" << std::endl
                        << "Enter your choice: ";
                    std::cin >> sortCriteria;
                    std::cout << std::endl;

                    if (sortCriteria == 1 || sortCriteria == 2)
                        sort(searchResults, sortCriteria);
                    else
                        std::cout << "Results will be outputted unsorted." << std::endl;

                    for (int i = 0; i < searchResults.size(); i++) {                         // Search results are printed out.
                        std::cout << searchResults[i]->getDescription() << std::endl << std::endl;
                    }

                    std::cout << "Do you want to save results to an external file? (y/n): ";    // The user is asked if they want to
                    std::cin >> userChoice;                                                    // store the search results in an external file.

                    if (userChoice == 'y' || userChoice == 'Y') {
                        std::string fileName;
                        std::cout << "Enter output txt file name (add .txt to the end): ";
                        std::cin >> fileName;
                        std::cout << std::endl;

                        std::ofstream outSearch;
                        outSearch.open(fileName);
                        
                        for (int i = 0; i < searchResults.size(); i++)
                            searchResults[i]->outputToFile(outSearch);

                        outSearch.close();
                    }
                }
            }
        }

        else {              // If the user enters an invalid choice, the program exits out.
            std::cerr << "Invalid choice. Program exiting." << std::endl;
            return -1;
        }

        // After processing the current operation, the user is queried again to choose another operation.
        std::cout << std::endl;
        std::cout << "Possible operations:" << std::endl
            << "1 - Insert Element" << std::endl
            << "2 - Delete Element" << std::endl
            << "3 - Modify Element" << std::endl
            << "4 - Output table" << std::endl
            << "5 - Search" << std::endl
            << "0 - Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> userChoice;
        std::cout << std::endl;
    }

    // If the user selects quit, they are asked whether they want to save the changes made to the database.
    std::cout << "Do you want to save changes made to the database? (y/n): ";
    std::cin >> userChoice;

    if (userChoice == 'y' || userChoice == 'Y') {
        std::ofstream outs;
        outs.open("input.txt");
        inventory.outputToFile(outs);
        outs.close();
    }
    return 0;
}

// Constructor for QueryHits struct (used in sorting functions)
DatabaseProgram::QueryHits::QueryHits(const Product* prod)
    : prod(prod), price(prod->getPrice()), title(prod->getTitle()) {}

DatabaseProgram::QueryHits::QueryHits(const QueryHits& lhs)
    : prod(lhs.prod), price(lhs.price), title(lhs.title) {}

bool DatabaseProgram::QueryHits::hasSmallerPrice(const QueryHits& lhs) {
    if (this->price < lhs.price)
        return true;
    else
        return false;
}

void DatabaseProgram::sort(std::vector<const Product*>& products, int sortCriteria) {
    if (!products.empty()) {
        std::vector<QueryHits> queryResults;

        for (int i = 0; i < products.size(); i++)
            queryResults.push_back(QueryHits(products[i]));

        if (sortCriteria == 1)
            quickSortTitle(queryResults, 0, queryResults.size() - 1);
        else
            quickSortPrice(queryResults, 0, queryResults.size() - 1);
        
        for (int i = 0; i < products.size(); i++) {
            products[i] = queryResults[i].prod;
        }
    }
}

void DatabaseProgram::insertionSortTitle(std::vector<QueryHits>& queryResults) {
    for (int i = 0; i < queryResults.size(); i++) {
        QueryHits tmp = queryResults[i];
        int j;

        for (j = i; j > 0 && tmp.title < queryResults[j - 1].title; j--)
            queryResults[j] = queryResults[j - 1];
        queryResults[j] = tmp;
    }
}

void DatabaseProgram::insertionSortPrice(std::vector<QueryHits>& queryResults) {
    for (int i = 0; i < queryResults.size(); i++) {
        QueryHits tmp = queryResults[i];
        int j;

        for (j = i; j > 0 && tmp.hasSmallerPrice(queryResults[j - 1]); j--)
            queryResults[j] = queryResults[j - 1];
        queryResults[j] = tmp;
    }
}

void DatabaseProgram::quickSortTitle(std::vector<QueryHits>& queryResults, int low, int high) {
    int middle = (low + high) / 2;

    if (queryResults[middle].title < queryResults[low].title)
        std::swap(queryResults[middle], queryResults[low]);

    if (queryResults[low].title > queryResults[high].title)
        std::swap(queryResults[low], queryResults[high]);

    if (queryResults[high].title < queryResults[middle].title)
        std::swap(queryResults[high], queryResults[middle]);

    QueryHits pivot = queryResults[middle];

    if (low < high - 1) {

        std::swap(queryResults[middle], queryResults[high - 1]);
        int i, j;

        for (i = low, j = high - 1; ;) {

            while (queryResults[++i].title < pivot.title) {}
            while (queryResults[--j].title > pivot.title) {}

            if (i < j)
                std::swap(queryResults[i], queryResults[j]);
            else
                break;
        }

        std::swap(queryResults[i], queryResults[high - 1]);

        quickSortTitle(queryResults, low, i - 1);
        quickSortTitle(queryResults, i + 1, high);
    }
}

void DatabaseProgram::quickSortPrice(std::vector<QueryHits>& queryResults, int low, int high) {
    int middle = (low + high) / 2;

    if (queryResults[middle].hasSmallerPrice(queryResults[low]))
        std::swap(queryResults[middle], queryResults[low]);

    if (queryResults[high].hasSmallerPrice(queryResults[low]))
        std::swap(queryResults[low], queryResults[high]);

    if (queryResults[high].hasSmallerPrice(queryResults[middle]))
        std::swap(queryResults[high], queryResults[middle]);

    QueryHits pivot = queryResults[middle];

    if (low < high - 1) {

        std::swap(queryResults[middle], queryResults[high - 1]);
        int i, j;

        for (i = low, j = high - 1; ;) {

            while (queryResults[++i].hasSmallerPrice(pivot)) {}
            while (pivot.hasSmallerPrice(queryResults[--j])) {}

            if (i < j)
                std::swap(queryResults[i], queryResults[j]);
            else
                break;
        }

        std::swap(queryResults[i], queryResults[high - 1]);

        quickSortPrice(queryResults, low, i - 1);
        quickSortPrice(queryResults, i + 1, high);
    }
}