
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include<sstream>
#include <time.h>
#include <conio.h>
#include <math.h>



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

	//mous positions
	
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//resources

	sf::Font fontIn;
	sf::Font fontOut;

	//text

	std::stringstream so;
	std::stringstream si;

	sf::Text textIn;
	sf::Text textOut;

	//text vector

	std::vector<char> letters; //FOR CIN
	std::vector<std::string> words; //FOR COUT



	//document with words

	std::fstream TextFile;


	//

	bool endGame;
	bool enterPressed;
	bool actionDone;
	int startTime;
	int stopTime;
	



	//private funcktions


	void initializeVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initWords();
	void initTextFile();
	void initTime();
	void initbackgroundTexture();

public:
	//constructor destructor
	Game();
	virtual ~Game();

	//accessors
	
	const bool running() const;
	const bool getEndGame() const;

	//public functions


	void poolEvents();
	void uptadeMousePositions();
	void uptadeTextIn();
	void uptadeTextOut();
	void uptadeTime();
	void setbackgroundTexture();
	void uptade();

	void renderText(sf::RenderTarget& target);
	void render();
	void renderbackGround();

};