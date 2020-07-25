#ifndef BUTTON_H
#define BUTTON_H

#include "Gui.hpp"

class Button : public Gui
{
public:
	enum State
	{
		NORMAL,
		ON_OVER,
		ON_CLICKED,
	};

public:
	Button();
	~Button();

public:
	void Show();
	virtual void Draw();
	virtual void OnMouseEntered();
	virtual void OnMouseLeft();

private:
	sf::Color states[3];

public:
	void SetFillColor(State state, sf::Color color);

private:
	sf::Text* text;

public:
	void SetText(std::string text);
	sf::Text* GetTextObject()
	{
		return text;
	};
};

#endif // BUTTON_H
