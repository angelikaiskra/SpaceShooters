#pragma once
#include "..\Include\UI.h"

#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>

class CPlayer
{
	sf::Texture		texture;
	sf::Texture		damagedTex;
	sf::Texture		leftTex;
	sf::Texture		rightTex;

	sf::Sprite		shape;

	CUI UI;

public:
	CPlayer();

	~CPlayer();

	sf::Text		hpText;
	int				HP;
	int				MaxHP;
	int				score = 0;
	int				enemySpawnTimer = 0;
	int				shootTimer = 20;



	//Functions
	sf::Sprite getSprite();
	void setPlayerDamagedTexture();
	void update();


};

