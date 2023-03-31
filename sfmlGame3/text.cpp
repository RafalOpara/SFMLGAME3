#include "Game.h"



void Game::uptadeTextIn()
{



	if (this->enterPressed == true)
	{
		this->textIn.setString("");
	}



	std::stringstream si;

	for (char letter : letters)
	{
		si << letter;
	}

	this->textIn.setString(si.str());
	sf::FloatRect textRectIn = textIn.getLocalBounds();
	this->textIn.setOrigin(textRectIn.left + textRectIn.width / 2.0f, textRectIn.top + textRectIn.height / 2.0f);
	this->textIn.setPosition(this->window->getSize().x / 2.0f, this->window->getSize().y / 2.0f);



}

void Game::uptadeTextOut()
{

	std::stringstream so;

	this->textOut.setString("");

	int randWord;

	randWord = std::rand() % this->words.size();
	so << this->words[randWord];
	this->textOut.setString(so.str());
	this->enterPressed = false;

	this->temp_word = words[randWord];

	sf::FloatRect textRectOut = textOut.getLocalBounds();
	this->textOut.setOrigin(textRectOut.left + textRectOut.width / 2.0f, textRectOut.top + textRectOut.height / 2.0f);
	this->textOut.setPosition(this->window->getSize().x / 2.0f, 95.0f);

	this->logic();


}

void Game::uptadeTextDown()
{
	std::stringstream sd;
	std::stringstream sd2;

	this->textDown.setString("");
	this->textDown2.setString("");

	//float lastWordX;
	//float lastWordY;

	

	
	for (int i = 0; i < this->correctWords.size(); i++) 
	{
		if (i < 8)
		{
			sd << this->correctWords[i];
			sd << "    ";
		}
		else
		{
			sd2 << this->correctWords[i];
				sd2 << "    ";
		}
	}


	this->textDown.setString(sd.str());
	this->textDown2.setString(sd2.str());

	//this->textDown.setStyle(sf::Text::Underlined);


	float x = 100.f;
	float y = 350.f;

	float x2 = 100.f;
	float y2 = 375.f;




	this->textDown.setPosition(x, y);

	this->textDown2.setPosition(x2, y2);

	// Pobranie pozycji ostatniego słowa w tekście
	//sf::Vector2f lastWordPos = this->textDown.findCharacterPos(this->textDown.getString().getSize() - this->correctWords.back().size());

	// Dodanie szerokości tekstu ostatniego słowa do pozycji X
	//lastWordX += this->textDown.getFont()->getGlyph(this->correctWords.back()[0], this->textDown.getCharacterSize(), false).advance;

	//Wyświetlenie pozycji ostatniego słowa na ekranie
	//std::cout << "Pozycja ostatniego slowa: (" << lastWordX << ", " << lastWordY << ")" << std::endl;


}