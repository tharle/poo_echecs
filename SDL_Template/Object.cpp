#include "Object.h"

Object::Object(const int x, const int y, const int w, const int h)
	: m_Sprite(new Sprite(x, y, w, h))
{
}

Object::~Object()
{
}

void Object::Draw(SDL_Renderer* renderer)
{
	m_Sprite->Draw(renderer);
}
