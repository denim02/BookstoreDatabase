/* 
* Course Project - Bookstore Database
* COS 221a - Fundamental Data Structures
* Programmer: Deni Mastori
* 
* Description: This program allows the user to insert, remove and modify various products from a database. In addition,
* the user can search for products based on certain keywords and can choose to save the search results, or any modifications
* made to the database itself.
*/

#include <iostream>
#include "HashTable.h"
#include "DatabaseProgram.h"

int main() {
    HashTable inventory(51);

    DatabaseProgram::init(inventory);
    DatabaseProgram::run(inventory);
}