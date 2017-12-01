#include "doublehash.hpp"

DoubleHashTable::DoubleHashTable(int num) {
	p = num;
	table.reserve(p);
	for (int ii=0; ii<p; ii++) {
		table.push_back(-1); //set all elements to -1 to indicate empty.
	}
}

DoubleHashTable::~DoubleHashTable() {
}

void DoubleHashTable::DoubleHashInsert(int element) {
	int hashKey = element % p;
	int i = 0; //hash probing counter
	

	while (table.at(hashKey) != -1) {
		i++;
		hashKey = ( ( (element % p) + (i * (1 + (element % (p-2))) ) ) % p); //keeps looking until empty slot or end of table
		if (i == p) {
			std::cout << "ERROR: Linear Hash Table Overflow. Could not insert " << element << "!" << std::endl;
			return;
		}

	}
	std::cout << "Attempting to place element: " << element << " in slot " << hashKey << std::endl;
	table.at(hashKey) = element; //slot empty, place new element in slot
}

int DoubleHashTable::DoubleHashSearch(int target) {
	int hashKey = target % p;
	int i = 0; //hash probing counter
	
	lastProbePath = std::to_string(hashKey);
	while (table.at(hashKey) != target )  {
		i++;
		hashKey = ( ( (target % p) + (i * (1 + (target % (p-2))) ) ) % p);
		lastProbePath = lastProbePath + " " + std::to_string(hashKey);
		if (i == p) {
			std::cout << "Searched entire table." << std::endl;
			return -1;
		}
	}
	return hashKey;
}


void DoubleHashTable::print() {
	using std::cout;
	using std::endl;
	
	std::ofstream ofs;
    ofs.open ("double-output.txt", std::ofstream::out);
	
	for (int ii=0; ii<p; ii++) {
		if (ii < 10) {
			cout << " ";
			ofs << " ";
		}
		
		cout << ii << ":\t\t";
		ofs << ii << ":\t\t";
		
		if (table.at(ii) != -1) {
			cout << table.at(ii);
			ofs << table.at(ii);
		}

	cout << endl;
	ofs << endl;
	} 
	cout << endl;
} 

string DoubleHashTable::getLastProbePath() {
	return lastProbePath;
}