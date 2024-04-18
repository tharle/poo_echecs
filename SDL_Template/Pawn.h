#pragma once
#include "Token.h"

class Pawn : public Token
{

private:
public:
	Pawn(int size, bool isWhite, SDL_Point offset);
	virtual std::string GetName() override;
	virtual void Update() override;
	virtual std::string ToString() override;
};

