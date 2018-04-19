#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <iostream>
#include <windows.h>


class CEngine
{
private:
	sf::RenderWindow window;

	//Init textures
	sf::Texture playerTex;
	sf::Texture enemyTex;
	sf::Texture bulletTex;
	sf::Texture backgroundText;
	sf::Texture explosionTex;

	sf::Sprite backgroundSprite;
	sf::Sprite explosionSprite;

	// An instance of player
	CPlayer player;

	//Init Bullets
	std::vector<CBullet> bullets;
	std::vector<CBullet> bulletsEnemy;

	// Init Enemy
	std::vector<CEnemy> enemies;

	CUI UI;


public:
	// The Engine constructor
	CEngine();

	// start will call all the private functions
	void start();
	void update();

	void draw();

	void makeExplosion(sf::Vector2f &position);

	~CEngine();

};