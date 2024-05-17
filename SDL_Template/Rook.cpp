#include "Rook.h"

Rook::Rook(bool isWhite, SDL_Point offset, int size) : Token(isWhite, offset, size)
{
}

std::string Rook::GetName()
{
    return "Rook";
}

void Rook::Update()
{
    // Do noting
}

std::string Rook::ToString()
{
    return "R";
}

bool Rook::IsInRangeOf(SDL_Point position)
{
    return false;
}

std::vector<std::vector<SDL_Point>> Rook::GetRangeMove()
{
    std::vector<std::vector<SDL_Point>> rangeMove;
    rangeMove = std::vector<std::vector<SDL_Point>>();

    for(int i = 0; i < 4; i++) rangeMove.push_back(std::vector<SDL_Point>());

    for (int i = 1; i <= 7; i++) 
    {
        rangeMove[0].push_back({1 * i,0});
        rangeMove[1].push_back({-1 * i,0});
        rangeMove[2].push_back({0,1 * i });
        rangeMove[3].push_back({0, -1 * i });
    }
    
    return rangeMove;
}

void Rook::Init(SDL_Renderer* renderer, SDL_Point position, int skinId)
{
    Token::Init(renderer, position, skinId);
}
