#include "..\Include\UI.h"

CUI::CUI()
{
	font.loadFromFile("Data/Fonts/font.ttf");

	//Init score
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(10.f, 10.f);

	//Init gameOver
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(50);
	gameOverText.setFillColor(sf::Color::Red);
	gameOverText.setPosition(425.f, 400);
	gameOverText.setString("GAME OVER!");

	heartTex.loadFromFile("Data/life.png");
}

sf::Sprite CUI::drawHeart(int number) {

	sf::Sprite heart;

	for (int i=0; i < number; i++) {
		heart.setTexture(heartTex);
		heart.setPosition(15.f + number * 3, 10.f);
	}

	return heart;
}


CUI::~CUI()
{
}
