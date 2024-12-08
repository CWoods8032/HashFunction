#include <iostream>
#include <string>
#include <algorithm> // For Reverse

using namespace std; // Apply namespace std

// HashGenerator class
class HashGenerator {
private:
	// Encapsulation

	// Internal method for hashing
	unsigned long computeHash(const string& text) const {
		unsigned long hashValue = 5381; // Initialize with a seed value
		for (char c : text) {
			hashValue = ((hashValue << 5) + hashValue) + c; // hashValue * 33 + c
		}
		return hashValue; // Final computed hash value
	}

	// Converts a numeric hash value to a hexadecimal string
	string toHex(unsigned long hashValue) const {
		string hashHex;
		while (hashValue > 0) {
			int remainder = hashValue % 16;
			if (remainder < 10) {
				hashHex += (remainder + '0'); // Convert to numeric characters
			}
			else {
				hashHex += (remainder - 10 + 'a'); // Convert to alphabetic characters
			}
			hashValue /= 16; // Divide by 16 for the next digit
		}
		// Reverse the string to get the correct hexadecimal representation
		reverse(hashHex.begin(), hashHex.end());
		return hashHex.empty() ? "0" : hashHex; // Return "0" if input is empty
	}

public:
	// Abstraction

	// Public method to generate hash
	string generateHash(const string& text) const {
		unsigned long hashValue = computeHash(text); // Compute numeric hash
		return toHex(hashValue); // Convert it to a hexadecimal representation
	}
};

// Main program
int main() {
	// Modularity

	// Create an object of HashGenerator
	HashGenerator hasher;

	// Input plain text
	string plainText;
	cout << "Enter plain text: ";
	getline(cin, plainText);

	// Generate hash using the HashGenerator class
	string hashedText = hasher.generateHash(plainText);

	// Output the hashed text
	cout << "Hashed Text: " << hashedText << endl;

	return 0;
}