#include <iostream>
#include "HashFunction.h"

using namespace std;


int main() {
    int tableSize = 10;  // Set hash table size
    HashTable hashTable(tableSize);

    // Sample inputs
    string input1 = "Charles";
    string input2 = "Carol";
    string input3 = "David";
    string input4 = "Smith";
    string input5 = "Christopher";
    string input6 = "Sabrina";
    string input7 = "Carolyn";
    string input8 = "Jesse";
    string input9 = "Whipple";
    string input10 = "Woods";

    // Inserting strings into the hash table
    hashTable.insert(input1);
    hashTable.insert(input2);
    hashTable.insert(input3);
    hashTable.insert(input4);
    hashTable.insert(input5);
    hashTable.insert(input6);
    hashTable.insert(input7);
    hashTable.insert(input8);
    hashTable.insert(input9);
    hashTable.insert(input10);

    // Display the contents of the hash table
    hashTable.display();

    // Retrieve a value from the hash table
    cout << "Retrieved value for 'Charles': " << hashTable.get("Charles") << endl;
    cout << "Retrieved value for 'Carol': " << hashTable.get("Carol") << endl;
    cout << "Retrieved value for 'Christopher': " << hashTable.get("Christopher") << endl;

    return 0;
}