#include <iostream>
#include <limits>
#include <stdio.h>
#include <vector>

#include "tHashTable.h"
#include "tLinkedList.h"
#include "tRedBlackTree.h"
#include "tHashTable.cpp"

using namespace std;


//
// increment_array()
//
void increment_array( int* input, int len )
{
	for( int i = ( len - 1 ); i > 0; i-- )
	{
		if( input[ i ] != 9 )
		{
			input[ i ] = input[ i ] + 1;
			break;
		}
		else // input == 9
		{
			input[ i ] = 0;
		}
	}
}


//
// main()
//
int main()
{
	/* EXAMPLE 1a: Linked List */
	tLinkedList linkedList;
	linkedList.insertNode( 1 );
	linkedList.insertNode( 2 );
	linkedList.insertNode( 3 );
	linkedList.insertNode( 4 );
	
	cout << "Original Linked List = ";
	linkedList.print();
	cout << endl;

	linkedList.reverse();
	cout << "Reversed Linked List = ";
	linkedList.print();
	cout << endl << endl;

	/* EXAMPLE 1b: Linked List */
	tLinkedList linkedList2;
	linkedList2.insertNode(1);

	cout << "Original Linked List = ";
	linkedList2.print();
	cout << endl;

	linkedList2.reverse();
	cout << "Reversed Linked List = ";
	linkedList2.print();
	cout << endl << endl;

	/* EXAMPLE 2: Hash Table */

	tHashTable<int, int> hashTable;
	hashTable.insertNode( 0, 10 );
	hashTable.insertNode( 10, 100 );
	hashTable.print();
	cout << endl;

	cout << "Search: Key = " << 0 << ", Value = " << hashTable.searchKey( 0 ) << endl;
	cout << "Search: Key = " << 10 << ", Value = " << hashTable.searchKey( 10 ) << endl << endl;

	hashTable.removeNode( 0 );
	hashTable.print();
	cout << endl;

	cout << "Search: Key = " << 0 << ", Value = " << hashTable.searchKey(0) << endl << endl;

	/* EXAMPLE 3: Red Black Tree */

	tRedBlackTree tree;

	tree.insert( 7 );
	cout << "Inorder Traversal of Created Tree" << endl;
	tree.inOrder();
	cout << endl << endl;

	cout << "Level Order Traversal of Created Tree" << endl;
	tree.levelOrder();
	cout << endl << endl;

	tree.insert( 6 );
	cout << "Inorder Traversal of Created Tree" << endl;
	tree.inOrder();
	cout << endl << endl;

	cout << "Level Order Traversal of Created Tree" << endl;
	tree.levelOrder();
	cout << endl << endl;

	tree.insert( 5 );
	cout << "Inorder Traversal of Created Tree" << endl;
	tree.inOrder();
	cout << endl << endl;

	cout << "Level Order Traversal of Created Tree" << endl;
	tree.levelOrder();
	cout << endl << endl;

	tree.insert( 4 );
	cout << "Inorder Traversal of Created Tree" << endl;
	tree.inOrder();
	cout << endl << endl;

	cout << "Level Order Traversal of Created Tree" << endl;
	tree.levelOrder();
	cout << endl << endl;

	tree.insert( 3 );
	cout << "Inorder Traversal of Created Tree" << endl;
	tree.inOrder();
	cout << endl << endl;

	cout << "Level Order Traversal of Created Tree" << endl;
	tree.levelOrder();
	cout << endl << endl;

	tree.insert( 2 );
	cout << "Inorder Traversal of Created Tree" << endl;
	tree.inOrder();
	cout << endl << endl;

	cout << "Level Order Traversal of Created Tree" << endl;
	tree.levelOrder();
	cout << endl << endl;

	tree.insert( 1 );
	cout << "Inorder Traversal of Created Tree" << endl;
	tree.inOrder();
	cout << endl << endl;

	cout << "Level Order Traversal of Created Tree" << endl;
	tree.levelOrder();
	cout << endl << endl;

	tree.insert( 0 );
	cout << "Inorder Traversal of Created Tree" << endl;
	tree.inOrder();
	cout << endl << endl;

	cout << "Level Order Traversal of Created Tree" << endl;
	tree.levelOrder();
	cout << endl << endl;

	int input[ 8 ] = { 1, 4, 6, 7, 0, 2, 9, 0 };

	increment_array( input, 8 );

	return 0;
}