#ifndef GAME_H
#define GAME_H

#include "Platform/Platform.hpp"
#include "include/Eventable.hpp"
#include "include/Gui.hpp"
#include "include/config.hpp"
// #include "include/window/window.hpp"

class Game : public Eventable
{
private:
	util::Platform platform;  /* main platform */
	sf::RenderWindow* window; /* main window */
	Config config;			  /*  */
	sf::Event event;		  /* handling events */
	Gui* gui;				  /* main gui for manage */
							  // std::set<Window*> windows; /* gui map */

public: /* constructor and destructor */
	Game();
	~Game();

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

	/* General gui events */
	virtual void OnClose();
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
	virtual bool OnMouseButtonPressed(sf::Event::MouseButtonEvent& event);
	virtual bool OnMouseButtonReleased(sf::Event::MouseButtonEvent& event);
	virtual void OnMouseMoved();
	virtual void OnMouseEntered();
	virtual void OnMouseLeft();

public: /* functions from display */
	/* Calling from main.window.isOpen() */
	void Render();
}; // class game

#endif // GAME_H
