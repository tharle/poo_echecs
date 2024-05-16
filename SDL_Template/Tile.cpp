#include "Tile.h"

Tile::Tile(SDL_Point position, int size, SDL_Point offset) :
	m_Position(position),
	m_Token(nullptr),
	m_IsOver(false),
	m_IsAttack(false),
	m_IsRange(false)
{
	int x = offset.x + position.x * size;
	int y = offset.y + position.y * size;

	m_DecorationOver = new Sprite(y, x, size, size); // il fait l'invertion pour désiner
	m_DecorationAttack = new Sprite(y, x, size, size); 
	m_DecorationRange = new Sprite(y, x, size, size); 
}

Tile::~Tile() 
{
	if (m_Token != nullptr)
	{
		delete m_Token;
		m_Token = nullptr;
	}

	if (m_DecorationOver != nullptr)
	{
		delete m_DecorationOver;
		m_DecorationOver = nullptr;
	}

	if (m_DecorationAttack != nullptr)
	{
		delete m_DecorationAttack;
		m_DecorationAttack = nullptr;
	}

	if (m_DecorationRange != nullptr)
	{
		delete m_DecorationRange;
		m_DecorationRange = nullptr;
	}
}

void Tile::Init(SDL_Renderer* renderer)
{
	m_DecorationOver->LoadTexture(renderer, "assets/UI/1.png");
	m_DecorationRange->LoadTexture(renderer, "assets/UI/2.png");
	m_DecorationAttack->LoadTexture(renderer, "assets/UI/3.png");
}

void Tile::Draw(SDL_Renderer* renderer)
{	
	if (m_Token != nullptr) m_Token->Draw(renderer);

	if(m_IsOver) m_DecorationOver->Draw(renderer);
	else if(m_IsAttack) m_DecorationAttack->Draw(renderer);
	else if (m_IsRange) m_DecorationRange->Draw(renderer);
}

void Tile::RestoreState()
{
	m_IsOver = false;
	m_IsAttack = false;
	m_IsRange = false;
}

void Tile::SetToken(Token* token)
{
	m_Token = token;
	if(m_Token != nullptr) m_Token->SetPosition(m_Position);
}

Token* Tile::GetToken()
{
	return m_Token;
}

string Tile::ToString()
{
	return m_Token != nullptr ? m_Token->ToString() : " ";
}

bool Tile::IsOver()
{
	return m_IsOver;
}

void Tile::SetOver(bool active)
{
	m_IsOver = active;
}

bool Tile::IsRange()
{
	return m_IsRange;
}

void Tile::SetRange(bool active)
{
	m_IsRange = active;
}

bool Tile::IsAttack()
{
	return m_IsAttack;
}

void Tile::SetAttack(bool active)
{
	m_IsAttack = active;
}
