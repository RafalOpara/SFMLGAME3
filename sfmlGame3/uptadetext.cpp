#include "Game.h"




void Game::uptade()
{


	this->poolEvents();




	if (!this->endGame)
	{
		this->uptadeTime();
		this->uptadePoints();



		this->uptadeTextIn();


		if (this->enterPressed == true)
		{
			this->uptadeTextOut();
			this->uptadeTextDown();
		}
	}

}


void Game::uptadeTextIn()
{



	if (this->enterPressed == true)
	{
		this->textIn.setString("");
	}



	std::stringstream so;

	for (char letter : letters)
	{
		so << letter;
	}

	this->textIn.setString(so.str());
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

	this->uptadeColor();


}

void Game::uptadeTextDown()
{
	std::stringstream so;
	std::stringstream so2;

	this->textDown.setString("");
	this->textDown2.setString("");

	//float lastWordX;
	//float lastWordY;

	

	
	for (int i = 0; i < this->correctWords.size(); i++) 
	{
		if (i < 8)
		{
			so << this->correctWords[i];
			so << "    ";
		}
		else
		{
			so2 << this->correctWords[i];
				so2 << "    ";
		}
	}


	this->textDown.setString(so.str());
	this->textDown2.setString(so2.str());

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






void Game::uptadeTime()
{
	

	if (clock.getElapsedTime().asSeconds() >= 1.0)
	{
		this->time_left--;

		clock.restart();
	}


	// wyświetl upływający czas na ekranie

	std::stringstream timeString;
	timeString << "Czas gry: " << std::fixed << std::setprecision(1) << time_left << " s";

	sf::Text timeText(timeString.str(), fontPlus, 1);
	
	

	this->textTime.setString(timeString.str());

	this->textTime.setPosition(800, 35);

	
	if (time_left < 0.0)
	{
		this->setScore(true);
		this->gameState = 3;
	}
	


	if (time_left >= 20)
	{
		textTime.setFillColor(sf::Color::White);
	}
	else if(time_left < 20 && time_left >10)
	{
		this->textTime.setFillColor(sf::Color::Yellow);
	}
	else if (time_left <= 10)
	{
		textTime.setFillColor(sf::Color::Red);
	}
	
	
}

void Game::uptadePoints()
{


	// wyświetl upływający czas na ekranie
	std::stringstream pointString;
	pointString << "Punkty: " << this->points;

	sf::Text pointText(pointString.str(), fontPlus, 1);


	this->textPoints.setString(pointString.str());

	this->textPoints.setPosition(800, 70);


}

void Game::endMenu()
{



	std::stringstream so1;
	std::stringstream so2;
	std::stringstream so3;
	std::stringstream so4;

	this->menuExit.setString("");
	this->menuStart.setString("");
	this->menuDescribe.setString("");
	this->menuOptions.setString("");



	this->menuStart.setString(so1.str());
	this->menuDescribe.setString(so2.str());
	this->menuOptions.setString(so3.str());
	this->menuExit.setString(so4.str());


	so1 << "Punkty: " << this->points;
	this->menuStart.setString(so1.str());

	so2 << "Play Again";
	this->menuDescribe.setString(so2.str());

	so3 << "Back to menu";
	this->menuOptions.setString(so3.str());

	so4 << "EXIT";
	this->menuExit.setString(so4.str());

	this->menuStart.setPosition(this->videoMode.width / 2.f, (this->videoMode.height * 0.2));
	this->menuDescribe.setPosition(this->videoMode.width / 2.f, (this->videoMode.height * 0.4));
	this->menuOptions.setPosition(this->videoMode.width / 2.f, (this->videoMode.height * 0.6));
	this->menuExit.setPosition(this->videoMode.width / 2.f, (this->videoMode.height * 0.8));

	this->menuStart.setCharacterSize(60);

	if (this->menuPick == 1) { (this->menuStart.setFillColor(sf::Color::Green)); }
	else { this->menuStart.setFillColor(sf::Color::White); }

	if (this->menuPick == 2) { (this->menuDescribe.setFillColor(sf::Color::Green)); }
	else { this->menuDescribe.setFillColor(sf::Color::White); }

	if (this->menuPick == 3) { (this->menuOptions.setFillColor(sf::Color::Green)); }
	else { this->menuOptions.setFillColor(sf::Color::White); }

	if (this->menuPick == 4) { (this->menuExit.setFillColor(sf::Color::Green)); }
	else { this->menuExit.setFillColor(sf::Color::White); }


	sf::FloatRect textRect1 = menuExit.getLocalBounds();
	menuExit.setOrigin(textRect1.left + textRect1.width / 2.0f, textRect1.top + textRect1.height / 2.0f);

	sf::FloatRect textRect2 = menuStart.getLocalBounds();
	menuStart.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);

	sf::FloatRect textRect3 = menuDescribe.getLocalBounds();
	menuDescribe.setOrigin(textRect3.left + textRect3.width / 2.0f, textRect3.top + textRect3.height / 2.0f);

	sf::FloatRect textRect4 = menuOptions.getLocalBounds();
	menuOptions.setOrigin(textRect4.left + textRect4.width / 2.0f, textRect4.top + textRect4.height / 2.0f);






}

