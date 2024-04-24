#pragma once
#include "Token.h"
#include <string>

#define STATE_NONE 0
#define STATE_OVER 1
#define STATE_RANGE 2
#define STATE_ATACK 3

using namespace std;

class Tile
{
private:
	SDL_Point m_Position;
	Token* m_Token;
	Sprite* m_Decoration;
	int m_State;
	SDL_Renderer* m_Renderer;
public:
	Tile(SDL_Point position, int size, SDL_Point offset);
	~Tile();
	void Draw(SDL_Renderer* renderer);

	void ChangeState(int state);
	void SetToken(Token* token);
	string ToString();

};

