#pragma once
#include "Token.h"
#include <string>

using namespace std;

class Tile
{
private:
	SDL_Point m_Position;
	Token* m_Token;
	Sprite* m_DecorationOver;
	Sprite* m_DecorationRange;
	Sprite* m_DecorationAttack;
	bool m_IsOver;
	bool m_IsRange;
	bool m_IsAttack;
public:
	Tile(SDL_Point position, int size, SDL_Point offset);
	~Tile();
	void Init(SDL_Renderer* renderer);
	void Draw(SDL_Renderer* renderer);
	void RestoreState();
	void InitToken(Token* token);
	void SetToken(Token* token);
	Token* GetToken();
	string ToString();

	bool IsOver();
	void SetOver(bool active);
	bool IsRange();
	void SetRange(bool active);
	bool IsAttack();
	void SetAttack(bool active);
};

