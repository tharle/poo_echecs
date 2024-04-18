#pragma once
#include "Pawn.h"
#include "SDL_image.h"


class TokenFactory
{
public: 
	static Pawn* CreatePawn(SDL_Renderer* renderer, SDL_Point position, SDL_Point offset, bool isWhite, int skinTokenId);
};

