#include "Game.h"

void Game::renderbackGround()
{
	this->window->draw(this->background);
}





/// ////////////////////////////


void Game::renderMenu(sf::RenderTarget& target)
{
	target.draw(this->menuStart);
	target.draw(this->menuDescribe);
	target.draw(this->menuOptions);
	target.draw(this->menuExit);
}

void Game::menuRender()
{
	this->poolEvents();
	this->window->clear();
	this->renderbackGround();
	this->uptadeMenu();
	this->renderMenu(*this->window);
	this->window->display();

}
///////////////////////////////////
void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->textOut);
	target.draw(this->textIn);
	target.draw(this->textDown);
	target.draw(this->textDown2);
	target.draw(this->textTime);
	target.draw(this->textPoints);
}



void Game::render()
{
	this->window->clear();

	// draw 

	this->renderbackGround();


	this->renderText(*this->window);



	this->window->display();
}
///////////////////////////////////

void Game::renderScore(sf::RenderTarget& target)
{
	target.draw(this->endScorePoints);
}

void Game::endRender()
{
	this->poolEvents();
	this->window->clear();
	this->renderbackGround();
	this->endMenu();
	this->renderMenu(*this->window);
	this->window->display();

}