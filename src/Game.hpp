#ifndef GAME_H
#define GAME_H
#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
	
class Game  
{

public:
	Game(SDL_Rect position, const std::string title);
	~Game();

	void run();
	void processEvents();

	void clearScreen();

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	bool isRunning;

};

#endif