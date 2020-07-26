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
	virtual bool OnMouseButtonPressed(sf::Event::MouseButtonEvent& event);
	virtual void setPosition(float x, float y);

protected:
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

class ToggleButton : public Button
{
public:
	ToggleButton();
	~ToggleButton();

private:
	bool is_pressed;

public:
	bool IsPressed()
	{
		return is_pressed;
	}
	void SetPressed(bool is)
	{
		is_pressed = is;
	}
	virtual void OnMouseEntered();
	virtual void OnMouseLeft();
	virtual bool OnMouseButtonPressed(sf::Event::MouseButtonEvent& event);
	// virtual void SetMouseButtonEvent(std::function<void()> func) {std::ign};
};

#endif // BUTTON_H
