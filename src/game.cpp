#include "include/Game.hpp"

Game::Game()
{
	this->window = nullptr;
	// this->gui = nullptr;

	InitializeWindow();
	InitializeVariables();
}

Game::~Game()
{
	delete this->window;
}

void Game::InitializeVariables()
{
}

void Game::Start()
{
	while (this->window->isOpen())
	{
		this->Update();

		this->window->clear();
		this->Render();
		this->window->display();
	}
}

void Game::Update()
{
	while (this->window->pollEvent(event))
	{
		HandlePollEvent(event);
	}
}
