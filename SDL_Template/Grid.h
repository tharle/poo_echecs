#pragma once
#include "Sprite.h"

class Grid
{
private:
	SDL_Point m_Position;
	int m_CellDimension;
	int m_TypeSkin;
	Sprite* m_BoardSkin;

public:
	Grid(const SDL_Point position, const int cellDimension);
	~Grid();

	int GetWidth();
	int GetHeight();

	void Init(SDL_Renderer* renderer);
	void Draw(SDL_Renderer* renderer);
	void MouseClick(SDL_Point mousePosition);


	SDL_Point GetGridPointByMousePosition(SDL_Point mousePosition);

};

