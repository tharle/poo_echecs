#include "TokenFactory.h"

#define SIZE_TOKENS 64

Pawn* TokenFactory::CreatePawn(SDL_Renderer* renderer, SDL_Point position, SDL_Point offset, bool isWhite, int skinTokenId)
{
	Pawn* pawn = new Pawn(SIZE_TOKENS, isWhite, offset);
	pawn->Init(skinTokenId, renderer);
	return pawn;
}
