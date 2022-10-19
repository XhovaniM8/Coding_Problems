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

#pragma once
#include "TreeNode.h"

class BST
{
private:
	TreeNode* root;

	// helper functions
	int Size(TreeNode* tree);
	void Clear(TreeNode*& tree);
	void Add(TreeNode*& tree, Game g);
	void Preorder(TreeNode* tree);
	void Inorder(TreeNode* tree);
	void Postorder(TreeNode* tree);
	bool RetrievePrice(TreeNode* tree, double& price, bool& found);
	void PrintTree(TreeNode* tree, ostream& out);

public:
	BST();					// Creates an empty BST
	BST(const BST& rhs);	// Copy constructor
	~BST();					// Destructor

	void Clear();			// Clears the binary search tree
	int Size();				// Returns elements in BST
	void Add(Game g);		// Add a game object to binary search tree
	void CopyTree(TreeNode*& copy, const TreeNode* originalTree);
	void PrintTree(); 
	bool GetPrice(string name, double& price);

	void Preorder();
	void Inorder();
	void Postorder();

	BST& operator=(const BST& rhs);
	friend ostream& operator<<(ostream& out, const BST& rhs);
};