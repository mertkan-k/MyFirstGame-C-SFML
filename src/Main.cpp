#include "include/game.hpp"

int main()
{
#if defined(_DEBUG)
	std::cout << "Hello Debug!" << std::endl;
#endif

	Game::game my_game;
	my_game.Start();

	return 0;
}
