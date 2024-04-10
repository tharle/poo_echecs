#pragma once
#include "Sprite.h"

class Object
{
public:

	Object(const int x, const int y, const int w, const int h);
	~Object();

	virtual void Init(SDL_Renderer* renderer) = 0; // virtual pure
	virtual void Update() = 0;
	virtual void Draw(SDL_Renderer* renderer);

	virtual void IsColliding(const int x, const int y) {}

	const bool IsDestroyed() { return isDestroyed; }

protected:
	Sprite* m_Sprite;

	bool isDestroyed;

private:
};

