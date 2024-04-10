#pragma once
#include "Object.h"
class MovingTarget :
    public Object
{
public:
	MovingTarget(const int x, const int y, const int directionX, const int directionY, const int speed);

	virtual void Init(SDL_Renderer* renderer);
	virtual void Update();
	void IsColliding(const int x, const int y);

private:
	int m_Speed;
	int m_DirectionX;
	int m_DirectionY;
};

