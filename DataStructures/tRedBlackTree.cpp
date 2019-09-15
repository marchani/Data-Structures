#include "tRedBlackTree.h"

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

//
// constructor()
//
tRedBlackTree::tRedBlackTree()
{
	_rootPtr = nullptr;
}


//
// destructor()
//
tRedBlackTree::~tRedBlackTree()
{
}


//
// BSTInsert()
//
tRedBlackTreeNode* tRedBlackTree::BSTInsert( tRedBlackTreeNode* rootPtr, tRedBlackTreeNode* ptr )
{
	// If the tree is empty, return a new node.
	if( rootPtr == nullptr ) return ptr;

	// Otherwise, recur down the tree.
	if( ptr->data < rootPtr->data )
	{
		rootPtr->leftPtr = BSTInsert( rootPtr->leftPtr, ptr );
		rootPtr->leftPtr->parentPtr = rootPtr;
	}
	else if( ptr->data > rootPtr->data )
	{
		rootPtr->rightPtr = BSTInsert( rootPtr->rightPtr, ptr );
		rootPtr->rightPtr->parentPtr = rootPtr;
	}

	// Return the (unchanged) node pointer.
	return rootPtr;
}


//
// rotateLeft()
//
void tRedBlackTree::rotateLeft( tRedBlackTreeNode* &rootPtr, tRedBlackTreeNode* &pt )
{
	tRedBlackTreeNode* pt_right = pt->rightPtr;

	pt->rightPtr = pt_right->leftPtr;

	if (pt->rightPtr != NULL)
		pt->rightPtr->parentPtr = pt;

	pt_right->parentPtr = pt->parentPtr;

	if (pt->parentPtr == NULL)
		rootPtr = pt_right;

	else if (pt == pt->parentPtr->leftPtr)
		pt->parentPtr->leftPtr = pt_right;

	else
		pt->parentPtr->rightPtr = pt_right;

	pt_right->leftPtr = pt;
	pt->parentPtr = pt_right;
}


//
// rotateRight()
//
void tRedBlackTree::rotateRight( tRedBlackTreeNode* &root, tRedBlackTreeNode* &pt )
{
	tRedBlackTreeNode* pt_left = pt->leftPtr;

	pt->leftPtr = pt_left->rightPtr;

	if (pt->leftPtr != NULL)
		pt->leftPtr->parentPtr = pt;

	pt_left->parentPtr = pt->parentPtr;

	if (pt->parentPtr == NULL)
		root = pt_left;

	else if (pt == pt->parentPtr->leftPtr)
		pt->parentPtr->leftPtr = pt_left;

	else
		pt->parentPtr->rightPtr = pt_left;

	pt_left->rightPtr = pt;
	pt->parentPtr = pt_left;
}


//
// fixViolation()
//
void tRedBlackTree::fixViolation( tRedBlackTreeNode* &rootPtr, tRedBlackTreeNode* &ptr )
{
	tRedBlackTreeNode* parentPtr = nullptr;
	tRedBlackTreeNode* grandparentPtr = nullptr;

	while( ( ptr != rootPtr ) &&
		   ( ptr->color != BLACK ) &&
		   ( ptr->parentPtr->color == RED ) )
	{
		parentPtr = ptr->parentPtr;
		grandparentPtr = ptr->parentPtr->parentPtr;

		// CASE A:
		// Parent of ptr is left child of grandparent of ptr
		if( parentPtr == grandparentPtr->leftPtr )
		{
			tRedBlackTreeNode* unclePtr = grandparentPtr->rightPtr;

			// CASE 1:
			// The uncle of ptr is also red
			// Only recoloring required
			if( ( unclePtr != nullptr ) &&
				( unclePtr->color == RED ) )
			{
				grandparentPtr->color = RED;
				parentPtr->color = BLACK;
				unclePtr->color = BLACK;
				ptr = grandparentPtr;
			}
			else
			{
				// CASE 2:
				// ptr is right child of its parent
				// Left-rotation required
				if( ptr == parentPtr->rightPtr )
				{
					rotateLeft( rootPtr, parentPtr );
					ptr = parentPtr;
					parentPtr = ptr->parentPtr;
				}

				// CASE 3:
				// ptr is left child of its parent
				// Right-rotation required
				rotateRight( rootPtr, grandparentPtr );
				swap( parentPtr->color, grandparentPtr->color );
				ptr = parentPtr;
			}
		}

		// CASE B:
		// Parent of ptr is right child of grandparent of ptr
		else
		{
			tRedBlackTreeNode* unclePtr = grandparentPtr->rightPtr;

			// CASE 1:
			// The uncle of ptr is also red
			// Only recoloring required
			if( ( unclePtr != nullptr) &&
				( unclePtr->color == RED ) )
			{
				grandparentPtr->color = RED;
				parentPtr->color = BLACK;
				unclePtr->color = BLACK;
				ptr = grandparentPtr;
			}
			else
			{
				// CASE 2:
				// ptr is left child of its parent
				// Right-rotation required
				if( ptr == parentPtr->leftPtr )
				{
					rotateRight( rootPtr, parentPtr );
					ptr = parentPtr;
					parentPtr = ptr->parentPtr;
				}

				// CASE 3:
				// ptr is right child of its parent
				// Left-rotation required
				rotateLeft( rootPtr, grandparentPtr );
				swap( parentPtr->color, grandparentPtr->color );
				ptr = parentPtr;
			}
		}
	}

	rootPtr->color = BLACK;
}


//
// insert()
//
void tRedBlackTree::insert( int data )
{
	tRedBlackTreeNode* ptr = new tRedBlackTreeNode( data );

	_rootPtr = BSTInsert( _rootPtr, ptr );

	fixViolation( _rootPtr, ptr );
}


//
// inorderHelper()
//
void tRedBlackTree::inorderHelper( tRedBlackTreeNode* ptr )
{
	if( ptr == NULL ) return;

	inorderHelper( ptr->leftPtr );

	cout << ptr->data << " ";
	if( ptr->color == RED )
	{
		cout << "(RED) ";
	}
	else
	{
		cout << "(BLACK) ";
	}

	inorderHelper( ptr->rightPtr );
}


//
// inOrder()
//
void tRedBlackTree::inOrder()
{
	inorderHelper( _rootPtr );
}


//
// levelOrderHelper()
//
void tRedBlackTree::levelOrderHelper( tRedBlackTreeNode* ptr )
{
	if( ptr == NULL ) return;

	queue< tRedBlackTreeNode* > q;
	q.push( ptr );

	while( !q.empty() )
	{
		tRedBlackTreeNode* temp = q.front();
		cout << temp->data << " ";

		if( temp->color == RED )
		{
			cout << "(RED) ";
		}
		else
		{
			cout << "(BLACK) ";
		}

		q.pop();

		if( temp->leftPtr != NULL )
		{
			q.push( temp->leftPtr );
		}

		if( temp->rightPtr != NULL )
		{
			q.push( temp->rightPtr );
		}
	}
}


//
// levelOrder()
//
void tRedBlackTree::levelOrder()
{
	levelOrderHelper( _rootPtr );
}
