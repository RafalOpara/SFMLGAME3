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

	this->textDown.setString("");

	for (std::string correctWord : this->correctWords)
	{
		sd << correctWord;
	}


	this->textDown.setString(sd.str());

	//sf::FloatRect textRectIn = textIn.getLocalBounds();
	//this->textIn.setOrigin(textRectIn.left + textRectIn.width / 2.0f, textRectIn.top + textRectIn.height / 2.0f);
	//this->textIn.setPosition(this->window->getSize().x / 2.0f, this->window->getSize().y / 2.0f);


	float x = 0.f; // Ustaw położenie tekstu względem osi x
	float y = this->videoMode.height - this->textDown.getLocalBounds().height - this->videoMode.height / 4.f; // Ustaw położenie tekstu względem osi y
	this->textDown.setPosition(x, y);
}