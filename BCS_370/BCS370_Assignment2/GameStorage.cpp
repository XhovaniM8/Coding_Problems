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
//				Updated functions to loop to the sizeofArray. 
//
// Compiler: Visual C++ 2019
//****************************************************

#include "game.h"
#include "GameStorage.h"

//****************************************************
// Function: GameStorage
//
// Purpose: Deletes instances of Game
//****************************************************
GameStorage::~GameStorage()
{
	cout << "Game Array Deleted !!!" << endl;

	delete[] gameArray;
	gameArray = nullptr;
}

//****************************************************
// Function: GameStorage
//
// Purpose: Dynamically allocate an array of the given 
//			size.
//****************************************************
GameStorage::GameStorage(int newsizeofArray)
{
	sizeofArray = newsizeofArray;
	gameArray = new Game[newsizeofArray];

	cout << "Size of Dynamically Allocated Array is: " 
		 << newsizeofArray << endl;
}

//****************************************************
// Function: Copy Constructor
//
// Purpose: This function should make a deep copy of 
//			the passed in instance.
//****************************************************
GameStorage::GameStorage(const GameStorage& rhs)
{
	sizeofArray = rhs.sizeofArray;
}

//****************************************************
// Function: GameStorage
//
// Purpose: Default Constructor for Class GameStorage
//
// Update Information
// ------------------
//
// Date:
// Description:
//
//****************************************************
GameStorage::GameStorage()
{
	gameArray = new Game[sizeofArray];

	Initialize();
	cout << "Initialized" << endl;
	cout << "New Array Created" << endl;
}


//****************************************************
// Function: Resize
//
// Purpose: This function should create a new array
//			that has the passed in size.
//****************************************************
void GameStorage::Resize(int newSize)
{
	Game* tempgameArray = new Game[newSize];

}

//****************************************************
// Function: DeepCopy
//
// Purpose: This function should allocate a new dynamic
//			instance of GameStorage that is a deep copy 
//			of the current instance.
//****************************************************
/*
GameStorage* GameStorage::DeepCopy()
{
	Game *tempgameArray = new Game[sizeofArray];
	GameStorage temp;
	GameStorage* copy;

	for (int i = 0; i < sizeofArray; i++)
	{
		tempgameArray[i] = Get(i);

		for (int j = 0; j < sizeofArray; j++)
		{
			temp.Set(j, *tempgameArray);
		}
	}

	*copy = temp;

	return copy;
}
*/


//****************************************************
// Function: Set
//
// Purpose: Sets the value at the given index to the 
//			given Game
//
// Update Information
// ------------------
//
// Date:
// Description:
//
//****************************************************
void GameStorage::Set(int index, Game g)
{
	cout << index << ": " << endl;
	
	if (index > 0 || index < sizeofArray)
	{
		gameArray[index] = g;
		cout << "Index is valid: Index is set to: " << endl;
	}
	else
	{
		cout << "Index is not valid";
		return;
	}
}

//****************************************************
// Function: Get
//
// Purpose: Return the Game located at element index of
//			the array.
//
// Update Information
// ------------------
//
// Date:
// Description:
//
//****************************************************
Game GameStorage::Get(int index)
{
	return gameArray[index];
}

//****************************************************
// Function: MostExpensive
//
// Purpose: Returns the game with the highest price in 
//			the array
//
// Update Information
// ------------------
//
// Date: 10/8/2021
// Description: Changed "index < 3" to "index < sizeofArray"
//
//****************************************************
Game GameStorage::MostExpensive()
{
	Game maxGame;
	maxGame = gameArray[0];

	for (int i = 0; i < sizeofArray; i++)
	{
		if (gameArray[i].getPrice() > maxGame.getPrice())
		{
			maxGame = gameArray[i];
		}
	}

	cout << "The most expensive game is: ";
	return maxGame;
}

