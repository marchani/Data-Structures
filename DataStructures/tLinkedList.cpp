#include "tLinkedList.h"

#include <iostream>
#include <stdio.h>

//
// constructor()
//
tLinkedList::tLinkedList()
{
	_headPtr = NULL;
}


//
// destructor()
//
tLinkedList::~tLinkedList()
{
	if( _headPtr == NULL ) return;

	tNode* currPtr = _headPtr;
	tNode* nextPtr = _headPtr->nextPtr;

	while( nextPtr != NULL )
	{
		delete currPtr;

		currPtr = nextPtr;
		nextPtr = currPtr->nextPtr;
	}

	delete currPtr;
	currPtr = NULL;
}


//
// reverse()
//
void tLinkedList::reverse()
{
	if( ( _headPtr == NULL ) || ( _headPtr->nextPtr == NULL ) ) return;

	tNode* prevPtr = NULL;
	tNode* currPtr = _headPtr;
	tNode* succPtr = currPtr->nextPtr;

	while( currPtr != NULL )
	{
		succPtr = currPtr->nextPtr;

		currPtr->nextPtr = prevPtr;

		prevPtr = currPtr;
		currPtr = succPtr;
	}

	_headPtr = prevPtr;
}


//
// insertNode()
//
void tLinkedList::insertNode( int value )
{
	tNode* newNode = new tNode();
	newNode->data = value;
	newNode->nextPtr = NULL;

	if( _headPtr == NULL )
	{
		_headPtr = newNode;
	}
	else // _headPtr != NULL
	{
		tNode* currPtr = _headPtr;

		while (currPtr->nextPtr != NULL)
		{
			currPtr = currPtr->nextPtr;
		}

		currPtr->nextPtr = newNode;
	}
}


//
// print()
//
void tLinkedList::print()
{
	tNode* currPtr = _headPtr;

	while( currPtr != NULL )
	{
		std::cout << currPtr->data << ", ";
		currPtr = currPtr->nextPtr;
	}
}
