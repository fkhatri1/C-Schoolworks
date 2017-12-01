/*
 *Faysal Khatri  1213830616  HW5
 *rbnode.hpp
 */
#ifndef RBNODE
#define RBNODE

typedef enum {RED, BLACK, DOUBLEBLACK} color;

class RBNode {
	public:
		int key;
		color c;
		RBNode * parent;
		RBNode * lchild;
		RBNode * rchild;
		RBNode(int);
		RBNode();
};


#endif