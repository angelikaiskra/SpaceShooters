#include "..\Include\Player.h"

CPlayer::CPlayer()
{
	this->MaxHP = 10;
	this->HP = this->MaxHP;
	this->shape.setPosition(650, 400);

	damagedTex.loadFromFile("Data/playerDamaged.png");
	leftTex.loadFromFile("Data/playerLeft.png");
	rightTex.loadFromFile("Data/playerRight.png");
	texture.loadFromFile("Data/player.png");

	shape.setTexture(texture);

	hpText.setFont(UI.font);
	hpText.setCharacterSize(12);
	hpText.setFillColor(sf::Color::White);
}

sf::Sprite CPlayer::getSprite()
{
	return shape;
}

void CPlayer::setPlayerDamagedTexture()
{
	shape.setTexture(damagedTex);
}

void CPlayer::update()
{
	if (HP <= 4)
	{
		shape.setTexture(damagedTex);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
	{
		if (HP > 4)
			shape.setTexture(texture);
		shape.move(0.f, -15.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
	{
		if (HP > 4)
			shape.setTexture(texture);
		shape.move(0.f, 15.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (HP > 4)
			shape.setTexture(leftTex);
		shape.move(-15.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (HP > 4)
			shape.setTexture(rightTex);
		shape.move(15.f, 0.f);
	}


	hpText.setPosition(shape.getPosition().x, shape.getPosition().y - hpText.getGlobalBounds().height);
	hpText.setString(std::to_string(this->HP) + "/" + std::to_string(this->MaxHP));

	//Player collision with window
	if (shape.getPosition().x <= 0) //Left
		shape.setPosition(0.f, shape.getPosition().y);
	if (shape.getPosition().x + shape.getGlobalBounds().width >= 1200) //Right
		shape.setPosition(1200 - shape.getGlobalBounds().width, shape.getPosition().y);

	if (shape.getPosition().y <= 0) //Top
		shape.setPosition(shape.getPosition().x, 0.f);
	if (shape.getPosition().y + shape.getGlobalBounds().height >= 800) //Bottom
		shape.setPosition(shape.getPosition().x, 800 - shape.getGlobalBounds().height);


	if (shootTimer < 15)
	{
		shootTimer++;
	}

}

CPlayer::~CPlayer()
{
}
