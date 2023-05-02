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
		

		if (game.getGameState() == 1)
		{
			game.menuRender();
		}

		else if (game.getGameState() == 2)
		{
			//uptade
			game.uptade();

			//render
			game.render();
		}

		else if (game.getGameState() == 3)
		{
			game.endRender();
		}


	}
	//End

	return 0;

}