#include "Grid.h"
#include <iostream>
#include "Pawn.h"
#include "TokenFactory.h"

Grid::Grid(const SDL_Point offset, const int cellDimension) :
	m_Offset(offset),
	m_CellDimension(cellDimension),
	m_SkinBoardId(2),
	m_SkinTokenId(2),
	m_WhiteCaptureds(list<Token*>()),
	m_BlackCaptureds(list<Token*>()),
	m_Board({})
{
	m_BoardSkin = new Sprite(offset.x, offset.y, GetWidth(), GetHeight());
	for (int i = 0; i < 8; i++)
	{
		m_Board.push_back(vector<Tile*>());
		for (int j = 0; j < 8; j++)
		{
			// SDL_Point position, int size, SDL_Point offset
			m_Board[i].push_back(new Tile({i, j}, cellDimension, offset));
		}
	}

}

Grid::~Grid()
{
	if (m_BoardSkin != nullptr) 
	{
		delete m_BoardSkin;
		m_BoardSkin = nullptr;
	}

	if (m_TokenSelected != nullptr)
	{
		delete m_TokenSelected;
		m_TokenSelected = nullptr;
	}

	if (m_TokenSelectedSprite != nullptr) 
	{
		delete m_TokenSelectedSprite;
		m_TokenSelectedSprite = nullptr;
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_Board[i][j] != nullptr) 
			{
				delete m_Board[i][j];

				m_Board[i][j] = nullptr;
			}
		}
	}

	for (Token* token : m_WhiteCaptureds) 
	{
		delete token;

		token = nullptr;
	}
	
	for (Token* token : m_BlackCaptureds)
	{
		delete token;

		token = nullptr;
	}
}


int Grid::GetWidth() 
{
	return m_CellDimension * 8;
}

int Grid::GetHeight()
{
	return m_CellDimension * 8;
}

void Grid::Init(SDL_Renderer* renderer)
{
	m_BoardSkin->LoadTexture(renderer, "assets/Board/"+std::to_string(m_SkinBoardId) +".png");
	
	for (int i = 0; i < 8; i++) 
	{
		m_Board[1][i]->SetToken(TokenFactory::CreatePawn(renderer, { 6, i }, m_Offset, false, m_SkinTokenId)) ;
		m_Board[6][i]->SetToken(TokenFactory::CreatePawn(renderer, { 6, i }, m_Offset, false, m_SkinTokenId));
		m_Board[4][i]->SetToken(TokenFactory::CreatePawn(renderer, { 6, i }, m_Offset, false, m_SkinTokenId));
		m_Board[5][i]->SetToken(TokenFactory::CreatePawn(renderer, { 6, i }, m_Offset, false, m_SkinTokenId));
		m_Board[3][i]->SetToken(TokenFactory::CreatePawn(renderer, { 6, i }, m_Offset, false, m_SkinTokenId));
		m_Board[2][i]->SetToken(TokenFactory::CreatePawn(renderer, { 6, i }, m_Offset, true, m_SkinTokenId));
	}

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << "[" << m_Board[i][j]->ToString() << "]";
			m_Board[i][j]->Init(renderer);
		}
		std::cout << std::endl;
	}
}

void Grid::Draw(SDL_Renderer* renderer)
{

	// ----------
	//  BOARD
	// ----------
	m_BoardSkin->Draw(renderer);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_Board[i][j] != nullptr)
			{
				m_Board[i][j]->Draw(renderer);
			}
		}
	}

	// ----------
	//  MOUSE SELECTED TOKEN
	// ----------
	if (m_TokenSelectedSprite != nullptr) m_TokenSelectedSprite->Draw(renderer);

	// ----------
	//  TOKENS CAPTUREDS
	// ----------
	int i = 0;
	for (Token* token : m_WhiteCaptureds) token->Draw(renderer);
	for (Token* token : m_BlackCaptureds) token->Draw(renderer);


}


void Grid::MouseDrag(SDL_Point mousePosition)
{
	if (!m_BoardSkin->IsColliding(mousePosition)) return;

	if (m_TokenSelected != nullptr)
	{
		// ici j'ai besoin de être dans la bonne X et Y, donc je l'enverse (oui à nouveau)
		m_TokenSelectedSprite->SetPosition({ mousePosition.y - m_TokenSelectedSprite->GetW()/2, mousePosition.x - 32 + m_TokenSelectedSprite->GetH() / 2 });
	}

	SDL_Point gridPosition = GetGridPointByMousePosition(mousePosition);

	if (m_MouseOverTile == m_Board[gridPosition.x][gridPosition.y]) return;

	//std::cout << "DRAG [" << gridPosition.x << "," << gridPosition.y << "]" << m_Board[gridPosition.x][gridPosition.y]->ToString()<<endl;
	if (m_MouseOverTile != nullptr) m_MouseOverTile->SetOver(false);
	m_MouseOverTile = m_Board[gridPosition.x][gridPosition.y];
	m_MouseOverTile->SetOver(true);
}

