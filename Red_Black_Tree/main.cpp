/*
 *Faysal Khatri  1213830616  HW5
 *main.cpp
 */
 
#include <fstream>
#include <string>
#include "rbnode.hpp"
#include "rbtree.hpp"


using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;



int main(int argc, const char * argv[]) { 
	
	if (argc>1) { 
		RBTree * T = new RBTree();
		T->RBRead(argv[1]);
		
		
		int ii;
		for (ii=0; ii<T->C; ii++) {
			T->RBInsert( *(T->insertKeys + ii) );
			T->RBWrite();
		}
		cout << "Complete. Output printed to output.txt" << endl;
	}
	else {
		cout << "No input text file provided." << endl;
	}
}
