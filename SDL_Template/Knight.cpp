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
    std::vector<std::vector<SDL_Point>> rangeMove;
    rangeMove = std::vector<std::vector<SDL_Point>>();

    for (int i = 0; i < 8; i++) rangeMove.push_back(std::vector<SDL_Point>());

    rangeMove[0].push_back({ -1,  2 });
    rangeMove[1].push_back({ 1 , 2 });
    rangeMove[2].push_back({ -2,1 });
    rangeMove[3].push_back({ 2, 1 });
    rangeMove[4].push_back({ -1 , -2 });
    rangeMove[5].push_back({ 1 , -2 });
    rangeMove[6].push_back({ -2,-1 });
    rangeMove[7].push_back({ 2, -1 });

    return rangeMove;
}
