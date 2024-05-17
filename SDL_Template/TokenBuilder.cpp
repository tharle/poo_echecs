#include "TokenBuilder.h"

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

Bishop* TokenBuilder::CreateBishop(bool isWhite, SDL_Point position, int skinId)
{
	Bishop* bishop = new Bishop(isWhite, m_Offset, SIZE_TOKENS);
	bishop->Init(m_Renderer, position, skinId);
	return bishop;
}

Knight* TokenBuilder::CreateKight(bool isWhite, SDL_Point position, int skinId)
{
	Knight* knight = new Knight(isWhite, m_Offset, SIZE_TOKENS);
	knight->Init(m_Renderer, position, skinId);
	return knight;
}

Queen* TokenBuilder::CreateQueen(bool isWhite, SDL_Point position, int skinId)
{
	Queen* queen = new Queen(isWhite, m_Offset, SIZE_TOKENS);
	queen->Init(m_Renderer, position, skinId);
	return queen;
}

King* TokenBuilder::CreateKing(bool isWhite, SDL_Point position, int skinId)
{
	King* king = new King(isWhite, m_Offset, SIZE_TOKENS);
	king->Init(m_Renderer, position, skinId);
	return king;
}


