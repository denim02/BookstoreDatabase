#pragma once
#include "HashTable.h"
// <list>, <vector>, <fstream>, <string>, "Product.h" included through "HashTable.h"

namespace DatabaseProgram {
    // Initializes the hash table with data from an external file.
    int init(HashTable& inventory);

    // Executes the main program loop which continuously queries the user for an operation to perform.
    int run(HashTable& inventory);

     // QueryHits struct is created to make the job of sorting the Product objects (based on their price or their title) 
    // cleaner, simpler and faster.
    struct QueryHits {
        const Product* prod;
        double price;
        std::string title;

        QueryHits(const Product* prod);
        QueryHits(const QueryHits& lhs);

        bool hasSmallerPrice(const QueryHits& lhs);

    };

    // Sorting methods are implemented to sort the results from a search in the database.
    void sort(std::vector<const Product*>& products, int sortCriteria);

    void insertionSortTitle(std::vector<QueryHits>& queryResults);
    void insertionSortPrice(std::vector<QueryHits>& queryResults);

    void quickSortTitle(std::vector<QueryHits>& queryResults, int low, int high);
    void quickSortPrice(std::vector<QueryHits>& queryResults, int low, int high);
}