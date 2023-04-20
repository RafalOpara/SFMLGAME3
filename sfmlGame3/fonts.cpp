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

	if (this->fontPlus.loadFromFile("Fonts/plus.ttf"))
	{
		std::cout << "CORRECT: Extra fonts " << std::endl;
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


	//INIT TEXT FOR TIME and points


	this->textPoints.setFont(this->fontPlus);
	this->textPoints.setCharacterSize(40);
	this->textPoints.setFillColor(sf::Color::White);


	this->textTime.setFont(this->fontPlus);
	this->textTime.setCharacterSize(40);
	this->textTime.setFillColor(sf::Color::White);


	this->endScorePoints.setFont(this->fontPlus);
	this->endScorePoints.setCharacterSize(40);
	this->endScorePoints.setFillColor(sf::Color::White);


	//INIT TEXT FOR CORRECT WORDS

	this->textDown.setFont(this->fontDown);
	this->textDown.setCharacterSize(20);
	this->textDown.setFillColor(sf::Color::White);

	this->textDown2.setFont(this->fontDown);
	this->textDown2.setCharacterSize(20);
	this->textDown2.setFillColor(sf::Color::White);


	/// init text for menu 

	this->menuStart.setFont(this->fontPlus);
	this->menuStart.setCharacterSize(40);
	this->menuStart.setFillColor(sf::Color::Green);

	this->menuDescribe.setFont(this->fontPlus);
	this->menuDescribe.setCharacterSize(40);
	this->menuDescribe.setFillColor(sf::Color::White);

	this->menuOptions.setFont(this->fontPlus);
	this->menuOptions.setCharacterSize(40);
	this->menuOptions.setFillColor(sf::Color::White);

	this->menuExit.setFont(this->fontPlus);
	this->menuExit.setCharacterSize(40);
	this->menuExit.setFillColor(sf::Color::White);

}
