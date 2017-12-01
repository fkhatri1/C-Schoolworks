#include "linkednode.hpp"

LinkedNode::LinkedNode(int k, LinkedNode* n) {
	key = k;
	next = n;
}

LinkedNode::LinkedNode(int k) {
	key = k;
	next = nullptr;
}

LinkedNode::~LinkedNode() {
	next = nullptr;
}

int LinkedNode::getKey() {
	return (*this).key;
}

LinkedNode* LinkedNode::getNext() {
	return (*this).next;
}

void LinkedNode::setNext(LinkedNode* nextNode) {
	(*this).next = nextNode;
}