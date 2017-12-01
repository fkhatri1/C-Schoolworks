#ifndef LINEAR
#define LINEAR
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include "linkednode.hpp"


using std::string;

class LinearHashTable {
	
	
	private:
		LinkedNode** table;
		int p; //number of slots
		float alpha; //hash function parameter
		string lastProbePath; //stores probe path for printing
	public:
		LinearHashTable(int, float);
		~LinearHashTable();
		void LinearHashInsert(int);
		int LinearHashSearch(int);
		void print();
		string getLastProbePath();
};
		


#endif