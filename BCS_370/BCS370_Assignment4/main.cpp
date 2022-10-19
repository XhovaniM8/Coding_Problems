//****************************************************
// File: main.cpp
//
// Purpose: 
//
// Written By: Xhovani Mali
//
// Compiler: Visual C++ 2019
//****************************************************

#include <iostream>
#include <fstream>
#include <istream>
#include "game.h"
#include "TreeNode.h"
#include "BST.h"
using namespace std;

int main()
{
	Game a("A", "E", 10);
	Game b("B", "E", 20);
	Game c("C", "E", 30);
	Game e("E", "E", 40);
	Game d("D", "E", 50);

	BST tree;
	BST copyTree;

	tree.Add(a);
	tree.Add(c);
	tree.Add(b);
	tree.Add(e);
	tree.Add(d);

	copyTree.Add(c);
	copyTree.Add(d);
	copyTree.Add(a);
	copyTree.Add(e);
	copyTree.Add(b);

	tree.PrintTree();
	cout << endl;

	cout << "Size is: " << tree.Size() << endl;
	cout << endl;

	tree.Preorder();
	cout << endl;

	tree.Inorder();
	cout << endl;

	tree.Postorder();
	cout << endl;

	double score;
	tree.GetPrice("A", score);
	cout << score << endl;

}