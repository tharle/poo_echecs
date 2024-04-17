#pragma once
#include "Sprite.h"
#include "Token.h"
#include <vector>

using namespace std;

class Grid
{
private:
	SDL_Point m_Offset;
	int m_CellDimension;
	int m_TypeSkin;
	Sprite* m_BoardSkin;
	
	vector<vector<Token*>> m_Board;

public:
	Grid(const SDL_Point offset, const int cellDimension);
	~Grid();

	int GetWidth();
	int GetHeight();

	void Init(SDL_Renderer* renderer);
	void Draw(SDL_Renderer* renderer);
	void MouseClick(SDL_Point mousePosition);


	SDL_Point GetGridPointByMousePosition(SDL_Point mousePosition);

};

