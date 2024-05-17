#include "Queen.h"

Queen::Queen(bool isWhite, SDL_Point offset, int size) : Token(isWhite, offset, size), 
    m_Rook(isWhite, offset, size), 
    m_Bishop(isWhite, offset, size)
{
}

std::string Queen::GetName()
{
    return "Queen";
}

void Queen::Update()
{
}

std::string Queen::ToString()
{
    return "Q";
}

bool Queen::IsInRangeOf(SDL_Point position)
{
    return false;
}

std::vector<std::vector<SDL_Point>> Queen::GetRangeMove()
{
    if (m_RangeMoves.size() > 0) return m_RangeMoves;

    m_RangeMoves  = m_Rook.GetRangeMove();
    std::vector<std::vector<SDL_Point>> rangeMoveBishop = m_Bishop.GetRangeMove();

    m_RangeMoves.insert(std::end(m_RangeMoves), std::begin(rangeMoveBishop), std::end(rangeMoveBishop));

    return m_RangeMoves;
}
