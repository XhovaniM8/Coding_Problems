//****************************************************
// File: game.cpp
//
// Purpose: Store game information.
//
// Written By: Xhovani Mali
//
// Update Information
// ------------------
//
// 10/5/2021: Added Destructor, >> Operator Overload, updated functions 
//			  for dynamic memory usage. 
//
// Description: Added updates to make Game function with pointers
//				Changed member variables to pointers. Added destructor.
// Compiler: Visual C++ 2019
//****************************************************

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Game
{

private:
	string *title;
	string *esrb;
	double *price;

public:

	// Default Constructor
	Game();

	// Constructor with parameters
	Game(string newTitle, string newEsrb, double newPrice);

	// Copy Constructor
	Game(const Game& rhs);

	// Delete
	~Game();

	// Gets & Sets
	string getTitle();
	void setTitle(string newTitle);

	string getEsrb();
	void setEsrb(string newEsrb);

	double getPrice();
	void setPrice(double newPrice);
	
	// Constructs an ostream object
	friend ostream& operator<<(ostream& os, Game& rhs);

	// Member overload for the assignment operator
	const Game& operator=(const Game& rhs);

	// Operator >> Overload
	friend istream& operator >>(istream& in, const Game& rhs);
};
