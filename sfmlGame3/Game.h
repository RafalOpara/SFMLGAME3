
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
#include <chrono>



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

	
	
	

	//resources

	sf::Font fontIn;
	sf::Font fontOut;
	sf::Font fontDown;
	sf::Font fontPlus;

	//text

	sf::Text textIn;
	sf::Text textOut;
	sf::Text textDown;
	sf::Text textDown2;
	sf::Text textTime;
	sf::Text textPoints;
	sf::Text endScorePoints;
	sf::Text menuStart;
	sf::Text menuDescribe;
	sf::Text menuExit;
	sf::Text menuOptions;

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

	enum gameState; 
	gameState state_;

	int count;
	int points;
	std::string temp_word;

	int gameState;
	
	
	/// time
	///////////////////////////////
	
	int time_left;

	sf::Clock clock;
	sf::Time elapsed_time = clock.getElapsedTime();


	//////////////////


	sf::RenderWindow m_window;
	
	


	///////////////////////test
	//private funcktions

	void setbackgroundTexture();
	void uptadeColor();
	


	void setEndGame(bool value);
	void setScore(bool value);
	



	void initializeVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initWords();
	void initTextFile();
	void initStart_time();
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

	/// gameState



	//public functions


	int getGameState();
	void setGameState(int);

	void poolEvents();
	void uptadeMousePositions();
	void uptadeTextIn();
	void uptadeTextOut();
	void uptadeMenu();

	void uptadeTextDown();
	void uptadeTime();
	void uptadePoints();
	void uptade();
	

	void render();
	void endRender();
	void menuRender();
	void renderbackGround();

	void renderText(sf::RenderTarget& target);
	void renderScore(sf::RenderTarget& target);
	void renderMenu(sf::RenderTarget& target);

	void endScore();
	

};