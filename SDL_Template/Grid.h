#pragma once
#include "Sprite.h"
#include "Token.h"
#include "Tile.h"
#include <vector>

using namespace std;

class Grid
{
private:
	SDL_Point m_Offset;
	Tile* m_MouseOverTile;
	int m_CellDimension;
	Sprite* m_BoardSkin;

	int m_SkinBoardId;
	int m_SkinTokenId;
	
	vector<vector<Tile*>> m_Board;

public:
	Grid(const SDL_Point offset, const int cellDimension);
	~Grid();

	int GetWidth();
	int GetHeight();

	void Init(SDL_Renderer* renderer);
	void Draw(SDL_Renderer* renderer);
	void MouseClick(SDL_Point mousePosition);
	void MouseDrag(SDL_Point mousePosition);


	SDL_Point GetGridPointByMousePosition(SDL_Point mousePosition);

};

