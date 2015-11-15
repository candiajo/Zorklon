#pragma once

#include <string>

using namespace std;

class Player;

class Input
{
public:
	Input(Player* player);
	~Input();

	bool getPlayerInput();


private:
	Player* player;
	string rawInput = "";
	string word1 = "";
	string word2 = "";
};