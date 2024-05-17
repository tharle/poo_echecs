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
    std::vector<std::vector<SDL_Point>> rangeMove;
    rangeMove = std::vector<std::vector<SDL_Point>>();

    for (int i = 0; i < 4; i++) rangeMove.push_back(std::vector<SDL_Point>());

    for (int i = 1; i <= 7; i++)
    {
        rangeMove[0].push_back({ 1 * i, 1 * i });
        rangeMove[1].push_back({ -1 * i, 1 * i });
        rangeMove[2].push_back({ 1 * i,-1 * i });
        rangeMove[3].push_back({ -1 * i, -1 * i });
    }

    return rangeMove;
}
