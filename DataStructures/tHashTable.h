//
// tHashtable.h
//

#ifndef THASHTABLE_H
#define THASHTABLE_H

static const int TABLE_SIZE = 128;

//
// tHashTableEntry
//
template< typename K, typename V >
class tHashTableEntry
{
	public:

		//
		// constructor()
		//
		tHashTableEntry( K key, V value )
		{
			_key = key;
			_value = value;
		}

		//
		// getKey()
		//
		int getKey()
		{
			return _key;
		}

		//
		// getValue()
		//
		int getValue()
		{
			return _value;
		}

	private:

		K _key;
		V _value;

};


//
// tHashTable
//
template<typename K, typename V>
class tHashTable
{
	public:

		// Constructor
		tHashTable();

		// Destructor
		~tHashTable();

		// insertNode()
		void insertNode( K key, V value );

		// removeNode()
		void removeNode( K key );

		// searchKey()
		V searchKey( K key);

		// print()
		void print();

	private:

		// hashFunction
		int hashFunction( K key );

	private:

		tHashTableEntry<K, V> **table;

};

#endif