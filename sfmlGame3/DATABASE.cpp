#include "Game.h"



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