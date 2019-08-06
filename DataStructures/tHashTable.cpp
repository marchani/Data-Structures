#include "tHashTable.h"

//
// constructor()
//
template< typename K, typename V >
tHashTable< K, V >::tHashTable()
{
	table = new tHashTableEntry< K, V >*[ TABLE_SIZE ];

	for( int i = 0; i < TABLE_SIZE; i++ )
	{
		table[ i ] = NULL;
	}
}


//
// destructor()
//
template< typename K, typename V >
tHashTable< K, V >::~tHashTable()
{
	for( int i = 0; i < TABLE_SIZE; i++ )
	{
		if( table[ i ] != NULL )
		{
			delete table[ i ];
		}
	}

	delete[] table;
}


//
// hashFunction()
//
template< typename K, typename V >
int tHashTable< K, V >::hashFunction( K key )
{
	return key % TABLE_SIZE;
}


//
// insertNode()
//
template< typename K, typename V >
void tHashTable< K, V >::insertNode( K key, V value )
{
	// Apply hash function to find index for given key
	int hashIndex = hashFunction( key );

	// Find next free space
	while( ( table[ hashIndex ] != NULL ) &&
		   ( table[ hashIndex ]->getKey() != key ) )
	{
		hashIndex = ( hashIndex + 1 ) % TABLE_SIZE;
	}

	if( table[ hashIndex ] == NULL )
	{
		delete table[ hashIndex ];
	}

	table[ hashIndex ] = new tHashTableEntry< K, V >( key, value );
}


//
// removeNode()
//
template< typename K, typename V >
void tHashTable< K, V >::removeNode( K key )
{
	int hashIndex = hashFunction( key );

	while( ( table[ hashIndex ] != NULL ) &&
		   ( table[ hashIndex ]->getKey() != key ) )
	{
		hashIndex = hashFunction( hashIndex + 1 );
	}

	if( table[ hashIndex ] == NULL )
	{
		cout << "No element found at key " << key << endl;
	}
	else
	{
		table[ hashIndex ] = NULL;
		delete table[ hashIndex ];

		cout << "Element deleted." << endl;
	}
}


//
// searchKey()
//
template< typename K, typename V >
V tHashTable< K, V >::searchKey( K key )
{
	int hashIndex = hashFunction( key );

	while( ( table[ hashIndex ] != NULL ) &&
		   ( table[ hashIndex ]->getKey() != key ) )
	{
		hashIndex = hashFunction( hashIndex + 1 );
	}

	if( table[ hashIndex ] == NULL )
	{
		return -1;
	}
	else
	{
		return table[ hashIndex ]->getValue();
	}
}


//
// print()
//
template< typename K, typename V >
void tHashTable< K, V >::print()
{
	for( int i = 0; i < TABLE_SIZE; i++ )
	{
		if( ( table[ i ] != NULL ) &&
			( table[ i ]->getKey() != -1 ) )
		{
			cout << "Key = " << table[ i ]->getKey() << ", Value = " << table[ i ]->getValue() << endl;
		}
	}
}
