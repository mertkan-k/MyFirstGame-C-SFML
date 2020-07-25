#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include "PCH.hpp"

class Font_manager
{
public:
	enum Fonts
	{
		ARIAL,
		// ARIAL,
		DEFAULT = ARIAL,
	};

	// private:
	std::unordered_map<Fonts, sf::Font*> fonts;

public:
	Font_manager(/* args */);
	~Font_manager();

public:
	sf::Font& GetFont(Fonts index = DEFAULT);
};

#endif // FONT_MANAGER_H