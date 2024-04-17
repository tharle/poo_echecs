#pragma once
#include "Token.h"

class Pawn : public Token
{

private:
public:
	Pawn(int size, bool isWhite, SDL_Point offset);
	virtual std::string GetName();
	virtual void Update();
};

