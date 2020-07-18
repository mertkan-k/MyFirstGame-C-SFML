#ifndef CONFIG_H
#define CONFIG_H

#include "Platform/Platform.hpp"

/**
 * First init defaults
 * After read and init the CONFIG_FILENAME
*/
class Config
{
public: /* default variables */
	const char* CONFIG_FILENAME = "bin/config.txt";
	enum class Default
	{
		SCREEN_WIDTH = 800,
		SCREEN_HEIGHT = 600,
		PIXEL_DEPTH = 32,
	};

public:
	enum Setting
	{
		DEFAULT,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		PIXEL_DEPTH,
		DESKTOP_RESULATION,
	};

private:
	FILE* configFile;

public:
	sf::VideoMode video_mode;
	void InitVideoMode();

private:
	void InitDefault();
	void InitFile();
	Setting GetSettingType(const char* name);

public:
	Config();
	~Config();
};

#endif // CONFIG_H
