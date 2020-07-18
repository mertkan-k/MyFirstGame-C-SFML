#include "Platform/Platform.hpp"
#include "include/game.hpp"

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello Debug!" << std::endl;
#endif

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(200.0f * screenScalingFactor, 200.0f * screenScalingFactor), "SFML works!");
	platform.setIcon(window.getSystemHandle());

	sf::Event event;

	Game::game game(&window);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			game.HandlePollEvent(event);
		}

		window.clear();
		game.RefreshDisplay();
		window.display();
	}

	return 0;
}
