#pragma once
#include "Queen.h"

class King : public Queen
{
public:
	King(bool isWhite, SDL_Point offset, int size);
	virtual std::string GetName() override;
	virtual void Update() override;
	virtual std::string ToString() override;
	virtual bool IsInRangeOf(SDL_Point position) override;
	virtual std::vector<std::vector<SDL_Point>> GetRangeMove() override;
};

