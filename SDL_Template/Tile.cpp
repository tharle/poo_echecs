#include "Tile.h"

Tile::Tile(SDL_Point position, int size, SDL_Point offset) :
	m_Position(position),
	m_Token(nullptr),
	m_State(STATE_NONE),
	m_Renderer(nullptr)
{
	int x = offset.x + position.x * size;
	int y = offset.y + position.y * size;

	m_Decoration = new Sprite(x, y, size, size);
}

Tile::~Tile() 
{
	if (m_Token != nullptr)
	{
		delete m_Token;
		m_Token = nullptr;
	}

	if (m_Decoration != nullptr) 
	{
		delete m_Decoration;
		m_Decoration = nullptr;
	}

	m_Renderer = nullptr; // lui, il va être detrui dans game
}

void Tile::Draw(SDL_Renderer* renderer)
{
	m_Renderer = renderer;
	if (m_Token != nullptr) m_Token->Draw(renderer);
	m_Decoration->Draw(renderer);
}

void Tile::ChangeState(int state)
{
	m_State = state;

	m_Decoration->LoadTexture(m_Renderer, "assets/UI/" + to_string(state) + ".png");
}

void Tile::SetToken(Token* token)
{
	m_Token = token;
	token->SetPosition(m_Position);
}

string Tile::ToString()
{
	return m_Token != nullptr ? m_Token->ToString() : " ";
}
