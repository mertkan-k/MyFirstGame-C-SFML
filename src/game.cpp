#include "include/game.hpp"

using namespace Game;

game::game()
{
	this->window = nullptr;

	InitializeWindow();
	InitializeVariables();
}

game::~game()
{
	delete this->window;
}

void game::InitializeWindow()
{
	this->window = new sf::RenderWindow(this->config.video_mode, "SFML works!");
	platform.setIcon(this->window->getSystemHandle());
}

void game::InitializeVariables()
{
}

void game::Start()
{
	while (this->window->isOpen())
	{
		this->Update();

		this->window->clear();
		this->Render();
		this->window->display();
	}
}

void game::Update()
{
	while (this->window->pollEvent(event))
	{
		HandlePollEvent(event);
	}
}
