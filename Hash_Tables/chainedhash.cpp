#include "chainedhash.hpp"

ChainedHashTable::ChainedHashTable(int slots) {
	p = slots;
	table = new LinkedNode*[p];
	for (int ii=0; ii<p; ii++)
		table[ii] = nullptr;  //initialize pointers to null
}

ChainedHashTable::~ChainedHashTable() {
	delete[] table;
}

void ChainedHashTable::ChainedHashInsert(int element) {
	LinkedNode* newElement = new LinkedNode(element);
	int hashKey = element % p;
	if (table[hashKey] == nullptr) {
		table[hashKey] = newElement;  //if slot empty, place new element in slot
	}
	else {
		newElement->setNext(table[hashKey]); 	//if collision, chain existing element(s) to
		table[hashKey] = newElement;			//	new element and place into slot
	}
}

int ChainedHashTable::ChainedHashSearch(int target) {
	int hashKey = target % p;
	if (table[hashKey] == nullptr) {
		return -1;  //if slot empty, target element does not exist in table
	}
	else {
		LinkedNode* curr = table[hashKey];
		while (curr > nullptr) {
			if ( (*curr).getKey() == target )
				return hashKey;
			curr = (*curr).getNext();
		}
	}
	return -1;
}

void ChainedHashTable::print() {
	using std::cout;
	using std::endl;
	std::ofstream ofs;
    ofs.open ("chained-output.txt", std::ofstream::out);
	
	for (int ii=0; ii<p; ii++) {
		if (ii < 10) {
			cout << " ";
			ofs << " ";
		}
		
		cout << ii << ":\t\t";
		ofs << ii << ":\t\t";
		
		if (table[ii] != nullptr) {
			LinkedNode* curr = table[ii];
			while (curr > nullptr) {
				cout << (*curr).getKey() << " ";
				ofs << (*curr).getKey() << " ";
				curr = (*curr).getNext();
			}
		}

		cout << endl;
		ofs << endl;
	}
}
