#include "TokenFactory.h"

#define SIZE_TOKENS 64
TokenBuilder TokenBuilder::Config(SDL_Point offset, SDL_Renderer* renderer)
{
	TokenBuilder builder = TokenBuilder();
	builder.m_Renderer = renderer;
	builder.m_Offset = offset;

	return builder;
}

Pawn* TokenBuilder::CreatePawn(bool isWhite, SDL_Point position, int skinId)
{	
	Pawn* pawn = new Pawn(isWhite, m_Offset, SIZE_TOKENS);
	pawn->Init(m_Renderer, position, skinId);
	return pawn;
}

Rook* TokenBuilder::CreateRook(bool isWhite, SDL_Point position, int skinId)
{
	Rook* rook = new Rook(isWhite, m_Offset, SIZE_TOKENS);
	rook->Init(m_Renderer, position, skinId);
	return rook;
}

Token* TokenBuilder::CreateBishop(bool isWhite, SDL_Point position, int skinId)
{
	return nullptr;
}

Token* TokenBuilder::CreateKight(bool isWhite, SDL_Point position, int skinId)
{
	return nullptr;
}

Token* TokenBuilder::CreateQueen(bool isWhite, SDL_Point position, int skinId)
{
	return nullptr;
}

Token* TokenBuilder::CreateKing(bool isWhite, SDL_Point position, int skinId)
{
	return nullptr;
}


