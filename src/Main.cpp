#include <SDL.h>
#include "Game.hpp"

int main(int argc, char *argv[])
{
	Game game(SDL_Rect{0, 0, 640, 480}, "Hello World");

	game.run();

	return 0;
}