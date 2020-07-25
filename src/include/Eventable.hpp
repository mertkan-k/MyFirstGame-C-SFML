#ifndef EVENTABLE_H
#define EVENTABLE_H

class Eventable
{
	/* Constuctors and destructors */
public:
	Eventable();
	virtual ~Eventable() = default;

	/* Event functions */
private:
	bool is_mouse_in;
	void (*mouse_button_pressed_func)(sf::Event::MouseButtonEvent& event);
	void (*mouse_button_released_func)(sf::Event::MouseButtonEvent& event);

public:
	void HandlePollEvent(sf::Event& event);
	bool IsMouseIn();
	void SetMouseIn(bool is);

public:
	virtual void OnClose() {};
	virtual void OnMouseEntered() {};
	virtual void OnMouseLeft() {};
	virtual void OnMouseMoved() {};
	virtual void SetMouseButtonPressedEvent(void (*func)(sf::Event::MouseButtonEvent& event));
	virtual bool OnMouseButtonPressed(sf::Event::MouseButtonEvent& event);
	virtual void SetMouseButtonReleasedEvent(void (*func)(sf::Event::MouseButtonEvent& event));
	virtual bool OnMouseButtonReleased(sf::Event::MouseButtonEvent& event);
};

#endif // EVENTABLE_H