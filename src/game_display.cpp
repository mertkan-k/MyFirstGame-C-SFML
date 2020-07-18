#include "include/game.hpp"

using namespace Game;

void game::RefreshDisplay()
{
	sf::CircleShape shape(this->window->getSize().x / 2);
	shape.setFillColor(sf::Color::White);

	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/sfml.png");
	shape.setTexture(&shapeTexture);
	this->window->draw(shape);
}