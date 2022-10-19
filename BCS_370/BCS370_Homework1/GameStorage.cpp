//****************************************************
// File: GameStorage.cpp
//
// Purpose: Store a collection of Game. This class will be used to keep track of data for
//			multiple games
//
// Written By: Xhovani Mali
//
// Compiler: Visual C++ 2019
//****************************************************

#include "game.h"
#include "GameStorage.h"


//****************************************************
// Function: GameStorage
//
// Purpose: Default Constructor for Class GameStorage
//****************************************************
GameStorage::GameStorage()
{
	for (int index = 0; index < 3; index++)
	{
		g[index].setTitle("N/A");
		g[index].setPrice(59.99);
		g[index].setEsrb("Everybody");
	}
}

//****************************************************
// Function: Set
//
// Purpose: Sets the value at the given index to the given Game
//****************************************************
void GameStorage::Set(int index, Game g)
{
	cout << index << ": " << endl;
	
	if (index > 0 || index < 3)
	{
		cout << "Index is valid" << endl;
		// Sets the value at the given index
	}
	else
	{
		cout << "Index is not valid" << endl;
		return;
	}
}

//****************************************************
// Function: Get
//
// Purpose: Return the Game located at element index of the array.
//****************************************************
Game GameStorage::Get(int index)
{
	return g[index];
}

//****************************************************
// Function: GamePriceCount
//
// Purpose: Returns the count of the number of games in the given range
//****************************************************
int	GameStorage::GamePriceCount(double lowerBound, double upperBound)
{
	int count = 0; 

	for (int index = 0; index < 3; index++)
	{
		double price = g[index].getPrice();

		while (price >= lowerBound && price <= upperBound)
		{
			count += 1;
		}
	}
	return count;
}

//****************************************************
// Function: MostExpensive
//
// Purpose: Returns the game with the highest price in the array
//****************************************************
Game GameStorage::MostExpensive()
{
	double MostExpensive;

	for (int i = 0; i < 3; i++)
	{
		double priceA = g[i].getPrice();
		double priceB = g[i - 1].getPrice();

		if (priceA > priceB)
		{
			MostExpensive = priceA;
		}
		else
		{
			MostExpensive = priceB;
		}
	}
	return g[index];
}

//****************************************************
// Function: FindByTitle
//
// Purpose: Returns true if the game with the given name is in the array and false otherwise
//****************************************************
bool GameStorage::FindByTitle(string name, Game& g)
{
	return true;
}

//****************************************************
// Function: PriceTotal
//
// Purpose: Returns the sum of all Game prices in the collection
//****************************************************
double GameStorage::PriceTotal()
{
	double PriceTotal = 0;

	for (int index = 0; index < 3; index++)
	{
		double price = g[index].getPrice();
		PriceTotal = PriceTotal + price;
	}

	return PriceTotal;
}

//****************************************************
// Function: Size
//
// Purpose: Returns the size of the array.
//****************************************************
int GameStorage::Size()
{
	int Size = 0; 

	for (int index = 0; index < 100; index++)
	{
		if (g[index].getTitle() != "Default")
		{
			Size++;
		}
		else
		{
			return Size;
		}
	}
}

//****************************************************
// Function: Initialize
//
// Purpose: Initializes all of the elements of the array to reasonable default values.
//****************************************************
void GameStorage::Initialize()
{
	for (int index = 0; index < 3; index++)
	{
		g[index].setTitle("N/A");
		g[index].setPrice(59.99);
		g[index].setEsrb("Everybody");
	}
}

//****************************************************
// Function: GetAuthor
//
// Purpose: Returns your name.
//****************************************************
string GameStorage::getAuthor()
{
	string Name = "Xhovani Mali";

	return Name;
}