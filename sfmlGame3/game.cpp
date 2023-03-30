#include "Game.h"

// funcktions

void Game::initializeVariables()
{
	this->window = nullptr;

	//game values


	bool endGame = false;
	bool enterPressed = false;;
	bool actionDone = false;;
	int startTime=0;
	int stopTime=0;
	int count = 0;
	int points = 0;

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
		case sf::Event::TextEntered:
			
			if (this->ev.text.unicode < 128) // sprawdzenie, czy wprowadzony znak jest znakiem ASCII
			{

				

				if (this->ev.text.unicode == 13)
				{
					if (textIn.getFillColor() == sf::Color::Green && this->letters.size() == this->temp_word.size())
					{
						this->points++;
						this->correctWords.push_back(temp_word);
						

						this->letters.clear();
						this->letters.shrink_to_fit();
						this->enterPressed = true;
						this->count = 0;
					}


				}


				else if(this->ev.text.unicode == 8)
				{
					if (this->letters.size() > 0)
					{
						this->letters.pop_back();

						

						if (this->count != 0)
						{
							this->count--;
							this->logic();

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

						this->logic();

					}

					
				}

			}

		}


	}

}

void Game::uptadeMousePositions()
{
	//return void uptade the mouse positions: relative to window (vector2i)

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::uptadeTime()
{
	this->stopTime = clock();
	//this->gameTime = ((double)(this->stopTime - this->startTime)) / CLOCKS_PER_SEC;
	//std::cout << gameTime;
}






void Game::uptade()
{


	this->poolEvents();

	if (!this->endGame)
	{
		this->uptadeMousePositions();
		this->uptadeTime();
		this->uptadeTextIn();
		

		if (this->enterPressed == true)
		{
			this->uptadeTextOut();
			this->uptadeTextDown();
		}
	}

	//if (this->health <= 0)
	//	this->endGame = true;
}


void Game::renderbackGround()
{
	this->window->draw(this->background);
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->textOut);
	target.draw(this->textIn);
	target.draw(this->textDown);
}

void Game::render()
{
	this->window->clear();

	// draw 

	this->renderbackGround();


	this->renderText(*this->window);


		
	this->window->display();
}
