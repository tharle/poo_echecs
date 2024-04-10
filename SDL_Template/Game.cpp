#include "Game.h"
#include <iostream>
#include "HealthTarget.h"
#include "MovingTarget.h"

const int Game::SCREEN_WIDTH = 800;
const int Game::SCREEN_HEIGHT = 600;

Game::Game()
	: m_Background(new Sprite(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT))
	, m_Objects({})
{
	m_Objects.push_back(new HealthTarget(400-50, 300-50));
	m_Objects.push_back(new MovingTarget(380-50, 300-50, 1, 1, 6));
	m_Objects.push_back(new MovingTarget(370-50, 300-50, 1, 1, 5));
	m_Objects.push_back(new MovingTarget(360-50, 300-50, 1, 1, 23));
	m_Objects.push_back(new MovingTarget(350-50, 300-50, 1, 1, 10));
	m_Objects.push_back(new MovingTarget(340-50, 300-50, 1, 1, 87));
	m_Objects.push_back(new MovingTarget(330-50, 300-50, 1, 1, 1));
	m_Objects.push_back(new MovingTarget(320-50, 300-50, 1, 1, 13));
	m_Objects.push_back(new MovingTarget(310-50, 300-50, 1, 1, 17));
	m_Objects.push_back(new MovingTarget(300-50, 300-50, 1, 1, 9));
	m_Objects.push_back(new MovingTarget(290-50, 300-50, 1, 1, 7));
	m_Objects.push_back(new MovingTarget(280-50, 300-50, 1, 1, 7));
	m_Objects.push_back(new MovingTarget(200, 50, 1, 1, 7));
	m_Objects.push_back(new MovingTarget(0, 500, 1, 0, 3));
	m_Objects.push_back(new MovingTarget(500, 0, 0, 1, 8));
}

Game::~Game()
{
}

void Game::Init(SDL_Renderer* graphics)
{
	m_Background->LoadTexture(graphics, "assets/background.jpg");
	for (int i = 0; i < m_Objects.size(); i++)
	{
		m_Objects[i]->Init(graphics);
	}
}

void Game::HandleMouseEvents(SDL_Event events)
{
	if (events.type == SDL_MOUSEMOTION)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);
	}

	if (events.type == SDL_MOUSEBUTTONDOWN)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);
	

		for (int i = 0; i < m_Objects.size(); i++)
		{
			if (m_Objects[i] != nullptr)
			{
				m_Objects[i]->IsColliding(x, y);
			}
		}
	}
}

void Game::Update()
{
	for (int i = 0; i < m_Objects.size(); i++)
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
	}
}

void Game::Draw(SDL_Renderer* graphics)
{
	m_Background->Draw(graphics);
	for (int i = 0; i < m_Objects.size(); i++)
	{
		if (m_Objects[i] != nullptr)
		{
			m_Objects[i]->Draw(graphics);
		}
	}
}



