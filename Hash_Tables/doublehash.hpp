#ifndef DOUBLE
#define DOUBLE

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>

using std::string;

class DoubleHashTable {
	private: 
		int p;
		string lastProbePath;
		std::vector<int> table;
	public:
		DoubleHashTable(int);
		~DoubleHashTable();
		void DoubleHashInsert(int);
		int DoubleHashSearch(int);
		void print();
		string getLastProbePath();
	
};

#endif