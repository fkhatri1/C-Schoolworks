#ifndef LINKED_NODE
#define LINKED_NODE

class LinkedNode {
	private:
		LinkedNode* next;
		int key;
	public:
		LinkedNode(int k, LinkedNode* n);
		LinkedNode(int k);
		virtual ~LinkedNode();
		int getKey();
		LinkedNode* getNext();
		void setNext(LinkedNode*);
};



#endif
