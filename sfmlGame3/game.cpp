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


}

void Game::initText()
{
	this->textIn.setFont(this->fontIn);
	this->textIn.setCharacterSize(50);
	
	//this->textIn.setString();

	this->textOut.setFont(this->fontOut);
	this->textOut.setCharacterSize(100);
	this->textOut.setFillColor(sf::Color::White);
	

	



}

void Game::initTextFile()
{
	TextFile.open(("F:/VS projekty/sfmlgame3/sfmlGame3/sfmlGame3/resources/TextFile.txt"), std::ios::in);
	if (TextFile.good() == true)
	{
		std::cout << " correct: Text File";

	}
}

void Game::initWords()
{
	std::string word;


	while (TextFile >> word) { // wczytujemy słowa z pliku i dodajemy je do tablicy
		this->words.push_back(word);

	}

	int randWord;

	

	
	uptadeTextOut();

	TextFile.close(); // 
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
					this->letters.clear();
					this->letters.shrink_to_fit();
					this->enterPressed = true;
					this->count=0;
					
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
}

void Game::render()
{
	this->window->clear();

	// draw 

	this->renderbackGround();


	this->renderText(*this->window);


		
	this->window->display();
}
