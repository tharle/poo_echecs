#include "King.h"

King::King(bool isWhite, SDL_Point offset, int size) : Queen(isWhite, offset, size)
{
}

std::string King::GetName()
{
	return "King";
}

void King::Update()
{
}

std::string King::ToString()
{
	return "K";
}

bool King::IsInRangeOf(SDL_Point position)
{
	return false;
}

std::vector<std::vector<SDL_Point>> King::GetRangeMove()
{
	if (m_RangeMoves.size() > 0) return m_RangeMoves;

	std::vector<std::vector<SDL_Point>> rangeMovesQueen = Queen::GetRangeMove();

	for (std::vector<SDL_Point> moves : rangeMovesQueen) 
	{
		std::vector<SDL_Point> kingMove = std::vector<SDL_Point>();
		kingMove.push_back(moves[0]);
		m_RangeMoves.push_back(kingMove);
	}

	return m_RangeMoves;
}
