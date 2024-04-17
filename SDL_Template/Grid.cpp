#include "Grid.h"
#include <iostream>
#include "Pawn.h"

#define SIZE_TOKENS 64



Grid::Grid(const SDL_Point offset, const int cellDimension) :
	m_Offset(offset),
	m_CellDimension(cellDimension),
	m_SkinBoardId(1),
	m_SkinTokenId(1),
	m_Board({})
{
	m_BoardSkin = new Sprite(offset.x, offset.y, GetWidth(), GetHeight());

	for (int i = 0; i < 8; i++)
	{
		m_Board.push_back(vector<Token*>());
		for (int j = 0; j < 8; j++)
		{
			m_Board[i].push_back(nullptr);
		}
	}

}

Grid::~Grid()
{
	if (m_BoardSkin != nullptr) 
	{
		delete m_BoardSkin;
		m_BoardSkin = nullptr;
	}
}


int Grid::GetWidth() 
{
	return m_CellDimension * 8;
}

int Grid::GetHeight()
{
	return m_CellDimension * 8;
}

void Grid::Init(SDL_Renderer* renderer)
{
	m_BoardSkin->LoadTexture(renderer, "assets/Board/"+std::to_string(m_SkinBoardId) +".png");
	
	for (int i = 0; i < 8; i++) 
	{
		m_Board[i][6] = new Pawn(SIZE_TOKENS, true, m_Offset);
		m_Board[i][6]->Init(m_SkinTokenId, renderer);
		m_Board[i][6]->SetPosition({ i, 6 });
	}

}

void Grid::Draw(SDL_Renderer* renderer)
{
	m_BoardSkin->Draw(renderer);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_Board[i][j] != nullptr) m_Board[i][j]->Draw(renderer);
		}
	}
}

void Grid::MouseClick(SDL_Point mousePosition)
{
	SDL_Point gridPosition = GetGridPointByMousePosition(mousePosition);
	std::cout << "Grid [" << gridPosition.x << "," << gridPosition.y << "]" << std::endl;
}

SDL_Point Grid::GetGridPointByMousePosition(SDL_Point mousePosition)
{
	return { (mousePosition.x - m_Offset.x) / m_CellDimension,  (mousePosition.y - m_Offset.y) / m_CellDimension };
}
