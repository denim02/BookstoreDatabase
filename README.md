# BookstoreDatabase
This program was created as the final project for the Fundamental Data Structures course.

## Description
This program is a very basic implementation of a database which allows the user to insert, remove and modify various products. In addition, the user can search for products based on certain keywords and can choose to save the search results, or any modifications made to the database itself.

## Evaluation of algorithms and data structures used
A hash table is used to store all objects created. The title for each product is passed through a hash function to produce a key. 
Linked list collision resolution was chosen for the hash table as the number of elements the table will hold is unknown, since users can add as many elements as they want. If linear probing was used, the whole hash table would have to be resized and rehashed if the number of elements exceeded the number of buckets. With linked lists, you can always add more elements into the hash table (even though this might jeopardize the benefits of using a hash table). 

Insertion, deletion, and searching with the full title all need constant average time. In the worst case, if all n elements are mapped to the same bucket, a linked list with n elements would be created so it would take O(n) time for the previously mentioned operations.
Searching with other criteria besides the full title (with a keyword in the title or in the description) takes a significantly longer time as the constant average search time of the hash table does not apply. Loops iterate through all elements in O(n) time, and additional time is needed to execute the Boyer-Moore string matching algorithm.

If the user chooses to do so, the results of these searches can be sorted by product title (lexicographical order) or by price using either insertion sort or quick sort depending on the number of search results (insertion sort is used when there are less than 10 search results).
