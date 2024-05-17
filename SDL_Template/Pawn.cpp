#include "Pawn.h"

Pawn::Pawn(bool isWhite, SDL_Point offset, int size): Token(isWhite, offset, size)
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

std::vector<std::vector<SDL_Point>> Pawn::GetRangeMove()
{
	std::vector <std::vector<SDL_Point>> rangeMove = std::vector<std::vector<SDL_Point>>();
	rangeMove.push_back(std::vector<SDL_Point>());
	if (IsWhite()) 
	{
		rangeMove[0].push_back({-1,0});
		if (!m_IsMoved) rangeMove[0].push_back({ -2,0 });
	} 
	else 
	{
		rangeMove[0].push_back({ 1,0 });
		if (!m_IsMoved) rangeMove[0].push_back({ 2,0 });
	} 

	return rangeMove;
}
