#pragma once
#include "Sprite.h"
#include <String>
#include <vector>

class Token 
{
private:
	/// <summary>
	/// Image afiche de la pièce
	/// </summary>
	Sprite* m_Sprite;

	/// <summary>
	/// C'est la dimension des pièces.
	/// </summary>
	float m_Size;

	/// <summary>
	/// Pour savoir quel est la couleur
	/// </summary>
	bool m_IsWhite;

	/// <summary>
	/// Offset du board, pour savoir par où le board commence à être desiné
	/// </summary>
	SDL_Point m_Offset;	


	// ------------------------
	// MÉTHODES PRIVÉES
	// ------------------------
	std::string GetPathTexture(int skin );
protected:
	bool m_IsMoved;
	std::vector<std::vector<SDL_Point>>  m_RangeMoves;

public:

	// ------------------------
	// CONSTRUCTOR
	// ------------------------
	Token(bool isWhite, SDL_Point offset, int size);

	// ------------------------
	// MÉTHODES
	// ------------------------
	void SetPosition(SDL_Point newPosition);
	Sprite* GetSprite(); // Util pour faire desiner le pointer quand il est sélectioné
	const bool IsWhite() { return m_IsWhite; }
	bool IsSameTeam(Token* other);
	void ChangeOffset(SDL_Point offset);

	virtual void Draw(SDL_Renderer* renderer);
	virtual std::vector<SDL_Point> GetRangeAttack();
	virtual void Init(SDL_Renderer* renderer, SDL_Point position, int skinId);

	// ------------------------
	// MÉTHODES ABSTRACTS
	// ------------------------
	

	/// <summary>
	/// Nom de pièce. Ex: Peon: "Pawn"
	/// </summary>
	/// <returns></returns>
	virtual std::string GetName() = 0;// virtual pure
	virtual void Update() = 0;
	virtual std::string ToString() = 0;
	virtual std::vector<std::vector<SDL_Point>> GetRangeMove()  = 0;

	/// <summary>
	/// Vérifie si la position est dans la "Range" pour la pièce se deplacer
	/// </summary>
	/// <returns>true si la position est dans le range, si non false</returns>
	virtual bool IsInRangeOf(SDL_Point position) = 0;
};

