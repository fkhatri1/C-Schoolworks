#include "linearhash.hpp"

LinearHashTable::LinearHashTable(int slots, float a) {
	p = slots;
	alpha = a;
	lastProbePath = "";
	table = new LinkedNode*[p];	
	for (int ii=0; ii<p; ii++)
		table[ii] = nullptr;  //initialize pointers to null
	
	/*
	 *NOTES:
	 *I should have used a vector or simple array to implement the Linear Hash table.
	 *I could have avoided using pointers all together that way. Instead I reused what I built for the Chained table.
	 *I had already finished coding the Linear Hash class before I realized it.
	 *I used a vector for the Double Hash.
	 */
}

LinearHashTable::~LinearHashTable() {
	delete[] table;
}

void LinearHashTable::LinearHashInsert(int element) {
	LinkedNode* newElement = new LinkedNode(element);
	float alphaElement = alpha * element;
	alphaElement = alphaElement - std::floor(alphaElement); //had to hack the (mod 1) behavior because % operator only accepts ints
	int hashKey = std::floor(p * alphaElement);
	int start = hashKey;
	
	if (table[hashKey] == nullptr) {
		table[hashKey] = newElement;  //if slot empty, place new element in slot
	}
	else {
		while (table[hashKey] != nullptr) {
			hashKey++; //keeps looking until empty slot or end of table
			if (hashKey == start) {
				std::cout << "ERROR: Linear Hash Table Overflow. Could not insert " << element << "!" << std::endl;
				return;
			}
			if (hashKey == p) {
				hashKey = 0; //wrap around
			}
		}
		table[hashKey] = newElement; //slot empty, place new element in slot
	}
}

int LinearHashTable::LinearHashSearch(int target) {
	float alphaTarget = alpha * target;
	alphaTarget = alphaTarget - std::floor(alphaTarget); //had to hack the (mod 1) behavior because % operator only accepts ints
	int hashKey = std::floor(p * alphaTarget);
	int start = hashKey;
	lastProbePath = "";
	if (table[hashKey] == nullptr) {
		return -1;
	}
	else {
		while ( (table[hashKey] != nullptr) && (hashKey < p) ) {
			lastProbePath = lastProbePath + " " + std::to_string(hashKey);
			if ( (*table[hashKey]).getKey() == target ) {
				return hashKey;
			} else 
			{
				hashKey++; //keeps looking until empty slot or end of table
				if (hashKey == start) {
					std::cout << "Searched entire table." << std::endl;
					return -1;
				}
				if (hashKey == p) {
					hashKey = 0; //wrap around
				}
			}
		}
	}
	return -1;
}

void LinearHashTable::print() {
	using std::cout;
	using std::endl;
	
	std::ofstream ofs;
    ofs.open ("linear-output.txt", std::ofstream::out);
	
	for (int ii=0; ii<p; ii++) {
		if (ii < 10) {
			cout << " ";
			ofs << " ";
		}
		
		cout << ii << ":\t\t";
		ofs << ii << ":\t\t";
		
		if (table[ii] != nullptr) {
			LinkedNode* curr = table[ii];
			cout << (*curr).getKey();
			ofs << (*curr).getKey();
		}

	cout << endl;
	ofs << endl;
	} 
	cout << endl;
}

string LinearHashTable::getLastProbePath() {
	return lastProbePath;
}