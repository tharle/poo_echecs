#include "Bishop.h"

Bishop::Bishop(bool isWhite, SDL_Point offset, int size) : Token(isWhite, offset, size)
{
}

std::string Bishop::GetName()
{
    return "Bishop";
}

void Bishop::Update()
{
}

std::string Bishop::ToString()
{
    return "B";
}

bool Bishop::IsInRangeOf(SDL_Point position)
{
    return false;
}

std::vector<std::vector<SDL_Point>> Bishop::GetRangeMove()
{
    if (m_RangeMoves.size() > 0) return m_RangeMoves;

    for (int i = 0; i < 4; i++) m_RangeMoves.push_back(std::vector<SDL_Point>());

    for (int i = 1; i <= 7; i++)
    {
        m_RangeMoves[0].push_back({ 1 * i, 1 * i });
        m_RangeMoves[1].push_back({ -1 * i, 1 * i });
        m_RangeMoves[2].push_back({ 1 * i,-1 * i });
        m_RangeMoves[3].push_back({ -1 * i, -1 * i });
    }

    return m_RangeMoves;
}
