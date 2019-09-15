//
// tLinkedList.h
//

#ifndef TLINKEDLIST_H
#define TLINKEDLIST_H

//
// tNode
//
struct tNode
{
	int data;
	tNode* nextPtr;
};


//
// tLinkedList
//
class tLinkedList
{
	public:

		// Constructor
		tLinkedList();

		// Destructor
		~tLinkedList();

		// insertNode()
		void insertNode(int value);

		// reverse()
		void reverse();

		// print()
		void print();

	private:

		tNode* _headPtr;

};

#endif