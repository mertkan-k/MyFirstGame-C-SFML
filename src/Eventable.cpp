#include "include/Eventable.hpp"

Eventable::Eventable()
{
	is_mouse_in = false;
	mouse_button_pressed_func = nullptr;
	mouse_button_released_func = nullptr;
}

// Eventable::~Eventable()
// {
// 	int x = 1;
// 	x += x;
// }

void Eventable::HandlePollEvent(sf::Event& event)
{
	switch (event.type)
	{
		using namespace sf;

		case (Event::Closed):
			OnClose();
			break;

		case (Event::Resized):
			// OnResize(event.size);
			break;

		case (Event::LostFocus):
			// OnLostFocus();
			break;

		case (Event::GainedFocus):
			// OnGainedFocus();
			break;

		case (Event::TextEntered):
			// TextEnteredEvent(event->text);
			break;

		case (Event::KeyPressed):
			// OnKeyPressed(event.key);
			break;

		case (Event::KeyReleased):
			// OnKeyReleased(event.key);
			break;

		case (Event::MouseWheelScrolled):
			// OnMouseWhell(event.mouseWheelScroll);
			break;

		case (Event::MouseButtonPressed):
			OnMouseButtonPressed(event.mouseButton);
			break;

		case (Event::MouseButtonReleased):
			OnMouseButtonReleased(event.mouseButton);
			break;

		case (Event::MouseMoved):
			OnMouseMoved();
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

bool Eventable::IsMouseIn()
{
	return is_mouse_in;
}

void Eventable::SetMouseIn(bool is)
{
	is_mouse_in = is;
}

void Eventable::SetMouseButtonPressedEvent(void (*func)(sf::Event::MouseButtonEvent& event))
{
	mouse_button_pressed_func = func;
}

bool Eventable::OnMouseButtonPressed(sf::Event::MouseButtonEvent& event)
{
	// SetFocusIn(true);

	if (*mouse_button_pressed_func)
	{
		(*mouse_button_pressed_func)(event);
		return true;
	}

	return false;
}

void Eventable::SetMouseButtonReleasedEvent(void (*func)(sf::Event::MouseButtonEvent& event))
{
	mouse_button_released_func = func;
}

bool Eventable::OnMouseButtonReleased(sf::Event::MouseButtonEvent& event)
{
	if (*mouse_button_released_func)
	{
		(*mouse_button_released_func)(event);
		return true;
	}

	return false;
}
