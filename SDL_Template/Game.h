#pragma once
#include "SDL.h"
#include "Grid.h"
#include <vector>

class Game
{

public:
	Game();
	~Game();

	void Init(SDL_Renderer* graphics);

	void Update();
	void Draw(SDL_Renderer* graphics);

	void HandleMouseEvents(SDL_Event events);

	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;
	static const int CELL_SIZE;
	static const int BORDER_SIZE;
private:

	//Sprite* m_Background;
	Grid m_Grid;

	//std::vector<Object*> m_Objects;

};

