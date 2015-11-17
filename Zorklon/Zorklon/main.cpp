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

	cout << "Welcome to Zorklon, you are in a old mansion and your goal is to escape. Good luck!" << endl << endl;
	zorklonWorld.player->Do("look", "room");
	while (!endGame)
	{
		endGame = input.getPlayerInput();
		endGame = endGame || zorklonWorld.player->isDead() || zorklonWorld.player->winGame;
	}

	cout << endl << "Thanks for playing!\n";
	getline(cin, player_input);
	return 0;
}

