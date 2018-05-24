#include "../Include/Enemy.h"


CEnemy::CEnemy(sf::Texture *texture, sf::Vector2u windowSize, int HPMax)
{
	this->HPMax = HPMax;
	this->HP = this->HPMax;

	this->shape.setTexture(*texture);

	this->shape.setPosition(rand() % (int)(windowSize.x - this->shape.getLocalBounds().width), 0);

}


CEnemy::~CEnemy()
{
}
