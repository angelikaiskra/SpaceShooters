#include "../Include/Enemy.h"



CEnemy::CEnemy(sf::Texture *texture, sf::Vector2u windowSize)
{
	this->HPMax = rand() % 3 + 1; //z przedzia³u 1-3
	this->HP = this->HPMax;

	this->shape.setTexture(*texture);

	this->shape.setPosition(rand() % (int)(windowSize.x - this->shape.getLocalBounds().width), 0);

}


CEnemy::~CEnemy()
{
}
