#include "include/game.hpp"

using namespace Game;

game::game()
{
	this->window = nullptr;
	this->gui = nullptr;

	InitializeWindow();
	InitializeVariables();
}

game::~game()
{
	delete this->window;
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
