#include "Knight.h"

Knight::Knight(bool isWhite, SDL_Point offset, int size) : Token(isWhite, offset, size)
{
}

std::string Knight::GetName()
{
    return "Knight";
}

void Knight::Update()
{
}

std::string Knight::ToString()
{
    return "H";
}

bool Knight::IsInRangeOf(SDL_Point position)
{
    return false;
}

std::vector<std::vector<SDL_Point>> Knight::GetRangeMove()
{
    if (m_RangeMoves.size() > 0) return m_RangeMoves;

    for (int i = 0; i < 8; i++) m_RangeMoves.push_back(std::vector<SDL_Point>());

    m_RangeMoves[0].push_back({ -1,  2 });
    m_RangeMoves[1].push_back({ 1 , 2 });
    m_RangeMoves[2].push_back({ -2,1 });
    m_RangeMoves[3].push_back({ 2, 1 });
    m_RangeMoves[4].push_back({ -1 , -2 });
    m_RangeMoves[5].push_back({ 1 , -2 });
    m_RangeMoves[6].push_back({ -2,-1 });
    m_RangeMoves[7].push_back({ 2, -1 });

    return m_RangeMoves;
}
