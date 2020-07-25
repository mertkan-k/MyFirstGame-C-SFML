#ifndef AREA_H
#define AREA_H

#include "include/Eventable.hpp"
#include "include/font_manager.hpp"

class Gui : public sf::RectangleShape, public Eventable
{
	/* Constuctors and destructors */
public:
	Gui(std::string name = "Unnamed Gui");
	Gui(sf::RenderWindow* mng);
	void InitEvents();
	~Gui();

private:
	std::string name;

public:
	void SetName(std::string name);
	std::string& GetName();

	/*private:
	Gui* parent;

public:
	Gui* GetParent();
	Gui* GetAncestor();*/

private:
	std::set<Gui*> children;

public:
	void RemoveChild(Gui* child);
	void AddChild(Gui* child);

private:
	bool is_show;
	bool is_focus_in;
	void (*mouse_button_func)(sf::Event::MouseButtonEvent& event);

public:
	bool IsShow() const;
	void Show();
	void Hide();
	bool IsFocusIn();
	void SetFocusIn(bool is);
	void SetMouseButtonEvent(void (*func)(sf::Event::MouseButtonEvent& event));
	bool OnMouseButton(sf::Event::MouseButtonEvent& event);

	/*private:
	sf::Vector2u size;

public:
	sf::Vector2u GetSize() const;
	void SetSize(sf::Vector2u size);*/

public:
	virtual void OnMouseEntered();
	virtual void OnMouseLeft();
	virtual void OnMouseMoved();
	virtual bool OnMouseButtonPressed(sf::Event::MouseButtonEvent& event);
	virtual bool OnMouseButtonReleased(sf::Event::MouseButtonEvent& event);

protected:
	inline static sf::RenderWindow* window_manager;

public:
	void SetWindowManager(sf::RenderWindow* mng);
	virtual void Draw();

protected:
	inline static Font_manager font_manager;
};

#endif // AREA_H