#include "Game.h"
#include <iostream>

using namespace std;





int main()
{
	//init rand
	std::srand(static_cast<unsigned>(time(NULL)));

	//init game
	Game game;

	//Game loop
	while (game.running() && !game.getEndGame() )
	{

		if (game.getScore() == true)
		{

			game.endRender();

		}
		else
		{


			//uptade
			game.uptade();

			//render
			game.render();

		}
	}
	//End

	return 0;

}