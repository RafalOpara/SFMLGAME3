#include "Game.h"

// funcktions

void Game::initializeVariables()
{
	this->window = nullptr;

	//game values


	bool endGame = false;
	int startTime=0;
	int stopTime=0;


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
	if (this->backgroundTexture.loadFromFile("F:/VS projekty/sfmlgame3/sfmlGame3/sfmlGame3/resources/tablica.png")) {
		std::cout << "tło sie nie ładuje" << std::endl;
	}

	
}

void Game::initFonts()
{
	if (this->font.loadFromFile("Fonts/Dosis-Light.ttf"))
	{
		std::cout << "error error error error F O N T S " << std::endl;
	}

}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(sf::Color::White);
	this->uiText.setString("NONE");
}

Game::Game()
{
	this->initializeVariables();
	this->initWindow();
	this->initFonts();
	this->initText();
	this->initbackgroundTexture();
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


void Game::uptadebackgroundTexture()
{
	this->background.setTexture(this->backgroundTexture);
}

void Game::uptadeText()
{
	std::stringstream ss;

	//ss << "Points: " << this->points << std::endl;
	//ss << "Health: " << this->health << std::endl;
	//ss << "Time: " << this->gameTime << std::endl;

	this->uiText.setString(ss.str());
}


void Game::uptade()
{
	this->poolEvents();

	if (!this->endGame)
	{

		this->uptadeMousePositions();
		this->uptadeTime();
		this->uptadeText();
		this->uptadebackgroundTexture();
		

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
	target.draw(this->uiText);
}

void Game::render()
{
	this->window->clear();

	// draw 

	this->renderText(*this->window);

	this->renderbackGround();
		
	this->window->display();
}
