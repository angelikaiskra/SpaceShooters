#pragma once

#include <vector>
#include <SFML\Graphics.hpp>

class CEnemy 
{
public:
	CEnemy(sf::Texture *texture, sf::Vector2u windowSize, int HPMax);

	~CEnemy();

	std::vector<CEnemy> enemies;

	int			HP;
	int			HPMax;

	sf::Sprite shape;

};

