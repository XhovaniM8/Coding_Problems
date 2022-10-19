//****************************************************
// File: BST.h
//
// Purpose: Implements a Binary Search Tree
//
// Written By: Xhovani Mali
//
// Update Information
// ------------------
//
// Compiler: Visual C++ 2019
//****************************************************
#include "BST.h"

//****************************************************
// Function: BST Constructor
//
// Big O(1)
//
// Purpose: Creates an empty binary search tree.
//****************************************************
BST::BST()
{
	root = nullptr;
}

//****************************************************
// Function: BST Copy Constructor
//
// Big O(n)
//
// Purpose: This function should make a deep copy of the passed in
//			binary search tree
//****************************************************
BST::BST(const BST& rhs)
{
	CopyTree(this->root, rhs.root);
}

//****************************************************
// Function: BST Deconstructor
//
// Big O(n) (unless root = nullptr, then Big O(1))
//
// Purpose: Clears the binary search tree and releases ALL dynamically allocated
//			memory.
//****************************************************
BST::~BST()
{
	Clear();
}

//****************************************************
// Function: = Operator Overloard
//
// Big O(n)
//
// Purpose: Makes a deep copy of the rhs parameter
//****************************************************
BST& BST::operator=(const BST& rhs)
{
	return *this;
}


//****************************************************
// Function: << Operator Overload
//
// Big O(n)
//
// Purpose: Print the values of ALL elements on the binary search tree on the given
//			ostream.
//****************************************************
ostream& operator<<(ostream& out, const BST& rhs)
{
	return out;
}

//****************************************************
// Function: Size 
//
// Big O(n) (unless root == nullptr, then Big O(1))
//
// Purpose: Returns the number of elements that are currently in the binary search
//			tree.
//****************************************************
int BST::Size()
{
	return Size(root);
}

//****************************************************
// Function: Size (Helper)
//
// Big O(n) (unless root == nullptr, then Big O(1))
//
// Purpose:  Returns the number of elements that are currently in the binary search
//			 tree.
//****************************************************
int BST::Size(TreeNode* tree)
{
	if (tree == nullptr)
		return 0;
	else
		return Size(tree->left) + Size(tree->right) + 1;
}

//****************************************************
// Function: Clear
//
// Big O(n) (unless root == nullptr, then Big O(1))
//
// Purpose: Clears the binary search tree and releases ALL dynamically allocated
//			memory.
//****************************************************
void BST::Clear()
{
	Clear(root);
	root = nullptr;
}

//****************************************************
// Function: Clear (Helper)
//
// Big O(n) (unless root == nullptr, then Big O(1))
//
// Purpose: Clears the binary search tree and releases ALL dynamically allocated
//			memory.
//****************************************************
void BST::Clear(TreeNode*& tree)
{
	if (root != nullptr)
	{
		Clear(tree->left);
		Clear(tree->right);
		delete tree;
	}
}

//****************************************************
// Function: CopyTree 
//
// Big O(n) (unless root == nullptr, then Big O(1))
//
// Purpose: Copies tree into new tree
//****************************************************
void BST::CopyTree(TreeNode*& copy, const TreeNode* originalTree)
{
	if (originalTree == nullptr){
		copy = nullptr;
	}
	else
	{
		copy = new TreeNode;
		copy->gameData = originalTree->gameData;
		CopyTree(copy->left, originalTree->left);
		CopyTree(copy->right, originalTree->right);
	}
}

//****************************************************
// Function: Add
//
// Big O(n) (unless root == nullptr, then Big O(1))
//
// Purpose: Add a Game object to the binary search tree.
//****************************************************
void BST::Add(Game addedGame)
{
	Add(root, addedGame);
}

//****************************************************
// Function: Add (Helper)
//
// Big O(n) (unless root == nullptr, then Big O(1))
//
// Purpose: Add a Game object to the binary search tree.
//****************************************************
void BST::Add(TreeNode*& tree, Game addedGame)
{
	if (tree == nullptr)
	{
		tree = new TreeNode;
		tree->right = nullptr;
		tree->left = nullptr;
		tree->gameData = addedGame;
	}
	else if (addedGame.getTitle() < tree->gameData.getTitle())
		Add(tree->left, addedGame);
	else
		Add(tree->right, addedGame);
}

