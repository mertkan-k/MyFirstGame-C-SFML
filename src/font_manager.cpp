#include "include/font_manager.hpp"

Font_manager::Font_manager(/* args */)
{
	sf::Font* font = new sf::Font();
	if (!font->loadFromFile("content/arial.ttf"))
	{
		// error... todo:
	}
	fonts[DEFAULT] = font;
}

Font_manager::~Font_manager()
{
	std::for_each(fonts.begin(), fonts.end(), [&](std::pair<Fonts, sf::Font*> font) {
		delete font.second;
	});
}

sf::Font& Font_manager::GetFont(Fonts index)
{
	return *(fonts[index]);
}
