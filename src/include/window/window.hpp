#ifndef WINDOW_H
#define WINDOW_H

#include "PCH.hpp"
#include "Platform/Platform.hpp"

class Window
{
private:
	Window* root;
	std::vector<Window*> childres;

public:
	Window(Window* root, sf::Vector2f pos, sf::Vector2f size, sf::Color bg_color);
	~Window();
	void OnUpdate();

private:
	void Update();

private:
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::Color bg_color;
	bool is_show;

public:
	Window* GetAncestor()
	{
		return root ? root->GetAncestor() : this;
	}
	Window* GetRoot()
	{
		return root;
	}

	auto GetPos() const
	{
		return pos;
	}
	auto GetSize() const
	{
		return size;
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
};

#endif // WINDOW_H
