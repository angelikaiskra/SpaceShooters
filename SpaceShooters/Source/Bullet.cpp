#include "..\Include\Bullet.h"

#include "SFML\Graphics.hpp"



CBullet::CBullet(sf::Texture *texture, sf::Vector2f pos)
{
	this->shape.setTexture(*texture);

	this->shape.setPosition(pos);
}

CBullet::~CBullet()
{
}
