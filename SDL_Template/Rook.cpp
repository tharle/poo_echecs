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
    if (m_RangeMoves.size() > 0) return m_RangeMoves;

    for(int i = 0; i < 4; i++) m_RangeMoves.push_back(std::vector<SDL_Point>());

    for (int i = 1; i <= 7; i++) 
    {
        m_RangeMoves[0].push_back({1 * i,0});
        m_RangeMoves[1].push_back({-1 * i,0});
        m_RangeMoves[2].push_back({0,1 * i });
        m_RangeMoves[3].push_back({0, -1 * i });
    }
    
    return m_RangeMoves;
}

void Rook::Init(SDL_Renderer* renderer, SDL_Point position, int skinId)
{
    Token::Init(renderer, position, skinId);
}
