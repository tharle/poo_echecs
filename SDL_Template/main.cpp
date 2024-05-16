#include <Windows.h>
#include <SDL.h>
#include <iostream>
#include "Game.h"
#include <cstdlib>
#include <SDL_ttf.h>

using namespace std;

int main(int argc, char* argv[])
{
	srand(time(0));

	if (SDL_Init(SDL_INIT_EVERYTHING))
	{
		SDL_Log("Error : %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window* win = SDL_CreateWindow(
		"Master chees",
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED,
		Game::SCREEN_WIDTH,
		Game::SCREEN_HEIGHT,
		SDL_WINDOW_UTILITY
	);

	SDL_Renderer* graphics = SDL_CreateRenderer(win, 0, SDL_RENDERER_PRESENTVSYNC);

	if (graphics == nullptr)
	{
		SDL_Log("Error : %s\n", SDL_GetError());
		return 1;
	}

	bool running = true;
	SDL_Event events;

	Game* game = new Game();
	game->Init(graphics);

	while (running)
	{
		while (SDL_PollEvent(&events))
		{
			switch (events.type)
			{
				case SDL_QUIT:
					running = false;
					break;
			}

			game->HandleMouseEvents(events);
		}

		SDL_SetRenderDrawColor(graphics, 0, 0, 0, 255);
		SDL_RenderClear(graphics);

		game->Update();
		game->Draw(graphics);

		// Push back buffer to the front buffer
		SDL_RenderPresent(graphics);
	}

	SDL_DestroyRenderer(graphics);
	SDL_DestroyWindow(win);
	SDL_Quit();

	SDL_Log("PROGRAM END\n");
	return 0;
}
