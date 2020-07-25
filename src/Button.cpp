#include "include/Button.hpp"
#include "include/font_manager.hpp"

Button::Button()
{
	text = nullptr;
}

Button::~Button()
{
}

void Button::SetText(std::string sText)
{
	// std::ignore = text;
	if (text == nullptr)
	{
		text = new sf::Text(sText, font_manager.GetFont());
		// text->setPosition(getPosition());
		/*
			btn->setSize(sf::Vector2f(120, 50));
			btn->setPosition(sf::Vector2f(30, 50));
		*/
		// std::cout << text->getLocalBounds().height << std::endl;  // 22
		// std::cout << text->getLocalBounds().left << std::endl;	  // 0
		// std::cout << text->getLocalBounds().top << std::endl;	  // 8
		// std::cout << text->getLocalBounds().width << std::endl;	  // 104
		// std::cout << text->getGlobalBounds().height << std::endl; // 22
		// std::cout << text->getGlobalBounds().left << std::endl;	  // 30
		// std::cout << text->getGlobalBounds().top << std::endl;	  // 58
		// std::cout << text->getGlobalBounds().width << std::endl;  // 104

		float x = 0, y = 0;
		x = getPosition().x + ((getSize().x - text->getLocalBounds().width - text->getLocalBounds().left) / 2);
		y = getPosition().y + ((getSize().y - text->getLocalBounds().height - text->getLocalBounds().top) / 2);
		text->setPosition(x, y);
	}
	else
	{
		text->setString(sText);
	}

	// text.setCharacterSize(30);
	// text.setStyle(sf::Text::Bold);
	// text.setFillColor(sf::Color::Red);
}

void Button::Show()
{
	// sf::RectangleShape::setPosition(sf::Vector2f(x, y));
}

void Button::Draw()
{
	Gui::Draw();
	if (this->text)
	{
		window_manager->draw(*text);
	}
}

void Button::SetFillColor(State state, sf::Color color)
{
	if (state == NORMAL)
		setFillColor(color);

	states[state] = color;
}

void Button::OnMouseEntered()
{
	Gui::OnMouseEntered();
	// std::cout << typeid(*this).name() << " : " << __func__ << std::endl;
	setFillColor(states[ON_OVER]);
}

void Button::OnMouseLeft()
{
	Gui::OnMouseLeft();
	// std::cout << typeid(*this).name() << " : " << __func__ << std::endl;
	setFillColor(states[NORMAL]);
}