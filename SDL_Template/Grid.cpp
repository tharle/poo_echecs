#include "Grid.h"
#include <iostream>
#include "Pawn.h"
#include "TokenFactory.h"

Grid::Grid(const SDL_Point offset, const int cellDimension) :
	m_Offset(offset),
	m_CellDimension(cellDimension),
	m_SkinBoardId(2),
	m_SkinTokenId(2),
	m_Board({})
{
	m_BoardSkin = new Sprite(offset.x, offset.y, GetWidth(), GetHeight());
	for (int i = 0; i < 8; i++)
	{
		m_Board.push_back(vector<Tile*>());
		for (int j = 0; j < 8; j++)
		{
			// SDL_Point position, int size, SDL_Point offset
			m_Board[i].push_back(new Tile({i, j}, cellDimension, offset));
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

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_Board[i][j] != nullptr) 
			{
				delete m_Board[i][j];

				m_Board[i][j] = nullptr;
			}
		}
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
		m_Board[1][i]->SetToken(TokenFactory::CreatePawn(renderer, { 6, i }, m_Offset, false, m_SkinTokenId)) ;
		m_Board[6][i]->SetToken(TokenFactory::CreatePawn(renderer, { 6, i }, m_Offset, true, m_SkinTokenId));
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << "[" << m_Board[i][j]->ToString() << "]";
		}
		std::cout << std::endl;
	}
}



void Grid::Draw(SDL_Renderer* renderer)
{
	m_BoardSkin->Draw(renderer);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_Board[i][j] != nullptr)
			{
				m_Board[i][j]->Draw(renderer);
			}
		}
	}
}

void Grid::MouseClick(SDL_Point mousePosition)
{
	if (!m_BoardSkin->IsColliding(mousePosition)) return;

	SDL_Point gridPosition = GetGridPointByMousePosition(mousePosition);
	std::cout << "Grid [" << gridPosition.x << "," << gridPosition.y << "]" << std::endl;
}

void Grid::MouseDrag(SDL_Point mousePosition) 
{
	if (!m_BoardSkin->IsColliding(mousePosition)) return;

	SDL_Point gridPosition = GetGridPointByMousePosition(mousePosition);

	if (m_MouseOverTile == m_Board[gridPosition.x][gridPosition.y]) return;

	std::cout << "DRAG [" << gridPosition.x << "," << gridPosition.y << "]" << std::endl;
	if (m_MouseOverTile != nullptr) m_MouseOverTile->ChangeState(STATE_NONE);
	m_MouseOverTile = m_Board[gridPosition.x][gridPosition.y];
	m_MouseOverTile->ChangeState(STATE_OVER);
}

SDL_Point Grid::GetGridPointByMousePosition(SDL_Point mousePosition)
{
	return { (mousePosition.x - m_Offset.x) / m_CellDimension,  (mousePosition.y - m_Offset.y) / m_CellDimension };
}


