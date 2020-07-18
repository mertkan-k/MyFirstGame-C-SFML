#include "include/game.hpp"

using namespace Game;

void game::HandlePollEvent(sf::Event& event)
{
	switch (event.type)
	{
		using namespace sf;

		case (Event::Closed):
			OnClose();
			break;

		case (Event::Resized):
			OnResize(event.size);
			break;

		case (Event::LostFocus):
			OnLostFocus();
			break;

		case (Event::GainedFocus):
			OnGainedFocus();
			break;

		case (Event::TextEntered):
			// TextEnteredEvent(event->text);
			break;

		case (Event::KeyPressed):
			OnKeyPressed(event.key);
			break;

		case (Event::KeyReleased):
			OnKeyReleased(event.key);
			break;

		case (Event::MouseWheelScrolled):
			OnMouseWhell(event.mouseWheelScroll);
			break;

		case (Event::MouseButtonPressed):
			OnMouseButtonPressed(event.mouseButton);
			break;

		case (Event::MouseButtonReleased):
			OnMouseButtonReleased(event.mouseButton);
			break;

		case (Event::MouseMoved):
			OnMouseMoved(event.mouseMove);
			break;

		case (Event::MouseEntered):
			OnMouseEntered();
			break;

		case (Event::MouseLeft):
			OnMouseLeft();
			break;

		default:
			break;
	}
}

void game::OnClose()
{
	std::cout << "window closed" << std::endl;
	this->window->close();
}

void game::OnResize(sf::Event::SizeEvent& size)
{
	std::cout << "new width: " << size.width << std::endl;
	std::cout << "new height: " << size.height << std::endl;
}

void game::OnLostFocus()
{
	std::cout << "focus losted" << std::endl;
}

void game::OnGainedFocus()
{
	std::cout << "focus gained" << std::endl;
}

void game::TextEnteredEvent(sf::Event::TextEvent& text)
{
	if (text.unicode < 128)
		std::cout << "ASCII character typed: " << static_cast<char>(text.unicode) << std::endl;
}

void game::OnKeyPressed(sf::Event::KeyEvent& key)
{
	std::cout << "key pressed" << key.code << std::endl;
	// std::cout << "control:" << key.control << std::endl;
	// std::cout << "alt:" << key.alt << std::endl;
	// std::cout << "shift:" << key.shift << std::endl;
	// std::cout << "system:" << key.system << std::endl;
}

void game::OnKeyReleased(sf::Event::KeyEvent& key)
{
	std::cout << "key released" << key.code << std::endl;
}

void game::OnMouseWhell(sf::Event::MouseWheelScrollEvent& event)
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

void game::OnMouseButtonPressed(sf::Event::MouseButtonEvent& event)
{
	std::cout << "mouse button pressed" << event.button << std::endl;
	// std::cout << "mouse x: " << event.x << std::endl;
	// std::cout << "mouse y: " << event.y << std::endl;
}

void game::OnMouseButtonReleased(sf::Event::MouseButtonEvent& event)
{
	std::cout << "mouse button released" << event.button << std::endl;
	// std::cout << "mouse x: " << event.x << std::endl;
	// std::cout << "mouse y: " << event.y << std::endl;
}

void game::OnMouseMoved(sf::Event::MouseMoveEvent& event)
{
	std::cout << "new mouse x: " << event.x << " y: " << event.y << std::endl;
}

void game::OnMouseEntered()
{
	std::cout << "the mouse cursor has entered the window" << std::endl;
}

void game::OnMouseLeft()
{
	std::cout << "the mouse cursor has left the window" << std::endl;
}
