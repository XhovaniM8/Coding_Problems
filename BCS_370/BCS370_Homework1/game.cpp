//****************************************************
// File: game.cpp
//
// Purpose: Store game information.
//
// Written By: Xhovani Mali
//
// Compiler: Visual C++ 2019
//****************************************************

#include "game.h"


//****************************************************
// Function: Operator Overload
//
// Purpose: To allow class to output in console
//****************************************************
ostream& operator<<(ostream& os, Game& rhs)
{
	os << rhs.title << endl;
	os << rhs.esrb << endl;
	os << rhs.price << endl;

	return os;
}

//****************************************************
// Function: Default Constructor
//
// Purpose: Gives default valuables to class
//****************************************************
Game::Game()
{
	title = "default";
	esrb = "Everybody";
	price = 59.99;
}

//****************************************************
// Function: Constructor with Parameters
//
// Purpose: Allows setting of parameters for class
//****************************************************
Game::Game(string newTitle, string newEsrb, double newPrice)
{
	title = newTitle;
	esrb = newEsrb;
	price = newPrice;
}

//****************************************************
// Function: Copy Constructor
//
// Purpose: Copies constructor
//****************************************************
Game::Game(const Game& rhs)
{
	title = rhs.title;
	esrb = rhs.esrb;
	price = rhs.price;
}

//****************************************************
// Function: SetTitle
//
// Purpose: Sets a title
//****************************************************
void Game::setTitle(string newTitle)
{
	title = newTitle;
}

//****************************************************
// Function: setEsrb
//
// Purpose: Sets a esrb
//****************************************************
void Game::setEsrb(string newEsrb)
{
	esrb = newEsrb;
}

//****************************************************
// Function: setPrice
//
// Purpose: Sets a price
//****************************************************
void Game::setPrice(double newPrice)
{
	price = newPrice;
}

//****************************************************
// Function: getTitle
//
// Purpose: returns title
//****************************************************
string Game::getTitle()
{
	return title;
}

//****************************************************
// Function: getEsrb
//
// Purpose: returns esrb
//****************************************************
string Game::getEsrb()
{
	return esrb;
}

//****************************************************
// Function: getPrice
//
// Purpose: returns price
//****************************************************
double Game::getPrice()
{
	return price;
}