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

bool Pawn::IsInRangeOf(SDL_Point position)
{
	return true;
}

std::vector<SDL_Point> Pawn::GetRangeAttack()
{
	std::vector<SDL_Point> rangeAttack;
	if (IsWhite())
	{
		rangeAttack.push_back({ -1,1 });
		rangeAttack.push_back({ -1,-1 });
	}
	else {
		rangeAttack.push_back({ 1,1 });
		rangeAttack.push_back({ 1,-1 });
	}

	return rangeAttack;
}

std::vector<SDL_Point> Pawn::GetRangeMove()
{
	std::vector<SDL_Point> rangeMove;
	if (IsWhite()) 
	{
		rangeMove.push_back({ -1,0 });
		rangeMove.push_back({ -2,0 });
	} 
	else 
	{
		rangeMove.push_back({ 1,0 });
		rangeMove.push_back({ 2,0 });
	} 

	return rangeMove;
}
