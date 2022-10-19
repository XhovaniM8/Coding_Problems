//****************************************************
// File: GameStorage.cpp
//
// Purpose: Store a collection of Game. This class will be used to keep track of data for
//			multiple games
//
// Written By: Xhovani Mali
//
// Update Information
// ------------------
//
// Date: 10/4/2021
// Description: Added updates to make GameStorage function with pointers
//
// Date: 10/8/2021
// Description: Added deconstructor, constructor with a sizeofArray parameter
//				copy constructor, deepcopy function, and a resize function. 
//
// Compiler: Visual C++ 2019
//****************************************************

#pragma once
#include "game.h"
#include <string>
#include <iostream>
using namespace std;

class GameStorage
{
private: 
	Game* gameArray;
	int index = 0;
	int sizeofArray = 3;

public:
	// Destructor
	~GameStorage();

	// One Parameter Constructor
	GameStorage(int sizeofArray);

	// Copy Constructor
	GameStorage(const GameStorage& rhs);

	// Default Constructor
	GameStorage();
	
	// Sets & Gets
	void Set(int index, Game g);
	Game Get(int index);

	// Returns the game with the highest price in the array
	Game MostExpensive();

	// Returns the count of the number of games in the given range
	int GamePriceCount(double lowerBound, double upperBound);

	// Returns true if the game with the given name is in the array and false otherwise
	bool FindByTitle(string name, Game& g);

	// Returns the sum of all Game prices in the collection
	double PriceTotal();

	// Returns the size of the array
	int Size();

	// Initializes all of the elements of the array to reasonable default values
	void Initialize();

	//  Returns author's name
	string getAuthor();

	// This function should create a new array that has the passed in size.
	void Resize(int newSize);

	// This function should allocate a new dynamic instance of GameStorage that is a deep
	// copy of the current instance.
	GameStorage* DeepCopy();

	// Member overload of operator =
	const GameStorage& operator=(const GameStorage& rhs);

	// Member overload of operator <<
	friend ostream& operator<<(ostream& os, GameStorage& rhs);
};

