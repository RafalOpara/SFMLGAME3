#include "Game.h"



//cos z tym count +1 trzeba zrbic bo albo nie czyta znaku nie biezaco albo przy backspace sie pierodli





void Game::logic()
{


	for (int i = 0; i < this->count; i++)
	{
		if (tolower(this->letters[i]) == tolower(this->temp_word[i]))
		{
			this->textIn.setFillColor(sf::Color::Green);
		}
		else
		{
			this->textIn.setFillColor(sf::Color::Yellow);
		}

	}

	
}

