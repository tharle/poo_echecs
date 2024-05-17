#include "Token.h"

#define TOKEN_BORDER 16

Token::Token(bool isWhite, SDL_Point offset, int size) :
	m_Size(size), 
	m_IsWhite(isWhite),
	m_Offset(offset),
	m_IsMoved(false),
	m_Sprite(new Sprite(0, 0, size-TOKEN_BORDER, size-TOKEN_BORDER))
{

}

void Token::Init(SDL_Renderer* renderer, SDL_Point position, int skinId)
{
	std::string pathTexture = GetPathTexture(skinId);
	m_Sprite->LoadTexture(renderer, pathTexture);
	SetPosition(position);

	m_IsMoved = false;
}

std::string Token::GetPathTexture(int skin)
{
	std::string word = m_IsWhite ? "W" : "B";
//	return "assets/" + GetName() + "/" + std::to_string(skin) + "_" + word + ".png";
	return "assets/Pokemons/" + word + "/" + std::to_string(skin) + ".png";
}

void Token::Draw(SDL_Renderer* renderer)
{
	SDL_RendererFlip flip = m_IsWhite ? SDL_RendererFlip::SDL_FLIP_NONE : SDL_RendererFlip::SDL_FLIP_VERTICAL;
	m_Sprite->Draw(renderer, flip);
}

std::vector<SDL_Point> Token::GetRangeAttack()
{
	return std::vector<SDL_Point>();
}

void Token::SetPosition(SDL_Point newPosition)
{
	int x = m_Offset.x + (newPosition.x * m_Size) + TOKEN_BORDER / 2;
	int y = m_Offset.y + (newPosition.y * m_Size) + TOKEN_BORDER / 2;

	//il fait l'invertion pour désiner
	m_Sprite->SetPosition({ y, x });

	m_IsMoved = true;
}

Sprite* Token::GetSprite()
{
	return m_Sprite;
}

bool Token::IsSameTeam(Token* other)
{
	return other && this->m_IsWhite == other->m_IsWhite;
}

void Token::ChangeOffset(SDL_Point offset)
{
	m_Offset = offset;
}
