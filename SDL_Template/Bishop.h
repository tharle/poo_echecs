#pragma once
#include "Token.h"
class Bishop : public Token
{
public:
	Bishop(bool isWhite, SDL_Point offset, int size);
	virtual std::string GetName() override;
	virtual void Update() override;
	virtual std::string ToString() override;
	virtual bool IsInRangeOf(SDL_Point position) override;
	virtual std::vector<std::vector<SDL_Point>> GetRangeMove() override;
};

