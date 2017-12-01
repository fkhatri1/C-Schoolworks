#ifndef CHAINED_HASH
#define CHAINED_HASH
#include <iostream>
#include <fstream>
#include "linkednode.hpp"


class ChainedHashTable {
	private:
		LinkedNode** table;
		int p; //number of slots
		
	public:
		ChainedHashTable(int);
		~ChainedHashTable();
		void ChainedHashInsert(int);
		int ChainedHashSearch(int);
		void print();
};
		


#endif