//****************************************************
// File: game.h
//
// Purpose: Store game information.
//
// Written By: Xhovani Mali
//
// Compiler: Visual C++ 2019
// 
//*****************************************************

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Game
{

private:
	string title;
	string esrb;
	double price;

public:

	Game();
	Game(string newTitle, string esrb, double price);

	// Copy Constructor
	Game(const Game& rhs);

	string getTitle();
	void setTitle(string newTitle);

	string getEsrb();
	void setEsrb(string esrb);

	double getPrice();
	void setPrice(double price);
	
	// Constructs an ostream object
	friend ostream& operator<<(ostream& os, Game& rhs);
};