//****************************************************
// Function: PrintTree 
//
// Big O(n)
//
// Purpose: Prints tree
//****************************************************
void BST::PrintTree()
{
	PrintTree(root, cout);
}

//****************************************************
// Function: PrintTree (helper)
//
// Big O(n)
//
// Purpose: Prints tree
//****************************************************
void BST::PrintTree(TreeNode* tree, ostream& out)
{
	if (tree != nullptr)
	{
		PrintTree(tree->left, out);
		out << tree->gameData.getTitle() << " ";
		PrintTree(tree->right, out);
	}
}

//****************************************************
// Function: GetPrice
//
// Big O(n)
//
// Purpose: This function should find the score given a Game name (send back price
//			through reference parameter).
//****************************************************
bool BST::GetPrice(string name, double& price)
{
	bool found; 
	RetrievePrice(root, price, found);
	return found;
}

//****************************************************
// Function: RetrievePrice
//
// Big O(n)
//
// Purpose: This function should find the score given a Game name (send back price
//			through reference parameter).
//****************************************************
bool BST::RetrievePrice(TreeNode* tree, double& price, bool& found)
{
	if (tree == nullptr)
		found = false;
	else if (price < tree->gameData.getPrice())
		RetrievePrice(tree->left, price, found);
	else if (price > tree->gameData.getPrice())
		RetrievePrice(tree->right, price, found);
	else
	{
		price = tree->gameData.getPrice();
		found = true;
	}
	return found;
}

//****************************************************
// Function: Preorder
//
// Big O(n)
//
// Purpose: Print only the name of all the Game objects in the binary search tree on
//			the console.The output should be done using a preorder traversal of the
//			binary search tree.
//****************************************************
void BST::Preorder()
{
	Preorder(root);
}

//****************************************************
// Function: Preorder (Helper)
//
// Big O(n)
//
// Purpose: Print only the name of all the Game objects in the binary search tree on
//			the console.The output should be done using a preorder traversal of the
//			binary search tree.
//****************************************************
void BST::Preorder(TreeNode* tree)
{
	if (tree != nullptr)
	{
		cout << tree->gameData.getTitle() << " ";
		Preorder(tree->left);
		Preorder(tree->right);
	}
}

//****************************************************
// Function: Inorder
//
// Big O(n)
//
// Purpose: Print only the name of all the Game objects stored in the binary search
//			tree on the console.The output should be done using an inorder
//			traversal of the binary search tree.
//****************************************************
void BST::Inorder()
{
	Inorder(root);
}

//****************************************************
// Function: Inorder (Helper)
//
// Big O(n)
//
// Purpose: Print only the name of all the Game objects stored in the binary search
//			tree on the console.The output should be done using an inorder
//			traversal of the binary search tree.
//****************************************************
void BST::Inorder(TreeNode* tree)
{
	if (tree != nullptr)
	{
		Inorder(tree->left);
		cout << tree->gameData.getTitle() << " ";
		Inorder(tree->right);
	}
}

//****************************************************
// Function: Postorder 
//
// Big O(n)
//
// Purpose: Print only the name of all the Game objects stored in the binary search
//			tree on the console.The output should be done using a postorder
//			traversal of the binary search tree.
//****************************************************
void BST::Postorder()
{
	Postorder(root);
}

//****************************************************
// Function: Postorder (Helper)
//
// Big O(n)
//
// Purpose: Print only the name of all the Game objects stored in the binary search
//			tree on the console.The output should be done using a postorder
//			traversal of the binary search tree.
//****************************************************
void BST::Postorder(TreeNode* tree)
{
	if (tree != nullptr)
	{
		Postorder(tree->left);
		Postorder(tree->right);
		cout << tree->gameData.getTitle() << " ";
	}
}


