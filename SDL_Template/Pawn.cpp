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
	if (m_RangeMoves.size() > 0 && m_IsMoved && m_RangeMoves[0].size() <= 1) return m_RangeMoves;

	m_RangeMoves = std::vector<std::vector<SDL_Point>>();

	m_RangeMoves.push_back(std::vector<SDL_Point>());
	int modif = IsWhite() ? -1 : 1;
	m_RangeMoves[0].push_back({ 1 * modif,0 });
	if(!m_IsMoved) m_RangeMoves[0].push_back({ 2 * modif,0 });

	return m_RangeMoves;
}