void Grid::MouseButtonUp(SDL_Point mousePosition)
{
	if (m_TokenSelected == nullptr) return;

	if (!m_BoardSkin->IsColliding(mousePosition))
	{
		m_TokenSelected->SetPosition(m_OldTokenSelectedPosition);
		m_TokenSelected = nullptr;

		return;
	}
	//std::cout << "Grid [" << gridPosition.x << "," << gridPosition.y << "]" << m_Board[gridPosition.x][gridPosition.y]->ToString()<<endl;

	SDL_Point gridPosition = GetGridPointByMousePosition(mousePosition);
	UnselectToken(gridPosition);
}

void Grid::MouseButtonDown(SDL_Point mousePosition)
{
	if (!m_BoardSkin->IsColliding(mousePosition)) return;

	SDL_Point gridPosition = GetGridPointByMousePosition(mousePosition);
	SelectToken(gridPosition);

}

void Grid::SelectToken(SDL_Point gridPosition)
{
	m_TokenSelected = m_Board[gridPosition.x][gridPosition.y]->GetToken();
	if (m_TokenSelected != nullptr) 
	{
		m_OldTokenSelectedPosition = gridPosition;
		m_TokenSelectedSprite = m_TokenSelected->GetSprite();


		for (SDL_Point direction : m_TokenSelected->GetRangeMove()) 
		{
			int x = direction.x + gridPosition.x;
			int y = direction.y + gridPosition.y;

			// Ça c'est "hard codé" parce que le grid vas être toujours 8x8
			if (x < 0 || x > 7 || y < 0 || y > 7) continue;

			m_Board[x][y]->SetRange(true);
		
			if (!dynamic_cast<Pawn*>(m_TokenSelected)) 	// s'il est pas Pawn, le move et attck sont le même
			{
				if (m_Board[x][y]->GetToken() && !m_Board[x][y]->GetToken()->IsSameTeam(m_TokenSelected)) 
					m_Board[x][y]->SetAttack(true);
			}
			
		}

		// CHECK FOR ATTACK PAWN
		if (dynamic_cast<Pawn*>(m_TokenSelected))
		{
			for (SDL_Point direction : m_TokenSelected->GetRangeAttack())
			{
				int x = direction.x + gridPosition.x;
				int y = direction.y + gridPosition.y;

				// Ça c'est "hard codé" parce que le grid vas être toujours 8x8
				if (x < 0 || x > 7 || y < 0 || y > 7) continue;

				if(m_Board[x][y]->GetToken()) m_Board[x][y]->SetAttack(true);
			}
		}

	}
}

void Grid::UnselectToken(SDL_Point gridPosition) 
{
	Tile* newtile = m_Board[gridPosition.x][gridPosition.y];
	Tile* oldtile = m_Board[m_OldTokenSelectedPosition.x][m_OldTokenSelectedPosition.y];
	if (newtile->IsRange() && !newtile->GetToken())
	{
		std::cout << "IN RANGE MOVE" << endl;
		oldtile->SetToken(nullptr);
		newtile->SetToken(m_TokenSelected);
		// TODO ajouter le "mager token"
	} else if (newtile->IsAttack())
	{
		std::cout << "IN RANGE ATTACK" << endl;		
		if (newtile->GetToken()->IsWhite()) 
		{
			newtile->GetToken()->ChangeOffset({ 0, -12 });

			SDL_Point pos = { m_WhiteCaptureds.size(), 0 };
			if (pos.x > 8) pos = { 8, pos.x % 8 };

			newtile->GetToken()->SetPosition(pos);
			m_WhiteCaptureds.push_back(newtile->GetToken());
		} 
		else 
		{
			newtile->GetToken()->ChangeOffset({ m_BoardSkin->GetW() + 34, m_BoardSkin->GetH()+34});

			SDL_Point pos = { m_BlackCaptureds.size() * -1, 0};
			if (pos.x > 8) pos = { 0, -(pos.x % 8) };

			newtile->GetToken()->SetPosition(pos);
			m_BlackCaptureds.push_back(newtile->GetToken());
		}  

		oldtile->SetToken(nullptr);
		newtile->SetToken(m_TokenSelected);

	} else 
	{
		std::cout << "NO RANGE" << endl;
		oldtile->SetToken(m_TokenSelected);
	}

	RestoreSelectionGrid();

	m_TokenSelected = nullptr;
	m_TokenSelectedSprite = nullptr;
}

SDL_Point Grid::GetGridPointByMousePosition(SDL_Point mousePosition)
{
	return { (mousePosition.x - m_Offset.x) / m_CellDimension,  (mousePosition.y - m_Offset.y) / m_CellDimension };
}

void Grid::RestoreSelectionGrid()
{
	for (std::vector<Tile*> line : m_Board)
	{
		for (Tile* tile : line)
		{
			tile->RestoreState();
		}
	}
}


