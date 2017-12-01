/*
 *Faysal Khatri  1213830616  HW4
 *I created classes for Chained, Linear and Double hash tables.
 *The classes implement the hashing rules required by this assignment and provide insert and search methods.
 *This main method reads the input file and uses the 3 classes the hash the keys and search for the target k1.
 *Results are printed to the screen and to these output files:
 *	chained-output.txt
 *	linear-output.txt
 *	double-output.txt
 */
 
#include <fstream>
#include <string>
#include "linkednode.hpp"
#include "chainedhash.hpp"
#include "linearhash.hpp"
#include "doublehash.hpp"


using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stoi;
using std::stof;

//declaring global variables and methods
int p;
float alpha;
int n;
int k1;
int* keys;
bool readData(string);


int main(int argc, const char * argv[]) { 
	
	if( (argc>1) && (readData(argv[1])) ) {
	
		/*
		 *	Instantiate a Chained Hash Table
		 * 	Add keys to the chained hash table
		 *	print table
		 *  search for target key
		 */
			ChainedHashTable myChainedTable(p);
			cout << "--Building Chained Hash Table--" << endl;
			
			for (int ii=0; ii<n; ii++) {
				myChainedTable.ChainedHashInsert(keys[ii]);
			}

			myChainedTable.print();
			
			cout << endl << "--Searching for k1 (" << k1 << ") in Chained Hash Table--" << endl;
			std::ofstream ofs;
			ofs.open("chained-output.txt", std::ofstream::app);
			int k1_slot = myChainedTable.ChainedHashSearch(k1);
			if (k1_slot > -1) {
				cout << "k1 was found in slot " << k1_slot << "!" << endl;
				ofs << k1_slot;
			} else {
				cout << "k1 was not found in the table!" << endl;
				ofs << "k1 was not found in the table!" << endl;
			}
			cout << "Chained Hashing Results printed to chained-output.txt." << endl;
			ofs.close();
			
		/*
		 *	Instantiate a Linear Hash Table
		 * 	Add keys to the linear hash table
		 *	print table
		 *  search for target key
		 */
			LinearHashTable myLinearTable(p, alpha);
			cout << endl << endl << "--Building Linear Hash Table--" << endl;
			
			for (int ii=0; ii<n; ii++) {
				myLinearTable.LinearHashInsert(keys[ii]);
			}
		
			myLinearTable.print();
			
			cout << endl << "--Searching for k1 (" << k1 << ") in Linear Hash Table--" << endl;
			ofs.open("linear-output.txt", std::ofstream::app);
			k1_slot = myLinearTable.LinearHashSearch(k1);
			cout << myLinearTable.getLastProbePath() << endl;
			ofs << myLinearTable.getLastProbePath() << endl;
			
			if (k1_slot > -1) {
				cout << "k1 was found in slot " << k1_slot << "!" << endl;
			} else {
				cout << "k1 was not found in the table!" << endl;
			}
			cout << "Linear Hashing Results printed to linear-output.txt." << endl;
			ofs.close();
			
		/*
		 *	Instantiate a Double Hash Table
		 * 	Add keys to the dinear hash table
		 *	print table
		 *  search for target key
		 */
			DoubleHashTable myDoubleTable(p);
			cout << endl << endl << "--Building Double Hash Table--" << endl;
			
			for (int ii=0; ii<n; ii++) {
				myDoubleTable.DoubleHashInsert(keys[ii]);
			}
		
			myDoubleTable.print();
			
			cout << endl << "--Searching for k1 (" << k1 << ") in Double Hash Table--" << endl;
			ofs.open("double-output.txt", std::ofstream::app);
			k1_slot = myDoubleTable.DoubleHashSearch(k1);
			ofs << myDoubleTable.getLastProbePath() << endl;
			cout << myDoubleTable.getLastProbePath() << endl;
			
			
			if (k1_slot > -1) {
				cout << "k1 was found in slot " << k1_slot << "!" << endl;
			} else {
				cout << "k1 was not found in the table!" << endl;
			}
			cout << "Double Hashing Results printed to double-output.txt." << endl;
	}
	else {
		cout << "ERROR: Cannot proceed without input file." << endl;
	}
	
	delete[] keys;
	keys = nullptr;
	return 0;
}

	

bool readData(string file) {
	bool ret = false;
	
	//Declaring input stream
    ifstream inFile;
	inFile.open(file);
	
	if (inFile) {  
		ret = true;
		cout << "Input file opened successfully!" << endl << endl;
		string buffer;
		std::getline(inFile, buffer);	p = stoi(buffer);
		std::getline(inFile, buffer);	alpha = stof(buffer);
		std::getline(inFile, buffer);	n = stoi(buffer);
		
		keys = new int[n];
				
		for (int ii=0; ii<n; ii++) {
			std::getline(inFile, buffer);
			keys[ii] = stoi(buffer);
		}
		
		std::getline(inFile, buffer);	k1 = stoi(buffer);
		
		cout << "*****WORKING PARAMETERS*****" << endl;
		cout << "p: " << p;
		cout << "  alpha: " << alpha;
		cout << "  n: " << n;
		cout << "  k1: " << k1 << endl << endl;
		cout << "*****KEYS*****" << endl;
		for (int ii=0; ii<n; ii++) {
			cout << keys[ii] << " ";
		}
		cout << endl << endl;
	}		
	else {
		ret = false;
		cout << "Failed to open input file." << endl;
	}
	return ret;
}