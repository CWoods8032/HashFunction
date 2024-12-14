#include "HashFunction.h"
#include <iostream>

using namespace std;

// Constructor to initialize the hash table with a given size
HashTable::HashTable(int size) {
    tableSize = size;
    table.resize(tableSize);  // Resize the table to the given size
}

// Hash function to compute the index for a string
unsigned int HashTable::hashFunction(const string& input, int tableSize) {
    unsigned int hashValue = 0;

    // Loop through each character in the string
    for (char c : input) {
        hashValue += c;  // Add the ASCII value of the character to the hash
    }

    // Return the hash value modulo the table size to get a valid index
    return hashValue % tableSize;
}

// Method to insert a string into the hash table
void HashTable::insert(const string& value) {
    unsigned int index = hashFunction(value, tableSize);
    table[index].push_back(value);  // Insert at the computed index
    cout << "Inserted \"" << value << "\" at index " << index << endl;
}

// Method to retrieve a string from the hash table
string HashTable::get(const string& value) {
    unsigned int index = hashFunction(value, tableSize);

    // Search through the linked list at the given index
    for (const string& str : table[index]) {
        if (str == value) {
            return str;
        }
    }
    return "Not found";  // Return a default message if the value is not found
}

// Method to display the hash table contents
void HashTable::display() {
    cout << "Hash Table contents:" << endl;
    for (int i = 0; i < tableSize; i++) {
        cout << "Index " << i << ": ";
        if (table[i].empty()) {
            cout << "Empty";
        }
        else {
            for (const string& str : table[i]) {
                cout << str << " -> ";
            }
        }
        cout << endl;
    }
}