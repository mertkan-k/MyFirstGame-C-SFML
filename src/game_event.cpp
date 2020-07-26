#include "include/game.hpp"

void Game::OnClose()
{
	std::cout << "window closed" << std::endl;
	this->window->close();
}

void Game::OnResize(sf::Event::SizeEvent& size)
{
	std::cout << "new width: " << size.width << std::endl;
	std::cout << "new height: " << size.height << std::endl;
}

void Game::OnLostFocus()
{
	std::cout << "focus losted" << std::endl;
}

void Game::OnGainedFocus()
{
	std::cout << "focus gained" << std::endl;
}

void Game::TextEnteredEvent(sf::Event::TextEvent& text)
{
	if (text.unicode < 128)
		std::cout << "ASCII character typed: " << static_cast<char>(text.unicode) << std::endl;
}

void Game::OnKeyPressed(sf::Event::KeyEvent& key)
{
	switch (key.code)
	{
		case (sf::Keyboard::Escape):
			OnClose();
			break;

		default:
			break;
	}
}

void Game::OnKeyReleased(sf::Event::KeyEvent& key)
{
	std::cout << "key released" << key.code << std::endl;
}

void Game::OnMouseWhell(sf::Event::MouseWheelScrollEvent& event)
{
	if (event.wheel == sf::Mouse::VerticalWheel)
		std::cout << "wheel type: vertical" << std::endl;
	else if (event.wheel == sf::Mouse::HorizontalWheel)
		std::cout << "wheel type: horizontal" << std::endl;
	else
		std::cout << "wheel type: unknown" << std::endl;
	std::cout << "wheel movement: " << event.delta << std::endl;
	// std::cout << "mouse x: " << event.x << std::endl;
	// std::cout << "mouse y: " << event.y << std::endl;
}

bool Game::OnMouseButtonPressed(sf::Event::MouseButtonEvent& event)
{
	return this->gui->OnMouseButtonPressed(event);
	// std::ignore = event;
	// this->gui->OnMouseButtonPressed(event.button);
	// std::cout << "mouse button pressed" << event.button << std::endl;
	// std::cout << "mouse x: " << event.x << std::endl;
	// std::cout << "mouse y: " << event.y << std::endl;
}

bool Game::OnMouseButtonReleased(sf::Event::MouseButtonEvent& event)
{
	return this->gui->OnMouseButtonReleased(event);
	// std::ignore = event;
	// this->gui->OnMouseButtonReleased(event.button);
	// std::cout << "mouse button released" << event.button << std::endl;
	// std::cout << "mouse x: " << event.x << std::endl;
	// std::cout << "mouse y: " << event.y << std::endl;
}

void Game::OnMouseMoved()
{
	// std::ignore = event;
	this->gui->OnMouseMoved();
}

void Game::OnMouseEntered()
{
	std::cout << "the mouse cursor has entered the window" << std::endl;
	// this->gui->OnMouseEntered();
}

void Game::OnMouseLeft()
{
	std::cout << "the mouse cursor has left the window" << std::endl;
	this->gui->OnMouseLeft();
}
