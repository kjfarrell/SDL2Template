#include "Game.hpp"  
	
Game::Game(SDL_Rect position, const std::string title)
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        title.c_str(),
        position.x,
        position.y,
        position.w,
        position.h,
        0
    );
    if(!window) 
        throw std::runtime_error("Could not create window");

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer) 
        throw std::runtime_error("Could not create renderer");
	
}
	
Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::run()
{
    int fps=60;
    int desiredDelta = 1000/fps; 

    isRunning = true;
    while(isRunning)
    {
        Uint64 start = SDL_GetTicks();

        processEvents();
        clearScreen();
        
        
        // Draw screen
        SDL_RenderPresent(renderer);

        // Cap FPS
        Uint64 delta = SDL_GetTicks() - start;
        if(delta < desiredDelta)
        {
            SDL_Delay(desiredDelta - delta);
        }
    }
}

void Game::processEvents()
{
    SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                isRunning = false;
            else if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        isRunning = false;
                        break;
                }
            }
        }

}

void Game::clearScreen()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}