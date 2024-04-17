#pragma once
#include "Sprite.h"
#include <String>

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
public:

	// ------------------------
	// CONSTRUCTOR
	// ------------------------
	Token(float size, bool isWhite, SDL_Point offset);

	// ------------------------
	// MÉTHODES
	// ------------------------
	void SetPosition(SDL_Point newPosition);
	const bool IsWhite() { return m_IsWhite; }

	// ------------------------
	// MÉTHODES ABSTRACTS
	// ------------------------
	
	/// <summary>
	/// Init la texture du Token
	/// </summary>
	/// <param name="skinId">code de la skin sélectionné</param>
	/// <param name="renderer">Le renderer SDL</param>
	virtual void Init(int skinId, SDL_Renderer* renderer);
	virtual void Draw(SDL_Renderer* renderer);

	/// <summary>
	/// Nom de pièce. Ex: Peon: "Pawn"
	/// </summary>
	/// <returns></returns>
	virtual std::string GetName() = 0;// virtual pure

	virtual void Update() = 0;// virtual pure
};

