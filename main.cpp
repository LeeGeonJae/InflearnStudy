#include <iostream>
#include "Game.h"
#include "Creature.h"
#include "Player.h"

using namespace std;

// ø¿¥√¿« ¡÷¡¶ : TextRPG #4


int main()
{
	srand((unsigned int)time(nullptr));

	Game game;
	game.Init();

	while(true)
	{
		game.Update();
	}

	return 0;
}