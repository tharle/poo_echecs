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
    std::vector<std::vector<SDL_Point>> rangeMoveRook = m_Rook.GetRangeMove();
    std::vector<std::vector<SDL_Point>> rangeMoveBishop = m_Bishop.GetRangeMove();

    rangeMoveRook.insert(std::end(rangeMoveRook), std::begin(rangeMoveBishop), std::end(rangeMoveBishop));
    return rangeMoveRook;
}
