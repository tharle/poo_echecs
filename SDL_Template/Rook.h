#pragma once
#include "Token.h"

class Rook : public Token
{
public:
	Rook(bool isWhite, SDL_Point offset, int size);
	virtual std::string GetName() override;
	virtual void Update() override;
	virtual std::string ToString() override;
	virtual bool IsInRangeOf(SDL_Point position) override;
	virtual std::vector<std::vector<SDL_Point>> GetRangeMove() override;
	virtual void Init(SDL_Renderer* renderer, SDL_Point position, int skinId) override;
};

