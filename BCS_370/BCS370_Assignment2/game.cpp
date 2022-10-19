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
//			     for dynamic memory usage. 
//
// Compiler: Visual C++ 2019
//****************************************************

#include "game.h"

//****************************************************
// Function: Operator >> Overload
//
// Purpose: Reads value of all member values from given istream.
//****************************************************
istream& operator >>(istream& in, const Game& rhs)
{
	in >> *rhs.title;
	in >> *rhs.esrb;
	in >> *rhs.price;

	return in;
}

//****************************************************
// Function: Destructor
//
// Purpose: Deletes instance of Game.
//****************************************************
Game::~Game()
{
	cout << "Game Deleted" << endl;

	delete title;
	title = nullptr;

	delete esrb;
	esrb = nullptr;

	delete price;
	price = nullptr;
}

//****************************************************
// Function: Non-Member Operator<< Overload
//
// Purpose: To allow class to output in console
//
// Update Information
// ------------------
//
// Date: 10/4/2021
// Description: Updated for pointers.
//
//****************************************************
ostream& operator<<(ostream& os, Game& rhs)
{
	os << *rhs.title << endl;
	os << *rhs.esrb << endl;
	os << *rhs.price << endl;

	return os;
}

//****************************************************
// Function: Member Overload for the Assignment Operator.
//
// Purpose: To allow class to copy
//
// Update Information
// ------------------
//
// Date: 10/4/2021
// Description: Updated for pointers. Performs deep copy. 
//
//****************************************************
const Game& Game::operator=(const Game& rhs)
{
	if (this == &rhs)
		return *this;

	*title = *rhs.title;
	*esrb = *rhs.esrb;
	*price = *rhs.price;
	
	return *this;
}

//****************************************************
// Function: Default Constructor
//
// Purpose: Gives default valuables to class
//
// Update Information
// ------------------
//
// Date: 10/4/2021
// Description: Changed member variables to pointers.
//
//****************************************************
Game::Game()
{
	title = new string;
	esrb = new string;
	price = new double; 

	*title = "default";
	*esrb = "Everybody";
	*price = 59.99;
}

//****************************************************
// Function: Constructor with Parameters
//
// Purpose: Allows setting of parameters for class
//
// Update Information
// ------------------
// Date: 10/4/2021
// Description: Changed member variables to pointers. Dereferenced
//			    pointers to set value
//	
//****************************************************
Game::Game(string newTitle, string newEsrb, double newPrice)
{
	title = new string;
	esrb = new string;
	price = new double;

	*title = newTitle;
	*esrb = newEsrb;
	*price = newPrice;
}

//****************************************************
// Function: Copy Constructor
//
// Purpose: Copies constructor
//
// Update Information
// ------------------
//
// Date: 10/4/2021 
// Description: Updated for pointers
//
//****************************************************
Game::Game(const Game& rhs)
{
	title = new string;
	esrb = new string;
	price = new double;

	*title = *rhs.title;
	*esrb = *rhs.esrb;
	*price = *rhs.price;
}

//****************************************************
// Function: SetTitle
//
// Purpose: Sets a title
//
// Update Information
// ------------------
//
// Date: 10/4/2021 
// Description: Updated for pointers
//
//****************************************************
void Game::setTitle(string newTitle)
{	
	*title = newTitle;
}

//****************************************************
// Function: setEsrb
//
// Purpose: Sets a esrb
//
// Update Information
// ------------------
//
// Date: 10/4/2021 
// Description: Updated for pointers
//
//****************************************************
void Game::setEsrb(string newEsrb)
{
	*esrb = newEsrb;
}

//****************************************************
// Function: setPrice
//
// Purpose: Sets a price
//
// Update Information
// ------------------
//
// Date: 10/4/2021 
// Description: Updated for pointers
//
//****************************************************
void Game::setPrice(double newPrice)
{
	*price = newPrice;
}

//****************************************************
// Function: getTitle

//
// Purpose: returns title
//
// Update Information
// ------------------
//
// Date: 10/4/2021 
// Description: Updated for pointers
//
//****************************************************
string Game::getTitle()
{
	return *title;
}

//****************************************************
// Function: getEsrb
//
// Purpose: returns esrb
//
// Update Information
// ------------------
//
// Date: 10/4/2021 
// Description: Updated for pointers
//
//****************************************************
string Game::getEsrb()
{
	return *esrb;
}

//****************************************************
// Function: getPrice
//
// Purpose: returns price
//
// Update Information
// ------------------
//
// Date: 10/4/2021 
// Description: Updated for pointers
//
//****************************************************
double Game::getPrice()
{
	return *price;
}