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
	Game g();
	Game g1("Civilation 6", "Everybody", 59.99);
	Game g2("Call of Duty", "Mature", 19.99);
	Game g3("Minecraft", "Teen", 90.00);

	g1.getPrice();
}