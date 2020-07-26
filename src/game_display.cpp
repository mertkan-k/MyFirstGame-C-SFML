#include "include/game.hpp"

void Game::InitializeWindow()
{
	this->window = new sf::RenderWindow(this->config.video_mode, "SFML works!");
	platform.setIcon(this->window->getSystemHandle());

	this->gui = new Gui(this->window);
	this->gui->setSize(sf::Vector2f(config.video_mode.width, config.video_mode.height));

	InitInterfaces();
}

void Game::Render()
{
	// sf::CircleShape shape(this->window->getSize().x / 2);
	// shape.setFillColor(sf::Color::White);

	// sf::Texture shapeTexture;
	// shapeTexture.loadFromFile("content/sfml.png");
	// shape.setTexture(&shapeTexture);
	this->window->draw(*this->gui);

	this->gui->Draw();
}