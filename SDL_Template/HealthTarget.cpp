#include "HealthTarget.h"
#include "Game.h"

HealthTarget::HealthTarget(const int x, const int y)
	: Object(x, y, 100, 100)
	, m_Hp(3)
{

}

void HealthTarget::Init(SDL_Renderer* renderer)
{
	m_Sprite->LoadTexture(renderer, "assets/target.png");
}

void HealthTarget::Update()
{

}

void HealthTarget::IsColliding(const int x, const int y)
{
	SDL_Point point;

	point.x = x;
	point.y = y;

	if (SDL_PointInRect(&point, m_Sprite->GetRec()))
	{
		m_Hp -= 1;

		if (m_Hp == 0)
			isDestroyed = true;		
		else 
			Reposition();
	}	
}

void HealthTarget::Reposition()
{
	m_Sprite->SetPosition(rand() % Game::SCREEN_WIDTH, rand() % Game::SCREEN_HEIGHT);
}