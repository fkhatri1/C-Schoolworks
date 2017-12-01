/*
 *Faysal Khatri  1213830616  HW5
 *rbtree.hpp
 */
#ifndef RBTREE
#define RBTREE
#include "rbnode.hpp"
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::endl;

class RBTree {
	public:
		RBNode * root;
		RBNode * nil;
		int * preOrderKeys;
		int * preOrderColors;
		int * insertKeys;
		int N;
		int C;
		RBTree();
		~RBTree();
		void RBInsert(int);
		void RBRead(string);
		void RBWrite();
		void RBPreorderOut(RBNode *, std::ofstream &);
		RBNode * preOrderConstruct(int preIndex, int min, int max, int size);
		
	private:
		void RBInsertFixUp(RBNode *);
		void LeftRotation(RBNode *);
		void RightRotation(RBNode *);
};



#endif