#pragma once
#include "Sprite.h"
#include "Token.h"
#include "Tile.h"
#include <vector>
#include <list>

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
	Token* m_TokenSelected;
	SDL_Point m_TokenSelectedPositionOld;	
	Sprite* m_TokenSelectedSprite;

	list<Token*> m_WhiteCaptureds;
	list<Token*> m_BlackCaptureds;


	void SelectToken(SDL_Point gridPosition);
	void UnselectToken(SDL_Point gridPosition);
	void CaptureToken(Token* token);

public:
	Grid(const SDL_Point offset, const int cellDimension);
	~Grid();

	int GetWidth();
	int GetHeight();

	void Init(SDL_Renderer* renderer);
	void Draw(SDL_Renderer* renderer);
	void MouseDrag(SDL_Point mousePosition);
	void MouseButtonUp(SDL_Point mousePosition);
	void MouseButtonDown(SDL_Point mousePosition);


	SDL_Point GetGridPointByMousePosition(SDL_Point mousePosition);
	void RestoreSelectionGrid();

};

