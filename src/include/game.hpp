#ifndef GAME_H
#define GAME_H

#include "Platform/Platform.hpp"
#include "include/config.hpp"

namespace Game
{
class game
{
private:
	util::Platform platform;  /* main platform */
	sf::RenderWindow* window; /* main window */
	Config config;			  /*  */
	sf::Event event;		  /* handling events */

public: /* constructor and destructor */
	game();
	~game();

public:
	void Start(); /* start game with a while(true) */

private:
	/* Calling by constructor to init window */
	void InitializeWindow();

	/* Calling by constructor to init var */
	void InitializeVariables();

public: /* functions from window management */
	/* Calling from main.isOpen */
	void Update();

	/* Calling from this->Update */
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
	void Render();
}; // class game

} // namespace Game

#endif // GAME_H
