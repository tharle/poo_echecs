#pragma once
#include "Sprite.h"
#include <String>
#include <vector>

class Token 
{
private:
	/// <summary>
	/// Image afiche de la pi�ce
	/// </summary>
	Sprite* m_Sprite;

	/// <summary>
	/// C'est la dimension des pi�ces.
	/// </summary>
	float m_Size;

	/// <summary>
	/// Pour savoir quel est la couleur
	/// </summary>
	bool m_IsWhite;

	/// <summary>
	/// Offset du board, pour savoir par o� le board commence � �tre desin�
	/// </summary>
	SDL_Point m_Offset;	


	// ------------------------
	// M�THODES PRIV�ES
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
	// M�THODES
	// ------------------------
	void SetPosition(SDL_Point newPosition);
	Sprite* GetSprite(); // Util pour faire desiner le pointer quand il est s�lection�
	const bool IsWhite() { return m_IsWhite; }
	bool IsSameTeam(Token* other);
	void ChangeOffset(SDL_Point offset);

	virtual void Draw(SDL_Renderer* renderer);
	virtual std::vector<SDL_Point> GetRangeAttack();
	virtual void Init(SDL_Renderer* renderer, SDL_Point position, int skinId);

	// ------------------------
	// M�THODES ABSTRACTS
	// ------------------------
	

	/// <summary>
	/// Nom de pi�ce. Ex: Peon: "Pawn"
	/// </summary>
	/// <returns></returns>
	virtual std::string GetName() = 0;// virtual pure
	virtual void Update() = 0;
	virtual std::string ToString() = 0;
	virtual std::vector<std::vector<SDL_Point>> GetRangeMove()  = 0;

	/// <summary>
	/// V�rifie si la position est dans la "Range" pour la pi�ce se deplacer
	/// </summary>
	/// <returns>true si la position est dans le range, si non false</returns>
	virtual bool IsInRangeOf(SDL_Point position) = 0;
};