//****************************************************
// Function: GamePriceCount
//
// Purpose: Returns the count of the number of games 
//			in the given range
//
// Update Information
// ------------------
//
// Date: 10/8/2021
// Description: Changed "index < 3" to "index < sizeofArray"
//
//****************************************************
int	GameStorage::GamePriceCount(double lowerBound, double upperBound)
{
	int count = 0; 

	for (int index = 0; index < sizeofArray; index++)
	{
		double price = gameArray[index].getPrice();
		if (price >= lowerBound && price <= upperBound)
		{
			count = count += 1;
		}
	}

	cout << "Game's within these bounds: ";
	return count;
}

//****************************************************
// Function: FindByTitle
//
// Purpose: Returns true if the game with the given name
//			is in the array and false otherwise
//
// Update Information
// ------------------
//
// Date: 10/8/2021
// Description: Changed "index < 3" to "index < sizeofArray"
//
//****************************************************
bool GameStorage::FindByTitle(string name, Game& g)
{
	for (int i = 0; i < sizeofArray; i++)
	{
		if (gameArray[i].getTitle() == name)
		{
			g = gameArray[i];
			cout << "Title found: ";
			return true;
		}
	}
	cout << "Title not found: ";
	return false;
}

//****************************************************
// Function: PriceTotal
//
// Purpose: Returns the sum of all Game prices in the collection
//
// Update Information
// ------------------
//
// Date: 10/8/2021
// Description: Changed "index < 3" to "index < sizeofArray"
//
//****************************************************
double GameStorage::PriceTotal()
{
	double PriceTotal = 0;

	for (int index = 0; index < sizeofArray; index++)
	{
		double price = gameArray[index].getPrice();
		PriceTotal = PriceTotal + price;
	}

	cout << "Price Total is: ";
	return PriceTotal;
}

//****************************************************
// Function: Size
//
// Purpose: Returns the size of the array.
//
// Update Information
// ------------------
//
// Date: 10/8/2021
// Description: returns sizeofArray instead of 3
//
//****************************************************
int GameStorage::Size()
{
	cout << "Size is: ";
	return sizeofArray;
}

//****************************************************
// Function: Initialize
//
// Purpose: Initializes all of the elements of the 
//			array to reasonable default values.
//
// Update Information
// ------------------
//
// Date: 10/8/2021
// Description: Changed "index < 3" to "index < sizeofArray"
//
//****************************************************
void GameStorage::Initialize()
{
	for (int index = 0; index < sizeofArray; index++)
	{
		gameArray[index].setTitle("N/A");
		gameArray[index].setPrice(59.99);
		gameArray[index].setEsrb("Everybody");
	}
}

//****************************************************
// Function: GetAuthor
//
// Purpose: Returns author's name.
//
// Update Information
// ------------------
//
// Date:
// Description:
//
//****************************************************
string GameStorage::getAuthor()
{
	string Name = "Xhovani Mali";
	return Name;
}

//****************************************************
// Function: Non-Member Operator<< Overload
//
// Purpose: To allow class to output in console
//
// Update Information
// ------------------
//
// Date: 10/8/2021
// Description:
//
//****************************************************
ostream& operator<<(ostream& os, GameStorage& rhs)
{
	os << rhs.index << endl;

	for (int i = 0; i < rhs.sizeofArray; i++)
	{
		os << rhs.gameArray[i] << endl;
	}

	return os;
}

//****************************************************
// Function: Member Overload for the Assignment Operator.
//
// Purpose: To allow class to deep copy
//
// Update Information
// ------------------
//
// Date: 10/7/2021
// Description: Function should make a deep copy of the passed in
//				instance.
//
//****************************************************
const GameStorage& GameStorage::operator=(const GameStorage& rhs)
{
	if (this == &rhs)
		return  *this;

	index = rhs.index;
	sizeofArray = rhs.sizeofArray;

	for (int i = 0; i < rhs.sizeofArray; i++)
	{
		gameArray[i] = rhs.gameArray[i];
	}

	return *this;
}