void Game::uptadeColor()
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



void Game::uptadeMenu()
{


	std::stringstream so1;
	std::stringstream so2;
	std::stringstream so3;
	std::stringstream so4;

	this->menuExit.setString("");
	this->menuStart.setString("");
	this->menuDescribe.setString("");
	this->menuOptions.setString("");

	

	this->menuStart.setString(so1.str());
	this->menuDescribe.setString(so2.str());
	this->menuOptions.setString(so3.str());
	this->menuExit.setString(so4.str());


;	so1 << "START";
this->menuStart.setString(so1.str());

so2 << "DESCRIBE";
this->menuDescribe.setString(so2.str());

so3 << "OPTIONS";
this->menuOptions.setString(so3.str());

so4 << "EXIT";
this->menuExit.setString(so4.str());

	this->menuStart.setPosition(this->videoMode.width / 2.f, (this->videoMode.height * 0.2));
	this->menuDescribe.setPosition(this->videoMode.width / 2.f, (this->videoMode.height * 0.4));
	this->menuOptions.setPosition(this->videoMode.width / 2.f, (this->videoMode.height * 0.6));
	this->menuExit.setPosition(this->videoMode.width / 2.f, (this->videoMode.height * 0.8));


	if (this->menuPick == 1) { (this->menuStart.setFillColor(sf::Color::Green)); }
	else { this->menuStart.setFillColor(sf::Color::White); }

	if (this->menuPick == 2) { (this->menuDescribe.setFillColor(sf::Color::Green)); }
	else { this->menuDescribe.setFillColor(sf::Color::White); }

	if (this->menuPick == 3) { (this->menuOptions.setFillColor(sf::Color::Green)); }
	else { this->menuOptions.setFillColor(sf::Color::White); }

	if (this->menuPick == 4) { (this->menuExit.setFillColor(sf::Color::Green)); }
	else { this->menuExit.setFillColor(sf::Color::White); }


	sf::FloatRect textRect1 = menuExit.getLocalBounds();
	menuExit.setOrigin(textRect1.left + textRect1.width / 2.0f, textRect1.top + textRect1.height / 2.0f);

	sf::FloatRect textRect2 = menuStart.getLocalBounds();
	menuStart.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top + textRect2.height / 2.0f);

	sf::FloatRect textRect3 = menuDescribe.getLocalBounds();
	menuDescribe.setOrigin(textRect3.left + textRect3.width / 2.0f, textRect3.top + textRect3.height / 2.0f);

	sf::FloatRect textRect4 = menuOptions.getLocalBounds();
	menuOptions.setOrigin(textRect4.left + textRect4.width / 2.0f, textRect4.top + textRect4.height / 2.0f);



}

