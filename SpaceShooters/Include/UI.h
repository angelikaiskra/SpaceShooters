#pragma once
#include "SFML\Graphics.hpp"

class CUI
{
public:

	sf::Font font;

	sf::Text scoreText;
	sf::Text gameOverText;


	CUI();

	void update();

	~CUI();
};

