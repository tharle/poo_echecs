#include "MovingTarget.h"


MovingTarget::MovingTarget(const int x, const int y, const int directionX, const int directionY, const int speed)
	: Object(x, y, 100, 100), m_Speed(speed), m_DirectionX(directionX), m_DirectionY(directionY)
{

}

void MovingTarget::Init(SDL_Renderer* renderer)
{
	m_Sprite->LoadTexture(renderer, "assets/target.png");
}

void MovingTarget::Update()
{
	m_Sprite->Translate(m_Speed * m_DirectionX, m_Speed * m_DirectionY);

	if (m_Sprite->GetX() < 0 || m_Sprite->GetX() > 800 - 100)
	{
		m_DirectionX *= -1;
	}

	if (m_Sprite->GetY() < 0 || m_Sprite->GetY() > 600 - 100)
	{
		m_DirectionY *= -1;
	}
}


void MovingTarget::IsColliding(const int x, const int y)
{
	SDL_Point point;

	point.x = x;
	point.y = y;

	if (SDL_PointInRect(&point, m_Sprite->GetRec()))
	{
		isDestroyed = true;
	}
}
