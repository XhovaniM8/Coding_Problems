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
// Date: 10/5/2021 
// Description: Added Destructor, >> Operator Overload, updated functions 
//			    for dynamic memory usage. 
//
// Date: 11/30/2021
// Description: Added Non-Member Overload for < Operator & > Operator
//
// Compiler: Visual C++ 2019
//****************************************************

#pragma once
#include <string>
#include <iostream>
#include <fstream>
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

	// non-member overload for the less than operator
	friend bool operator<(Game& lhs, Game& rhs);

	// non-member overload for the greater than operator.
	friend bool operator>(Game& lhs, Game& rhs);
};
