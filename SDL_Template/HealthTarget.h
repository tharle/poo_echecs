#pragma once
#include "Object.h"
class HealthTarget : public Object
{
public:
	HealthTarget(const int x, const int y);

	virtual void Init(SDL_Renderer* renderer);
	virtual void Update();

	virtual void IsColliding(const int x, const int y);
	void Reposition();

private:

	int m_Hp;
};

