#ifndef WINDOW_H
#define WINDOW_H

#include "PCH.hpp"
#include "Platform/Platform.hpp"

class Window
{
private:
	std::string name;
	Window* root;
	std::set<Window*> children;

public:
	Window();
	~Window();
	void OnUpdate();

private:
	void Update();

private:
	sf::Vector2f pos;
	sf::Vector2u size;
	sf::Color bg_color;
	bool is_show;

public:
	void SetName(std::string name)
	{
		this->name = name;
	}
	std::string& GetName()
	{
		return this->name;
	}
	void SetRoot(Window* wind)
	{
		this->root = wind;
		wind->AddChild(this);
	}
	Window* GetAncestor()
	{
		return root ? root->GetAncestor() : this;
	}
	Window* GetRoot()
	{
		return root;
	}

	void SetPosition(sf::Vector2f pos)
	{
		this->pos = pos;
	}
	void SetPosition(float x, float y)
	{
		this->pos.x = x;
		this->pos.y = y;
	}
	auto GetPos() const
	{
		return pos;
	}

	void SetSize(sf::Vector2u size)
	{
		this->size = size;
	}
	void SetSize(float width, float height)
	{
		this->size.x = width;
		this->size.y = height;
	}
	auto GetSize() const
	{
		return size;
	}

	void SetBGCoolor(sf::Color bg_color)
	{
		this->bg_color = bg_color;
	}
	void SetBGCoolor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
	{
		this->bg_color.r = r;
		this->bg_color.g = g;
		this->bg_color.b = b;
		this->bg_color.a = a;
	}
	auto GetBGCoolor() const
	{
		return bg_color;
	}

	auto IsShow() const
	{
		return is_show;
	}
	void Show()
	{
		is_show = true;
	}
	void Hide()
	{
		is_show = false;
	}

	void RemoveChild(Window* window);
	void AddChild(Window* window);
	// void Close();

private: /* Events */
	bool is_mouse_in;
	void (*mouse_enter_func)(void);

public:
	bool isMouseIn()
	{
		return is_mouse_in;
	}
	void SetMouseIn(bool set)
	{
		is_mouse_in = set;
	}
	virtual void OnMouseMove(int x, int y);
	virtual void SetMouseMoveEvent(void (*func)(void));
	virtual void OnMouseEnter();
	virtual void OnMouseLeave();
};

#endif // WINDOW_H
