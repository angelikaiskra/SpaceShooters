#pragma once
#include "SFML\Graphics.hpp"

class CUI
{
public:

	sf::Font font;

	sf::Text scoreText;
	sf::Text gameOverText;

	sf::Texture heartTex;

	CUI();

	void update();
	sf::Sprite drawHeart(int number);

	~CUI();
};

