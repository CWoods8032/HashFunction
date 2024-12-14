#include <string>
#include <vector>
#include <list>

using namespace std;

class HashTable {
private:
    vector<list<string>> table;  // The hash table as a vector of linked lists
    int tableSize;               // Size of the hash table

    // Hash function to compute the index for a string
    unsigned int hashFunction(const string& input, int tableSize);

public:
    // Constructor to initialize the hash table with a given size
    HashTable(int size);

    // Method to insert a string into the hash table
    void insert(const string& value);

    // Method to retrieve a string from the hash table
    string get(const string& value);

    // Method to display the hash table contents
    void display();
};


