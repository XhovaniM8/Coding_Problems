//****************************************************
// File: main.cpp
//
// Purpose: Writing the classes Game and GameStorage. To test code for the Game and GameStorage classes. 
//
// Written By: Xhovani Mali
//
// Compiler: Visual C++ 2019   
//****************************************************

#include <iostream>
#include <string>
#include "game.h"
#include "GameStorage.h"
using namespace std;

int main()
{
	// Assignment 2

	// Game Class Functions

	Game g5; // Calls Default Constructor
	cout << g5 << endl;

	cin >> g5; // Calls >> Operator Overload

	Game g1("Minecraft", "Everybody", 10); // Calls Constructor with Parameters
	Game g2("Tetris", "Mature", 20); // Calls Constructor with Parameters
	Game g3("Solitaire", "Teen", 15); // Calls Constructor with Parameters
	Game g4("Solitaire on Sale", "Teen", 5); // Calls Constructor with Parameters

	Game gA("Sims", "Everybody", 30); // Calls Constructor with Parameters
	Game gB("Tetris 2", "Mature", 25); // Calls Constructor with Parameters
	Game gC("Uno", "Teen", 10); // Calls Constructor with Parameters
	Game gD("Chess", "Teen", 100); // Calls Constructor with Parameters

	cout << g1 << endl; // Uses << Operator Overload
	cout << g2 << endl; // Uses << Operator Overload
	cout << g3 << endl; // Uses << Operator Overload

	g3 = g4; // Calling Copy Constructor using = Operator Overload

	cout << "G4 copied into G3" << endl;
	cout << g4 << endl; // Calls Constructor with Parameters

	// GameStorage Class Functions

	GameStorage A; // Calls Default Constructor
	cout << A.Size() << endl; // Checks Size (Should be 3)

	GameStorage B(4); // Calls Constructor with Parameters
	cout << B.Size() << endl; // Checks Size (Should be 4)

	A.Set(0, gA); // Sets Index to Game Instance
	A.Set(1, gB);
	A.Set(2, gC);

	B.Set(0, g1); // Sets Index to Game Instance
	B.Set(1, g2);
	B.Set(2, g3);
	B.Set(3, g4);

	Game g = B.MostExpensive(); // Doesn't Output Anything
	cout << g << endl;

	Game returnedGame;
	cout << B.FindByTitle("Minecraft", returnedGame) << endl; // Returns True
	cout << B.FindByTitle("Space Invader", returnedGame) << endl; // Returns False

	cout << B << endl; // Prints the values of all elements of the array on the given ostream.

	// Assignment 1
	/*
	
	Game g1("Minecraft", "Everybody", 15);
	Game g2("Tetris", "Mature", 29.99);
	Game g3("Solitaire", "Teen", 11.99);
	Game g4("Solitaire on Sale", "Teen", 5.20);

	// Gets & Sets & Operator Overload functioning
	cout << g1 << endl;
	cout << g2 << endl;
	cout << g3 << endl;

	// Calling Copy Constructor
	g3 = g4;

	cout << g3 << endl;

	GameStorage A;
	A.Set(0, g1);
	A.Set(1, g2);
	A.Set(2, g3);
	
	// Functions
	A.Get(1);

	// Functions
	cout << A.PriceTotal() << endl;

	// Functions
	cout << A.Size() << endl;

	// Functions
	Game returnedGame;
	cout << A.FindByTitle("Minecraft", returnedGame) << endl;

	// Functions
	cout << A.GamePriceCount(12, 30) << endl;

	// Functions
	cout << A.getAuthor() << endl;

	// Functions
	Game g = A.MostExpensive();
	cout << g << endl;

	*/
}