// Zorklon.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"


#include "world.h";
#include "input.h";

using namespace std;

World zorklonWorld;
Input input(zorklonWorld.player);

int main()
{
	string player_input;
	bool endGame = false;

	while (!endGame)
	{
		endGame = input.getPlayerInput();
		endGame = endGame || zorklonWorld.player->isDead();
	}

	cout << "\nThanks for playing!\n";
	getline(cin, player_input);
	return 0;
}

