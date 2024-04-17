#pragma once
#include "SDL_image.h"
#include <string>

class Sprite
{
public:
	
	Sprite(float a_X, float a_Y, float a_W, float a_H);
	~Sprite();

	bool LoadTexture(SDL_Renderer* graphics, const std::string& filename);

	void Draw(SDL_Renderer* graphics);
	void SetPosition(const SDL_Point newPosition);

	const int GetX() { return m_Rect.x; }
	const int GetY() { return m_Rect.y; }

	void Translate(int x, int y);
	SDL_Rect* GetRec();

private:

	SDL_Rect m_Rect;
	SDL_Texture* m_Texture;
};

