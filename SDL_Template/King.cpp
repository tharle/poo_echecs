#include "King.h"

King::King(bool isWhite, SDL_Point offset, int size) : Queen(isWhite, offset, size)
{
}

std::string King::GetName()
{
	return std::string();
}

void King::Update()
{
}

std::string King::ToString()
{
	return std::string();
}

bool King::IsInRangeOf(SDL_Point position)
{
	return false;
}

std::vector<std::vector<SDL_Point>> King::GetRangeMove()
{
	std::vector<std::vector<SDL_Point>> rangeMovesQueen = Queen::GetRangeMove();
	std::vector<std::vector<SDL_Point>> rangeMoves = std::vector<std::vector<SDL_Point>>();

	for (std::vector<SDL_Point> moves : rangeMovesQueen) 
	{
		std::vector<SDL_Point> kingMove = std::vector<SDL_Point>();
		kingMove.push_back(moves[0]);
		rangeMoves.push_back(kingMove);
	}

	return rangeMoves;
}
