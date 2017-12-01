/*
 *Faysal Khatri  1213830616  HW5
 *rbtree.cpp
 */
#include "rbtree.hpp"

RBTree::RBTree() {
	nil = new RBNode();
	nil->c = BLACK;
	root = nil;
}
RBTree::~RBTree() {
	delete nil;
	root = nullptr;
	nil = nullptr;
}

void RBTree::RBInsert(int k) {
	RBNode * z = new RBNode(k);
	z->lchild = this->nil;
	z->rchild = this->nil;

	
	RBNode * y = this->nil;		//set y to nil
	RBNode * x = this->root;		//set x to root
	while (x != this->nil) {		//while x is not nil
		y = x;						//set y to x
		if (z->key < x->key) {
			x = x->lchild; 
		} else {
			x = x->rchild;
		}
	}
	z->parent = y;				//loop continues until a nil is found
	if (y == this->nil) {			//tree is empty
		this->root = z;
		z->parent = this->nil;
	}
	else if (z->key < y->key) {	//go left if less
		y->lchild = z;
	} else {
		y->rchild = z;			//go right if same or greater
	}
	
	this->RBInsertFixUp(z);
}


void RBTree::RBInsertFixUp(RBNode * z) {
	RBNode * y;
	if (z != (this->root)) {
		while (z->parent->c == RED) {
			if (z->parent == z->parent->parent->lchild) { 	//if z's parent is the lchild
				y = z->parent->parent->rchild;					//set y to z's uncle
				if (y->c == RED) {									//CASE 1
					z->parent->c = BLACK;						//set z's parent to black
					y->c = BLACK;									//set z's uncle to black
					z->parent->parent->c = RED;				//set z's grandparent to red
					z = z->parent->parent;						//set z to z's grandparent
				}
				else if (z == z->parent->rchild) {					//CASE 2
					z = z->parent;									//set z to z's parent
					this->LeftRotation(z);									//perform left rotate around z
				}
				else {													//CASE 3
					z->parent->c = BLACK;						//set z's parent to black
					z->parent->parent->c = RED;				//set z's grandparent to red
					(*this).RightRotation(z->parent->parent);		//perform right rotate around z's grandparent
				}
			}
			else {														//if z's parent is the rchild
				y = z->parent->parent->lchild;					//set y to z's uncle
				if (y->c == RED) {									//CASE 1
					z->parent->c = BLACK;						//set z's parent to black
					y->c = BLACK;									//set z's uncle to black
					z->parent->parent->c = RED;				//set z's grandparent to red
					z = z->parent->parent;						//set z to z's grandparent
				}
				else if (z == z->parent->lchild) {					//CASE 2
					z = z->parent;									//set z to z's parent
					this->RightRotation(z);									//perform right rotate around z
				}
				else {													//CASE 3
					z->parent->c = BLACK;						//set z's parent to black
					z->parent->parent->c = RED;				//set z's grandparent to red
					this->LeftRotation(z->parent->parent);				//perform left rotate around z's grandparent
				}
			}
		}
	}
	this->root->c = BLACK;
}

void RBTree::LeftRotation(RBNode * x) {
	RBNode * y = x->rchild; 		//set y
	x->rchild = y->lchild;			//set x rchild to y's lchild
	if (y->lchild != this->nil) {	//if y's left is not nil
		y->lchild->parent = x;	//	set y's left's parent to x
	}
	y->parent = x->parent;					//set y's parent to x's parent
	if (x->parent == this->nil) {	//if x's parent is nil
		this->root = y;				//	set root to y;
		y->parent = this->nil;
	}
	else if (x == x->parent->lchild) {		//if x is the left child
		x->parent->lchild = y;		//	set x parent left to y
	}
	else {							//	else set x parent right to y
		x->parent->rchild = y;
	}
	y->lchild = x;						//set y's left to x
	x->parent = y;						//set x's parent to y
}

void RBTree::RightRotation(RBNode * x) {
	RBNode * y = x->lchild; 			//set y
	x->lchild = y->rchild;			//set x lchild to y's rchild
	if (y->rchild != this->nil) {	//if y's right is not nil
		y->rchild->parent = x;	//	set y's right's parent to x
	}
	y->parent = x->parent;			//set y's parent to x's parent
	if (x->parent == this->nil) {	//if x's parent is nil
		this->root = y;				//	set root to y;
		y->parent = this->nil;
	}	
	else if (x == x->parent->lchild) {	//if x is the left child
		x->parent->lchild = y;	//	set x parent left to y
	}
	else {								//	else set x parent right to y
		x->parent->rchild = y;
	}
	y->rchild = x;					//set y's right to x
	x->parent = y;					//set x's parent to y
}

void RBTree::RBRead(string in) {
	std::ifstream inFile;
	inFile.open(in);
	inFile >> this->N;							//set N
	cout << "Input N: " << this->N << endl;
	this->preOrderKeys = new int[this->N];
	this->preOrderColors = new int[this->N];
	
	int ii;
	for (ii = 0; ii<N; ii++) {
		inFile >> *(this->preOrderColors + ii);	//adds color to array at ii
		inFile >> *(this->preOrderKeys + ii);		//adds key to array at ii
	}
	
	inFile >> this->C;							//set C
	this->insertKeys = new int[this->C];
	cout << "Input C: " << this->C << endl;
	
	for (ii = 0; ii<C; ii++) {
		inFile >> *(this->insertKeys + ii);		//saves keys to be inserted to array at ii
	}
	
	this->root = preOrderConstruct(0, 0, this->N - 1, this->N);
	this->root->parent = this->nil;
	
}

RBNode * RBTree::preOrderConstruct(int preIndex, int min, int max, int size) {
	int currKey = *(this->preOrderKeys + preIndex);
	//cout << "trying to construct key: " << currKey << " at preindex " << preIndex << endl;
	//cout << "\t min: " << min << "  max: " << max << " size: " << size << endl;
	int currColor = *(this->preOrderColors + preIndex);
	
	//base case
	if ( (preIndex >= size) || (min > max) ){
		return this->nil;
	}
	
	//set this node up
	RBNode * currNode = new RBNode(currKey);
	currNode->c = (color) currColor;
		
	//case 1: only one node in this subtree (leaf)
	if (min == max) {
		currNode->lchild = this->nil;
		currNode->rchild = this->nil;
		return currNode;
	}
	
	//case 2: searching for greatest element greater than current key
	int ii;
	for (ii=min; ii<=max; ++ii) {
		if ( *(this->preOrderKeys + ii) > currNode->key ) {
			break;
		}	
	}
	
	//move pointer to next element
	preIndex++;
	//all nodes in range (index, ii-1) go in left
	//all nodes in range (ii, max) go in right
	RBNode * L = new RBNode();
	RBNode * R = new RBNode();
	L = this->preOrderConstruct(preIndex, preIndex, ii-1, size); 
	R = this->preOrderConstruct(ii, ii, max, size);
	currNode->lchild = L;
	currNode->rchild = R;
	L->parent = currNode;
	R->parent = currNode;
	
	return currNode;

}


void RBTree::RBWrite() {
	std::ofstream outFile;
	outFile.open("output.txt", std::ofstream::out | std::ofstream::app);
	RBPreorderOut(this->root, outFile);
	outFile << endl;
}

void RBTree::RBPreorderOut(RBNode * x, std::ofstream& out) {
	out << x->c;
	out	<< " ";
	out << x->key;
	out << std::endl;
	
	if (x->lchild != this->nil) {
		RBPreorderOut(x->lchild, out);
	}
	if (x->rchild != this->nil) {
		RBPreorderOut(x->rchild, out);
	}
}