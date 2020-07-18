#ifndef GAME_H
#define GAME_H

#include "Platform/Platform.hpp"

namespace Game
{
class game
{
private:
	sf::RenderWindow* window; /* Upper window */

public: /* constructor and destructor */
	game(sf::RenderWindow* window);
	~game();

public: /* functions from window management */
	/* Calling from main.window.pollEvent */
	void HandlePollEvent(sf::Event& event);

	/* General gui events */
	void OnClose();
	void OnResize(sf::Event::SizeEvent& size);

	/* Focus events */
	void OnLostFocus();
	void OnGainedFocus();

	/* Text events */
	void TextEnteredEvent(sf::Event::TextEvent& text);

	/* Key events */
	void OnKeyPressed(sf::Event::KeyEvent& key);
	void OnKeyReleased(sf::Event::KeyEvent& key);

	/* Mouse events */
	void OnMouseWhell(sf::Event::MouseWheelScrollEvent& event);
	void OnMouseButtonPressed(sf::Event::MouseButtonEvent& event);
	void OnMouseButtonReleased(sf::Event::MouseButtonEvent& event);
	void OnMouseMoved(sf::Event::MouseMoveEvent& event);
	void OnMouseEntered();
	void OnMouseLeft();

public: /* functions from display */
	/* Calling from main.window.isOpen() */
	void RefreshDisplay();
}; // class game

} // namespace Game

#endif // GAME_H
