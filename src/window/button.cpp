#include "include/window/button.hpp"

Button::Button()
{
}

Button::Button(Window* root)
{
	this->SetRoot(root);
}

Button::~Button()
{
}

void Button::SetSize(float x, float y)
{
	Window::SetSize(x, y);
	sf::RectangleShape::setSize(sf::Vector2f(x, y));
}

void Button::SetPosition(float x, float y)
{
	Window::SetPosition(x, y);
	sf::RectangleShape::setPosition(sf::Vector2f(x, y));
}

void Button::Show()
{
	Window::Show();
	// sf::RectangleShape::setPosition(sf::Vector2f(x, y));
}

void Button::OnMouseMove(int x, int y)
{
	std::cout << GetName() << ": " << __func__ << std::endl;
}
