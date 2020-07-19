#include "include/game.hpp"
#include "include/window/button.hpp"

using namespace Game;

void game::InitializeWindow()
{
	this->window = new sf::RenderWindow(this->config.video_mode, "SFML works!");
	platform.setIcon(this->window->getSystemHandle());

	this->gui = new Window();
	this->gui->SetSize(this->config.video_mode.width, this->config.video_mode.height);

	Button* btn = new Button(this->gui);
	btn->SetSize(120, 50);
	btn->SetName("button");

	windows.insert(btn);
}

void game::Render()
{
	// sf::CircleShape shape(this->window->getSize().x / 2);
	// shape.setFillColor(sf::Color::White);

	// sf::Texture shapeTexture;
	// shapeTexture.loadFromFile("content/sfml.png");
	// shape.setTexture(&shapeTexture);

	// sf::RectangleShape btn(sf::Vector2f(120, 50));

	std::for_each(windows.begin(), windows.end(), [this](sf::Drawable* w) {
		this->window->draw(*w);
	});
}