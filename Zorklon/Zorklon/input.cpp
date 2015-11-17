#include "stdafx.h"
#include "input.h"
#include "world.h"
#include <locale>

Input::Input(Player* player)
{
	this->player = player;
}

bool Input::getPlayerInput()
{
	int pos;

	cout << endl << "> ";
	getline(cin, rawInput);
	
	//lowcase player input
	for (string::iterator it = rawInput.begin(); it != rawInput.end(); ++it)
		*it = tolower(*it);

	pos = rawInput.find(" ");

	if (pos == string::npos)	// there is only one word
	{
		word1 = rawInput;
		word2 = "";
	}
	else						// there are two words
	{
		word1 = rawInput.substr(0, pos);
		word2 = rawInput.substr(pos + 1, string::npos);
	}
	if (word1 == "quit")
	{
		return true;
	}
	else
	{
		player->Do(word1, word2);
		return false;
	}
}


Input::~Input()
{}