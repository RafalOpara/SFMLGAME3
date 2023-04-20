#include "Game.h"

// funcktions

void Game::initializeVariables()
{
	this->window = nullptr;

	//game values


	bool endGame = false;
	bool score = false;
	bool enterPressed = false;;
	bool actionDone = false;;
	
	 this->count = 0;
	 this-> points = 0;

	this->time_left = 30;

	this->gameState = 2;

	std::string temp_word;

	


	
}



void Game::initWindow()
{
	this->videoMode.height = 534;
	this->videoMode.width = 1024;

	this->window = new sf::RenderWindow(this->videoMode, "My first game", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initbackgroundTexture()
{
	if (this->backgroundTexture.loadFromFile("F:/VS projekty/sfmlgame3/sfmlGame3/sfmlGame3/resources/board.png")) {
		std::cout << "CORRECT: BACKGROUND" << std::endl;
	}

	
}



Game::Game()
{
	
	this->initializeVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
	this->initTextFile();
	this->initWords();
	this->initbackgroundTexture();
	this->setbackgroundTexture();
	

	
}

Game::~Game()
{
	delete this->window;
}


//accessors
const bool Game::running() const
{

	return this->window->isOpen();
}
const bool Game::getEndGame() const
{
	return this->endGame;
}

const bool Game::getScore() const
{
	return this->score;
}

void Game::setEndGame(bool value) {
	this->endGame = value;
}

void Game::setScore(bool value) {
	this->score = value;
}


int Game::getGameState()
{
	return this->gameState;
}

void Game::setGameState(int newState)
{
	this->gameState = newState;
}



void Game::poolEvents()
{
	//event polling

	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;

			if (this->gameState == 2)
			{


				case sf::Event::TextEntered:

				if (this->ev.text.unicode < 128) // sprawdzenie, czy wprowadzony znak jest znakiem ASCII
				{



					if (this->ev.text.unicode == 13)
					{
						if (textIn.getFillColor() == sf::Color::Green && this->letters.size() == this->temp_word.size())
						{
							this->points++;
							this->time_left = this->time_left + 1;
							this->correctWords.push_back(temp_word);


							this->letters.clear();
							this->letters.shrink_to_fit();
							this->enterPressed = true;
							this->count = 0;
						}


					}


					else if (this->ev.text.unicode == 8)
					{
						if (this->letters.size() > 0)
						{
							this->letters.pop_back();



							if (this->count != 0)
							{
								this->count--;
								this->uptadeColor();

							}


						}

					}

					else
					{



						if (this->count != this->temp_word.size())
						{
							this->letters.push_back(static_cast<char>(this->ev.text.unicode));



							if (this->count != this->temp_word.size())
							{
								this->count++;
							}

							this->uptadeColor();

						}


					}

				}
			}
			else if (gameState = 1)
			{
				/
			}

		}


	}

}




