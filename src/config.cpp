#include "include/config.hpp"
// #include <file>
#include <string.h>

Config::Config()
{
	InitDefault();

	if ((configFile = fopen(Config::CONFIG_FILENAME, "r")) != nullptr)
	{
		InitFile();
	}

	if (!video_mode.isValid())
	{
		/* todo:: throw or return false */
	}
}

Config::~Config()
{
}

void Config::InitDefault()
{
	video_mode.width = (unsigned int)Config::Default::SCREEN_WIDTH;
	video_mode.height = (unsigned int)Config::Default::SCREEN_HEIGHT;
	video_mode.bitsPerPixel = (unsigned int)Config::Default::PIXEL_DEPTH;
}

void Config::InitFile()
{
	Config::Setting type = Config::DEFAULT;
	char name[256];
	int value = 0;

	while (fscanf(configFile, "%s %d", name, &value) == 2)
	{
		type = GetSettingType(name);
		switch (type)
		{
			case (Setting::SCREEN_WIDTH):
				video_mode.width = value;
				break;

			case (Setting::SCREEN_HEIGHT):
				video_mode.height = value;
				break;

			case (Setting::PIXEL_DEPTH):
				video_mode.bitsPerPixel = value;
				break;

			case (Setting::DESKTOP_RESULATION):
				if (value)
					video_mode = sf::VideoMode::getDesktopMode();
				break;

			default:
				break;
		}
	}
}

Config::Setting Config::GetSettingType(const char* name)
{
	if (strcmp(name, "SCREEN_WIDTH") == 0)
		return Config::SCREEN_WIDTH;

	if (strcmp(name, "SCREEN_HEIGHT") == 0)
		return Config::SCREEN_HEIGHT;

	if (strcmp(name, "PIXEL_DEPTH") == 0)
		return Config::PIXEL_DEPTH;

	if (strcmp(name, "DESKTOP_RESULATION") == 0)
		return Config::DESKTOP_RESULATION;

	return Config::DEFAULT;
}
