#include "include/window/window.hpp"

Window::Window(Window* root = nullptr,
	sf::Vector2f pos = sf::Vector2f(0, 0),
	sf::Vector2f size = sf::Vector2f(0, 0),
	sf::Color bg_color = sf::Color(0, 0, 0, 255))
{
	this->root = root;
	this->pos = pos;
	this->size = size;
	this->bg_color = bg_color;

	this->is_show = false;
}

Window::~Window()
{
	/* before delete all chidrens */
	std::for_each(childres.begin(), childres.end(), std::default_delete<Window>());
}

void Window::OnUpdate()
{
	/* before update all chidrens */
	std::for_each(childres.begin(), childres.end(), [](Window* w) { w->OnUpdate(); });

	/* After update me */
	Update();
}

void Window::Update()
{
	/* after  */
}
