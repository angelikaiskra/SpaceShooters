#pragma once

#include "SFML\Graphics.hpp"


class CBullet
{
public:
	CBullet(sf::Texture *texture, sf::Vector2f pos);

	~CBullet();

	sf::Sprite shape;

};

