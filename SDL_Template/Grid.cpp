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

vector<int> GetRandomSkin() 
{
	vector<int> skins = vector<int>();
	skins = vector<int>();
	for (int i = 0; i < 6; i++) 
	{
		int nSkin = 0;
		bool exist = false;
		do
		{
			nSkin = rand() % 386 + 1;
			exist = false;
			for (int skin : skins)
			{
				if (skin == nSkin) 
				{
					exist = true;
					break;
				}
			}
		} while (exist);
		skins.push_back(nSkin);
	}
	return skins;
}

void Grid::Init(SDL_Renderer* renderer)
{
	m_BoardSkin->LoadTexture(renderer, "assets/Board/"+std::to_string(m_SkinBoardId) +".png");
	
	TokenBuilder builder = TokenBuilder::Config(m_Offset, renderer);
	
	vector<int> skins = GetRandomSkin();

	for (int i = 0; i < 8; i++) 
	{
		m_Board[1][i]->InitToken(builder.CreatePawn(false, { 1, i }, skins[0]));
		m_Board[6][i]->InitToken(builder.CreatePawn(true, { 6, i }, skins[0]));
	}

	m_Board[7][0]->InitToken(builder.CreateRook(true, { 7, 0 }, skins[1]));
	m_Board[7][7]->InitToken(builder.CreateRook(true, { 7, 7 }, skins[1]));
	m_Board[0][0]->InitToken(builder.CreateRook(false, { 0, 0 }, skins[1]));
	m_Board[0][7]->InitToken(builder.CreateRook(false, { 0, 7 }, skins[1]));

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
	if (m_TokenSelectedSprite != nullptr) 
	{
		
		SDL_RendererFlip flip = m_TokenSelected->IsWhite() ? SDL_RendererFlip::SDL_FLIP_NONE : SDL_RendererFlip::SDL_FLIP_VERTICAL;
		m_TokenSelectedSprite->Draw(renderer, flip);
	} 

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
		m_TokenSelected->SetPosition(m_TokenSelectedPositionOld);
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
		m_TokenSelectedPositionOld = gridPosition;
		m_TokenSelectedSprite = m_TokenSelected->GetSprite();

		for (vector<SDL_Point> directions : m_TokenSelected->GetRangeMove()) 
		{
			for (SDL_Point direction : directions)
			{
				int x = direction.x + gridPosition.x;
				int y = direction.y + gridPosition.y;

				// Ça c'est "hard codé" parce que le grid vas être toujours 8x8
				if (x < 0 || x > 7 || y < 0 || y > 7) continue;

				Tile* tileSelected = m_Board[x][y];

				if (!tileSelected->GetToken()) 
				{
					tileSelected->SetRange(true);
					continue;
				}
		
				if (!dynamic_cast<Pawn*>(m_TokenSelected)) 	// s'il est pas Pawn, le move et attck sont le même
				{
					if (!tileSelected->GetToken()->IsSameTeam(m_TokenSelected))
						tileSelected->SetAttack(true);
				}

				if (tileSelected->GetToken()) break;
			}
		}

		// CHECK FOR ATTACK PAWN
		if (dynamic_cast<Pawn*>(m_TokenSelected))
		{
			for (SDL_Point direction : m_TokenSelected->GetRangeAttack())
			{
				int x = direction.x + gridPosition.x;
				int y = direction.y + gridPosition.y;

				cout << y << "," << x << endl;
				// Ça c'est "hard codé" parce que le grid vas être toujours 8x8
				if (x < 0 || x > 7 || y < 0 || y > 7) continue;

				Tile* tileSelected = m_Board[x][y];
				if(tileSelected->GetToken() && !tileSelected->GetToken()->IsSameTeam(m_TokenSelected))
					tileSelected->SetAttack(true);
			}
		}

	}
}

void Grid::UnselectToken(SDL_Point gridPosition) 
{
	Tile* tileTarget = m_Board[gridPosition.x][gridPosition.y];
	Tile* tileOld = m_Board[m_TokenSelectedPositionOld.x][m_TokenSelectedPositionOld.y];
	if (tileTarget->IsRange() && !tileTarget->GetToken())
	{
		std::cout << "IN RANGE MOVE" << endl;
		tileOld->SetToken(nullptr);
		tileTarget->SetToken(m_TokenSelected);
		// TODO ajouter le "mager token"
	} else if (tileTarget->IsAttack())
	{ 
		CaptureToken(tileTarget->GetToken());

		tileOld->SetToken(nullptr);
		tileTarget->SetToken(m_TokenSelected);

	} else 
	{
		std::cout << "NO RANGE" << endl;
		tileOld->SetToken(m_TokenSelected);
	}

	RestoreSelectionGrid();

	m_TokenSelected = nullptr;
	m_TokenSelectedSprite = nullptr;
}

void Grid::CaptureToken(Token* token)
{
	cout << "IN RANGE ATTACK" << endl;
	if (token->IsWhite())
	{
		token->ChangeOffset({ 34, -12 });

		SDL_Point pos = { m_WhiteCaptureds.size(), 0 };
		if (pos.x > 8) pos = { 8, pos.x % 8 };

		token->SetPosition(pos);
		m_WhiteCaptureds.push_back(token);
	}
	else
	{
		token->ChangeOffset({ m_BoardSkin->GetH() - 6, m_BoardSkin->GetW() + 34 });

		SDL_Point pos = { m_BlackCaptureds.size() * -1, 0 };
		if (pos.x < -8) pos = { -8, pos.x % 8 };

		token->SetPosition(pos);
		m_BlackCaptureds.push_back(token);
	}
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


