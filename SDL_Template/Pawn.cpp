#include "Pawn.h"

Pawn::Pawn(int size, bool isWhite, SDL_Point offset): Token(size, isWhite, offset)
{
}

std::string Pawn::GetName()
{
	return "Pawn";
}

void Pawn::Update()
{
	// Do nothing
}

std::string Pawn::ToString()
{
	return "P";
}
