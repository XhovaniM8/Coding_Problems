//****************************************************
// File: GameStorage.h
//
// Purpose: Store a collection of Game. This class will be used to keep track of data for
//			multiple games
//
// Written By: Xhovani Mali
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
	Game g[3];
	int index = 0;

public:
	// Constructor 
	GameStorage();

	// Functions comments on source file
	void Set(int index, Game g);

	Game Get(int index);

	Game MostExpensive();

	int GamePriceCount(double lowerBound, double upperBound);

	bool FindByTitle(string name, Game& g);

	double PriceTotal();

	int Size();

	void Initialize();

	string getAuthor();
};

