#include "Sprite.h"

Sprite::Sprite(float x, float y, float w, float h)
	: m_Texture(nullptr)
	, m_Rect(SDL_Rect())
{
	m_Rect.x = x;
	m_Rect.y = y;
	m_Rect.w = w;
	m_Rect.h = h;
}

Sprite::~Sprite()
{
	if (m_Texture != nullptr)
	{
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	}
}

bool Sprite::LoadTexture(SDL_Renderer* graphics, const std::string& filename)
{
	m_Texture = IMG_LoadTexture(graphics, filename.c_str());
	if (m_Texture == nullptr)
	{
		SDL_Log("Error loading texture %s", filename.c_str());
		return false;
	}

	return true;
}

void Sprite::Draw(SDL_Renderer* graphics)
{
	SDL_RenderCopyEx(graphics, m_Texture, nullptr, &m_Rect, 0.0, nullptr, SDL_FLIP_NONE);
}

void Sprite::SetPosition(const int& x, const int& y)
{
	m_Rect.x = x;
	m_Rect.y = y;
}

void Sprite::Translate(int x, int y)
{
	m_Rect.x += x;
	m_Rect.y += y;
}

SDL_Rect* Sprite::GetRec()
{
	return &m_Rect;
}
