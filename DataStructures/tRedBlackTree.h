//
// tRedBlackTree.h
//

#ifndef TREDBLACKTREE_H
#define TREDBLACKTREE_H

enum Color { RED, BLACK };

//
// tRedBlackTreeNode
//
struct tRedBlackTreeNode
{
	//
	// constructor()
	//
	tRedBlackTreeNode( int data )
	{
		this->data = data;
		this->color = RED;

		leftPtr = nullptr;
		rightPtr = nullptr;
		parentPtr = nullptr;
	}

	int data;
	Color color;
	tRedBlackTreeNode* leftPtr;
	tRedBlackTreeNode* rightPtr;
	tRedBlackTreeNode* parentPtr;
};


//
// tRedBlackTree
//
class tRedBlackTree
{
	public:

		// Constructor
		tRedBlackTree();

		// Destructor
		~tRedBlackTree();

		// insert()
		void insert( int data );

		// inOrder()
		void inOrder();

		// levelOrder()
		void levelOrder();

	private:

		// BSTInsert()
		tRedBlackTreeNode* BSTInsert( tRedBlackTreeNode* rootPtr, tRedBlackTreeNode* ptr );

		// fixViolation()
		void fixViolation( tRedBlackTreeNode* &rootPtr, tRedBlackTreeNode* &ptr );

		// inorderHelper()
		void inorderHelper( tRedBlackTreeNode* ptr );

		// levelOrderHelper()
		void levelOrderHelper( tRedBlackTreeNode* ptr );

		// rotateLeft()
		void rotateLeft( tRedBlackTreeNode* &rootPtr, tRedBlackTreeNode* &ptr );

		// rotateRight()
		void rotateRight(tRedBlackTreeNode* &rootPtr, tRedBlackTreeNode* &ptr);

	private:

		tRedBlackTreeNode* _rootPtr;

};

#endif