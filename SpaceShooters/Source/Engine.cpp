#include "..\Include\Engine.h"


CEngine::CEngine()
{
	window.create(sf::VideoMode(1200, 800), "Space shooters", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	backgroundText.loadFromFile("Data/space.png");

	enemyTex1.loadFromFile("Data/enemyShip1.png");
	enemyTex2.loadFromFile("Data/enemyShip2.png");
	enemyTex3.loadFromFile("Data/enemyShip3.png");

	bulletTex.loadFromFile("Data/laserGreen.png");
	bulletTexEnemy.loadFromFile("Data/laserRed.png");
	explosionTex.loadFromFile("Data/laserGreenShot.png");

	backgroundSprite.setTexture(backgroundText);
}

void CEngine::makeExplosion(sf::Vector2f &position)
{
	explosionSprite.setTexture(explosionTex);
	explosionSprite.setPosition(position);
}

void CEngine::update()
{
	player.update();

	//Update controls
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && player.shootTimer >= 15)
		{
			bullets.push_back(CBullet(&bulletTex, (player.getSprite().getPosition() + sf::Vector2f(44, -20))));
			player.shootTimer = 0;
		}
	}

	//Bullets
	for (size_t i = 0; i < bullets.size(); i++)
	{
		//Move bullets
		bullets[i].shape.move(0.f, -10.f);

		//Out of window bounds
		if (bullets[i].shape.getPosition().y < 0)
		{
			bullets.erase(bullets.begin() + i);
			break;
		}

		//Enemy collision
		for (size_t k = 0; k < enemies.size(); k++)
		{

			if (bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
			{
				if (enemies[k].HP <= 1)
				{
					player.score += enemies[k].HPMax;
					//makeExplosion(pos);
					enemies.erase(enemies.begin() + k);
				}
				else
					enemies[k].HP--;

				bullets.erase(bullets.begin() + i);
				break;
			}
		}
	}

	//Bullets Enemy
	for (size_t i = 0; i < bulletsEnemy.size(); i++)
	{
		//Move bullets
		bulletsEnemy[i].shape.move(0.f, 6.5f);

		//Out of window bounds
		if (bulletsEnemy[i].shape.getPosition().y < 0)
		{
			bulletsEnemy.erase(bulletsEnemy.begin() + i);
			break;
		}

		if (player.getSprite().getGlobalBounds().intersects(bulletsEnemy[i].shape.getGlobalBounds()))
		{
			player.HP--;

			bulletsEnemy.erase(bulletsEnemy.begin() + i);
			break;
		}
	}


	//Enemy
	if (player.enemySpawnTimer < 60)
		player.enemySpawnTimer++;

	//Enemy spawn
	if (player.enemySpawnTimer >= 60)
	{
		int HPMax = rand() % 3 + 1;
		if (HPMax == 1) {
			enemies.push_back(CEnemy(&enemyTex1, window.getSize(), HPMax));
		}
		else if (HPMax == 2) {
			enemies.push_back(CEnemy(&enemyTex2, window.getSize(), HPMax));
		}
		else {
			enemies.push_back(CEnemy(&enemyTex3, window.getSize(), HPMax));
		}

		player.enemySpawnTimer = 0;
	}

	for (size_t i = 0; i < enemies.size(); i++)
	{
		enemies[i].shape.move(0.f, 5.f);

		if (enemies[i].shape.getPosition().y < 20) {
			bulletsEnemy.push_back(CBullet(&bulletTexEnemy, (enemies[i].shape.getPosition() + sf::Vector2f(44, 20))));
		}

		if (enemies[i].shape.getPosition().y >= window.getSize().y)
		{
			enemies.erase(enemies.begin() + i);
			break;
		}

		if (enemies[i].shape.getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
		{
			enemies.erase(enemies.begin() + i);

			player.HP--;
			break;
		}

	}

	//UI Update
	UI.scoreText.setString("Score: " + std::to_string(player.score));

	UI.drawHeart(player.score);
	

}

void CEngine::draw()
{
	window.clear();
	window.draw(backgroundSprite);

	//player
	window.draw(player.getSprite());

	//bullets
	for (int i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i].shape);
	}

	for (int i = 0; i < bulletsEnemy.size(); i++)
	{
		window.draw(bulletsEnemy[i].shape);
	}

	//enemy
	for (size_t i = 0; i < enemies.size(); i++)
	{
		window.draw(enemies[i].shape);
	}

	//UI
	window.draw(UI.scoreText);
	window.draw(player.hpText);


	if (player.HP <= 0)
	{
		window.draw(UI.gameOverText);
	}

	window.display();

	if (player.HP <= 0)
	{
		Sleep(5000);
		exit(0);
	}
}

void CEngine::start()
{
	srand(time(NULL));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		update();
		draw();
	}
}

CEngine::~CEngine()
{
}