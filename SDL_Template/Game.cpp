#include "Game.h"
#include <iostream>
//#include "HealthTarget.h"
//#include "MovingTarget.h"

const int Game::SCREEN_WIDTH = 600;
const int Game::SCREEN_HEIGHT = 600;
const int Game::CELL_SIZE = 64;
const int Game::BORDER_SIZE = 44;

Game::Game()
	: m_Grid(Grid({ BORDER_SIZE, BORDER_SIZE }, CELL_SIZE))
{
}

Game::~Game()
{
}

void Game::Init(SDL_Renderer* graphics)
{
	m_Grid.Init(graphics);
}

void Game::HandleMouseEvents(SDL_Event events)
{
	if (events.type == SDL_MOUSEBUTTONUP) 
	{
		SDL_Point mousePosition;
		SDL_GetMouseState(&mousePosition.y, &mousePosition.x);
		m_Grid.MouseButtonUp(mousePosition);
		cout << "MOUSE UP" << endl;
	}

	if (events.type == SDL_MOUSEBUTTONDOWN)
	{
		SDL_Point mousePosition;
		SDL_GetMouseState(&mousePosition.y, &mousePosition.x);
		m_Grid.MouseButtonDown(mousePosition);

		cout << "MOUSE DOWN" << endl;
	}

	if (events.type == SDL_MOUSEMOTION)
	{
		SDL_Point mousePosition;
		SDL_GetMouseState(&mousePosition.y, &mousePosition.x);
		m_Grid.MouseDrag(mousePosition);
	}
}

void Game::Update()
{
	/*for (int i = 0; i < m_Objects.size(); i++)
	{
		if (m_Objects[i] != nullptr)
		{
			if (m_Objects[i]->IsDestroyed())
			{
				delete m_Objects[i];
				m_Objects[i] = nullptr;

				continue;
			}

			m_Objects[i]->Update();
		}
	}*/
}

void Game::Draw(SDL_Renderer* graphics)
{
	m_Grid.Draw(graphics);
	/*m_Background->Draw(graphics);
	for (int i = 0; i < m_Objects.size(); i++)
	{
		if (m_Objects[i] != nullptr)
		{
			m_Objects[i]->Draw(graphics);
		}
	}*/
}



