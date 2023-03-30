#include "Game.h"



void Game::setbackgroundTexture()
{
	this->background.setTexture(this->backgroundTexture);

}




void Game::initFonts()
{


	if (this->fontIn.loadFromFile("Fonts/Cute Notes.ttf"))
	{
		std::cout << "CORRECT: FONTIN  " << std::endl;
	}

	if (this->fontOut.loadFromFile("Fonts/Hanged Letters.ttf"))
	{
		std::cout << "CORRECT: FONTOUT " << std::endl;
	}



	if (this->fontDown.loadFromFile("Fonts/Downfont.ttf"))
	{
		std::cout << "CORRECT: FONTOUT " << std::endl;
	}
}



void Game::initText()
{
	//INIT TEXT IN


	this->textIn.setFont(this->fontIn);
	this->textIn.setCharacterSize(50);

	//INIT TEXT OUT

	this->textOut.setFont(this->fontOut);
	this->textOut.setCharacterSize(100);
	this->textOut.setFillColor(sf::Color::White);


	//INIT TEXT FOR TIME


	//INIT TEXT FOR CORRECT WORDS

	this->textDown.setFont(this->fontDown);
	this->textDown.setCharacterSize(50);
	this->textDown.setFillColor(sf::Color::White);

}
