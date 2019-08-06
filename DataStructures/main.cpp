#include <iostream>
#include <limits>
#include <stdio.h>
#include <vector>

#include "tHashTable.h"
#include "tHashTable.cpp"

using namespace std;


//
// main()
//
int main()
{
	/* EXAMPLE 1: Hash Table */

	tHashTable<int, int> hashTable;
	hashTable.insertNode( 0, 10 );
	hashTable.insertNode( 10, 100 );
	hashTable.print();
	cout << endl;

	cout << "Search: Key = " << 0 << ", Value = " << hashTable.searchKey( 0 ) << endl;
	cout << "Search: Key = " << 10 << ", Value = " << hashTable.searchKey( 10 ) << endl;
	cout << endl;

	hashTable.removeNode( 0 );
	hashTable.print();
	cout << endl;

	cout << "Search: Key = " << 0 << ", Value = " << hashTable.searchKey(0) << endl;

	return 0;
}