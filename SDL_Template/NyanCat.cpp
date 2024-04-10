#include "NyanCat.h"
#include "Game.h"
#include <SDL_image.h>

NyanCat::NyanCat()
{
	m_Sprite = new Sprite(0.0f, 0.0f, 128, 128);
}

NyanCat::~NyanCat()
{

}

void NyanCat::Init(SDL_Renderer* graphics)
{
	m_Sprite->LoadTexture(graphics, "assets/nyancat_big.png");
}

/// <summary>
/// Cette fonction dessine un image
/// </summary>
void NyanCat::Draw(SDL_Renderer* graphics)
{	
	m_Sprite->Draw(graphics);
}

/// <summary>
/// Cette fonction doit faire parcourir l'image vers la droite de 2 pixel chaque frame.
/// Lorsque le bord de la fenetre en x est touché, l'image doit descendre de 128 pixels. 
/// Lorsque le bord de la fenetre en y est touché, l'image doit remonter en haut de l'écran
/// Vous devez utiliser la variable static SCREEN_WIDTH et SCREEN_HEIGHT dans la classe Game. (Game::SCREEN_WIDTH & Game::SCREEN_HEIGHT)
/// </summary>
void NyanCat::Update()
{
	m_Sprite->TranslateX(10);

	if (m_Sprite->GetX() > Game::SCREEN_WIDTH)
	{
		m_Sprite->TranslateX(-Game::SCREEN_WIDTH);

		if (m_Sprite->GetY() >= Game::SCREEN_HEIGHT)
		{
			m_Sprite->TranslateY(-Game::SCREEN_HEIGHT);
		} 
		else
		{
			m_Sprite->TranslateY(128);
		}
	}
}