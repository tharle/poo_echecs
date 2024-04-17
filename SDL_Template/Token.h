#pragma once
#include "Sprite.h"
#include <String>

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
public:

	// ------------------------
	// CONSTRUCTOR
	// ------------------------
	Token(float size, bool isWhite, SDL_Point offset);

	// ------------------------
	// M�THODES
	// ------------------------
	void SetPosition(SDL_Point newPosition);
	const bool IsWhite() { return m_IsWhite; }

	// ------------------------
	// M�THODES ABSTRACTS
	// ------------------------
	
	/// <summary>
	/// Init la texture du Token
	/// </summary>
	/// <param name="skinId">code de la skin s�lectionn�</param>
	/// <param name="renderer">Le renderer SDL</param>
	virtual void Init(int skinId, SDL_Renderer* renderer);
	virtual void Draw(SDL_Renderer* renderer);

	/// <summary>
	/// Nom de pi�ce. Ex: Peon: "Pawn"
	/// </summary>
	/// <returns></returns>
	virtual std::string GetName() = 0;// virtual pure

	virtual void Update() = 0;// virtual pure
};

