#include "include/game.hpp"

using namespace Game;

game::game(sf::RenderWindow* window)
{
	this->window = window;
}

game::~game()
{
}

void game::Update()
{
	sf::Event event;

	while (this->window->pollEvent(event))
	{
		HandlePollEvent(event);
	}
}
