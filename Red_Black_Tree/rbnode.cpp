/*
 *Faysal Khatri  1213830616  HW5
 *rbnode.cpp
 */
#include "rbnode.hpp"

RBNode::RBNode(int k) {
	key = k;
	c = RED; //Default to Red
	parent = nullptr;
	lchild = nullptr;
	rchild = nullptr;
}

RBNode::RBNode() {
	key = -1;
	c = RED;
	parent = nullptr;
	lchild = nullptr;
	rchild = nullptr;	
}
