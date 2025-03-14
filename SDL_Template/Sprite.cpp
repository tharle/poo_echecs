#include "Sprite.h"

Sprite::Sprite(float x, float y, float w, float h)
	: m_Texture(nullptr)
	, m_Rect(SDL_Rect())
	, m_Visible(true)
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
	Draw(graphics, SDL_FLIP_NONE);
}

void Sprite::Draw(SDL_Renderer* graphics, SDL_RendererFlip sdlFlipId)
{
	if (m_Visible) SDL_RenderCopyEx(graphics, m_Texture, nullptr, &m_Rect, 0.0, nullptr, sdlFlipId);
}

void Sprite::SetPosition(const SDL_Point newPosition)
{
	m_Rect.x = newPosition.x;
	m_Rect.y = newPosition.y;
}

void Sprite::Translate(SDL_Point distance)
{
	m_Rect.x += distance.x;
	m_Rect.y += distance.y;
}

void Sprite::SetVisible(bool visible)
{
	m_Visible = visible;
}

bool Sprite::IsColliding(SDL_Point point)
{
	return SDL_PointInRect(&point, &m_Rect);
}

int Sprite::GetH()
{
	return m_Rect.w;
}

int Sprite::GetW()
{
	return m_Rect.h;
}
