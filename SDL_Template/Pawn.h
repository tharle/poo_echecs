#pragma once
#include "Token.h"

class Pawn : public Token
{

private:
	SDL_Point m_StartPosition;
public:
	Pawn(int size, bool isWhite, SDL_Point offset);
	virtual std::string GetName() override;
	virtual void Update() override;
	virtual std::string ToString() override;
	virtual bool IsInRangeOf(SDL_Point position) override;
	virtual std::vector<SDL_Point> GetRangeMove();
	virtual std::vector<SDL_Point> GetRangeAttack();
};

