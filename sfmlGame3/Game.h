
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include<sstream>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <cctype>
#include <iomanip>




#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


class Game
{
	//window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;

	sf::Texture backgroundTexture;
	sf::Sprite background;

	//underline


	//mous positions
	
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//resources

	sf::Font fontIn;
	sf::Font fontOut;
	sf::Font fontDown;
	sf::Font fontPlus;

	//text

	std::stringstream so;
	std::stringstream si;
	std::stringstream sd;
	std::stringstream sd2;
	std::stringstream st;

	sf::Text textIn;
	sf::Text textOut;
	sf::Text textDown;
	sf::Text textDown2;
	sf::Text textTime;
	sf::Text textPoints;
	sf::Text endScorePoints;

	//text vector

	std::vector<char> letters; //FOR CIN
	std::vector<std::string> words; //FOR COUT
	std::vector<std::string> correctWords;



	//document with words

	std::fstream TextFile;


	//

	bool endGame;
	bool score;


	bool enterPressed;
	bool actionDone;

	int startTime;
	int stopTime;
	float gameTime;

	int count;
	int points;
	std::string temp_word;
	/////////////////////test


	sf::RenderWindow m_window;
	sf::Clock m_clock;
	float m_gameTime; // czas gry w sekundach


	///////////////////////test
	//private funcktions

	void setbackgroundTexture();
	void logic();
	


	void setEndGame(bool value);
	void setScore(bool value);


	void initializeVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initWords();
	void initTextFile();
;
	void initbackgroundTexture();

public:
	//constructor destructor
	Game();
	virtual ~Game();

	//accessors
	
	const bool running() const;
	const bool getEndGame() const;
	const bool getScore() const;

	//public functions


	void poolEvents();
	void uptadeMousePositions();
	void uptadeTextIn();
	void uptadeTextOut();

	void uptadeTextDown();
	void uptadeTime();
	void uptadePoints();
	void uptade();
	void renderText(sf::RenderTarget& target);
	void render();
	void endRender();
	void renderbackGround();

	void renderScore(sf::RenderTarget& target);

	void endScore();
	

};