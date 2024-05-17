#pragma once
#include "Pawn.h"
#include "Rook.h"
#include "SDL_image.h"


class TokenBuilder
{
private:
	SDL_Renderer* m_Renderer;
	SDL_Point m_Offset;
public: 
	static TokenBuilder Config(SDL_Point offset, SDL_Renderer* renderer);
	Pawn* CreatePawn(bool isWhite, SDL_Point position, int skinId);
	Rook* CreateRook(bool isWhite, SDL_Point position, int skinId);
	Token* CreateBishop(bool isWhite, SDL_Point position, int skinId);
	Token* CreateKight(bool isWhite, SDL_Point position, int skinId);
	Token* CreateQueen(bool isWhite, SDL_Point position, int skinId);
	Token* CreateKing(bool isWhite, SDL_Point position, int skinId);

};

