#pragma once
#include "SDL_image.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"


class TokenBuilder
{
private:
	SDL_Renderer* m_Renderer;
	SDL_Point m_Offset;
public: 
	static TokenBuilder Config(SDL_Point offset, SDL_Renderer* renderer);
	Pawn* CreatePawn(bool isWhite, SDL_Point position, int skinId);
	Rook* CreateRook(bool isWhite, SDL_Point position, int skinId);
	Bishop* CreateBishop(bool isWhite, SDL_Point position, int skinId);
	Knight* CreateKight(bool isWhite, SDL_Point position, int skinId);
	Queen* CreateQueen(bool isWhite, SDL_Point position, int skinId);
	King* CreateKing(bool isWhite, SDL_Point position, int skinId);

};

