#pragma once
#include "SDL_image.h"
#include <string>

class Sprite
{
public:
	
	Sprite(float a_X, float a_Y, float a_W, float a_H);
	~Sprite();

	bool LoadTexture(SDL_Renderer* graphics, const std::string& filename);

	//SDL_Rect* GetRec();
	virtual void Draw(SDL_Renderer* graphics);
	virtual void Draw(SDL_Renderer* graphics, SDL_RendererFlip sdlFlipId);
	virtual void SetVisible(bool visible);
	virtual bool IsColliding(SDL_Point point);
	virtual void SetPosition(const SDL_Point newPosition);
	void Translate(SDL_Point distance);
	int GetH();
	int GetW();


protected:

	SDL_Rect m_Rect;
	SDL_Texture* m_Texture;
	bool m_Visible;
};

