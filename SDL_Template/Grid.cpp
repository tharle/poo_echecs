#include "Grid.h"
#include <iostream>

Grid::Grid(const SDL_Point position, const int cellDimension) :
	m_Position(position),
	m_CellDimension(cellDimension),
	m_TypeSkin(3)
{

	m_BoardSkin = new Sprite(position.x, position.y, GetWidth(), GetHeight());
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
	m_BoardSkin->LoadTexture(renderer, "assets/Board/"+std::to_string(m_TypeSkin) +".png");
}

void Grid::Draw(SDL_Renderer* renderer)
{
	m_BoardSkin->Draw(renderer);
}

void Grid::MouseClick(SDL_Point mousePosition)
{
	SDL_Point gridPosition = GetGridPointByMousePosition(mousePosition);
	std::cout << "Grid [" << gridPosition.x << "," << gridPosition.y << "]" << std::endl;
}

SDL_Point Grid::GetGridPointByMousePosition(SDL_Point mousePosition)
{
	return { (mousePosition.x - m_Position.x) / m_CellDimension,  (mousePosition.y - m_Position.y) / m_CellDimension };
}
