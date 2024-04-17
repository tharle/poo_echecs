#include "Token.h"

#define TOKEN_BORDER 16

Token::Token(float size, bool isWhite, SDL_Point offset) :
	m_Size(size), 
	m_IsWhite(isWhite),
	m_Offset(offset),
	m_Sprite(new Sprite(0, 0, size-TOKEN_BORDER, size-TOKEN_BORDER))
{
}

std::string Token::GetPathTexture(int skin)
{
	std::string wOrB = m_IsWhite ? "W" : "B";
	return "assets/" + GetName() + "/" + std::to_string(skin) + "_" + wOrB + ".png";
}


void Token::Init(int skinId, SDL_Renderer* renderer)
{
	std::string pathTexture = GetPathTexture(skinId);
	m_Sprite->LoadTexture(renderer, pathTexture);
}

void Token::Draw(SDL_Renderer* renderer)
{
	m_Sprite->Draw(renderer);
}

void Token::SetPosition(SDL_Point newPosition)
{
	newPosition.x = m_Offset.x + (newPosition.x * m_Size)+ TOKEN_BORDER / 2;
	newPosition.y = m_Offset.x + (newPosition.y * m_Size)+ TOKEN_BORDER / 2;

	m_Sprite->SetPosition(newPosition);
}
