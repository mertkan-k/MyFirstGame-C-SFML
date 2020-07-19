#ifndef BUTTON_H
#define BUTTON_H

#include "window.hpp"

class Button : public sf::RectangleShape, public Window
{
public:
	Button();
	Button(Window* root);
	~Button();

public:
	void SetSize(float x, float y);
	void SetPosition(float x, float y);
	void Show();
	void OnMouseMove(int x, int y);
};

#endif // BUTTON_H
