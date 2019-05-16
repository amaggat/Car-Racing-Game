#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Car.h"
#include "Oils.h"
#include "Item.h"
#include "allVar.h"

void playerInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Up)) Up = 1;
	if (Keyboard::isKeyPressed(Keyboard::Right)) Right = 1;
	if (Keyboard::isKeyPressed(Keyboard::Down)) Down = 1;
	if (Keyboard::isKeyPressed(Keyboard::Left)) Left = 1;
	if (Keyboard::isKeyPressed(Keyboard::LShift)) Drift = 1;
	
}

void playerMovement()
{
	if (Up && speed < maxSpeed)
		if (speed < 0)  speed += dec;
		else  speed += acc;

	if (Down && speed > -maxSpeed)
		if (speed > 0) speed -= dec;
		else  speed -= acc;

	if (!Up && !Down)
		if (speed - dec > 0) speed -= dec;
		else if (speed + dec < 0) speed += dec;
		else speed = 0;

	if (Drift && car[0].finish == false)
	{
		turnSpeed = 0.09f;
		++nitro;
	}
		
	else if (Drift == 0 && car[0].finish == false)
	{
		turnSpeed = 0.03f;
	}

	if (Right && speed != 0)  angle += turnSpeed * speed / 12;
	if (Left && speed != 0)   angle -= turnSpeed * speed / 12;

	if (speed >= maxSpeed)
	{
		speed = maxSpeed;
	}

	car[0].speed = speed;
	car[0].angle = angle;
}

void playerSlowdown_Block()
{
	if (car[0].x < 210)
	{
		if (Up) speed = 6;
		if (Down) speed = -6;
	}

	if (car[0].x > 2710)
	{
		if (Up) speed = 6;
		if (Down) speed = -6;
	}

	if (car[0].y > 3440)
	{
		if (Up) speed = 6;
		if (Down) speed = -6;
	}

	if (car[0].y < 280)
	{
		if (Up) speed = 6;
		if (Down) speed = -6;
	}

	if ((car[0].x > 460 && car[0].x < 1260) && (car[0].y > 550 && car[0].y < 3180))
	{
		if (Up) speed = 8;
		if (Down) speed = -8;
	}

	if (car[0].x > 1478 && car[0].y < 1468)
	{
		if (Up) speed = 6;
		if (Down) speed = -6;
	}


	if ((car[0].x < 2222 && car[0].x > 1260) && (car[0].y > 2717 && car[0].y < 3170))
	{
		if (Up) speed = 8;
		if (Down) speed = -8;
	}

}

void car_block()
{
	if (car[0].x < 170) car[0].x = 170;
	if (car[0].y < 152) car[0].y = 152;
	if (car[0].x > 2800) car[0].x = 2800;
	if (car[0].y > 3600) car[0].y = 3600;

}

void _carCollision()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int dx = 0, dy = 0;
			while (dx*dx + dy * dy < 4 * R*R)
			{
				car[i].x += float(dx / 5.0);
				car[i].x += float(dy / 5.0);
				car[j].x -= float(dx / 5.0);
				car[j].y -= float(dy / 5.0);
				dx = int(car[i].x - car[j].x);
				dy = int(car[i].y - car[j].y);
				if (!dx && !dy) break;
			}
		}
}

void finishLap(int totalLap)
{
	for (int i = 0; i < N; ++i)
	{
		car[i].countCheckPoint();
	}


	for (int i = 0; i < N; ++i)
	{
		if (car[i].countLap() == totalLap && i != 0 && car[i].finish == false && car[i].y < 747)
		{
			car[i].speed = 4;
			car[i].finish = true;
			std::cout << Pposition[position] << ":          " << Racer[i] << std::endl;
			Score[position].setString(Pposition[position] + ":          " + Racer[i]);
			++position;
			++_endgame;
		}

		if (car[0].countLap() == totalLap && car[0].finish == false && car[0].y < 747)
		{
			maxSpeed = 4;
			car[0].finish = true;
			std::cout << Pposition[position] << ":          " << Racer[0] << std::endl;
			Score[position].setString(Pposition[position] + ":          " + Racer[0]);
			++position;
			++_endgame;
		}
	}
}


void bulletFire()
{
	if (_Bul)
	{
//		std::cout << "Guns Ready" << std::endl;

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			Firing = true;
		}

		if (Firing)
		{
			Bullet newBul(20.0f);
			newBul.setPos(car[0].getPosition());
			if(buleet.size() <= 4) buleet.push_back(newBul);
			Firing = false;
		}

	}
}

void bulletErase()
{
	if (buleet.size() > 0)
	{
		for (int i = 0; i < buleet.size(); ++i)
		{

			if (buleet[i].getX() < 0 || buleet[i].getY() < 50)
			{
				buleet.erase(buleet.begin() + i);
			}

			else if (buleet[i].getX() > 2880 || buleet[i].getY() > 3648)
			{
				buleet.erase(buleet.begin() + i);
			}
		}
	}
}

void bulletDestroy()
{
	for (int i = 0; i < buleet.size(); ++i)
	{
		for (int k = 1; k < N; k++)
		{
			if (buleet[i].getX() > car[k].getPosition().x - 20.0f
				&& buleet[i].getY() > car[k].getPosition().y - 20.0f
				&& buleet[i].getX() < car[k].getPosition().x + 20.0f
				&& buleet[i].getY() < car[k].getPosition().y + 20.0f)
			{
				buleet[i].setPos(Vector2f(100000.0f, 100000.0f));
				buleet.erase(buleet.begin() + i);
				car[k].speed = 0;
				break;
			}
		}

	}
}



void lasFire()
{
	if (_Las)
	{

	}
}

void oilSpray()
{
	if (_Oil)
	{
//		std::cout << "Oil Ready" << std::endl;

		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			Spraying = true;
			imedPosX = car[0].getPosition().x;
			imedPosY = car[0].getPosition().y;
		}

		if (Spraying)
		{
			Oil newOil(Vector2f(109.0f, 95.0f));
			newOil.setOilPos(Vector2f(imedPosX,imedPosY));
			oil.push_back(newOil);
			Spraying = false;
			_Oil = false;
		}

	}
}

void OilEffect()
{
	for (int i = 0; i < oil.size(); ++i)
	{
		for (int k = 1; k < N; k++)
		{
			if (imedPosX < car[k].getPosition().x - 20.0f
				&& imedPosY < car[k].getPosition().y - 20.0f
				&& imedPosX + 109 > car[k].getPosition().x + 20.0f
				&& imedPosY +95 > car[k].getPosition().y + 20.0f)
			{
				car[k].speed = 3;
			}
		}

	}
}

void checkUp()
{
	for(int i = 0; i < N; ++i)
	{
		if (car[i].speed == 0)
		{
			++car[i].deathtime;
		}

		if (car[i].deathtime >= 100 && car[i].finish == false)
		{
			car[i].speed += acc * 30 * (14 + i)*0.1;
			car[i].deathtime = 0;
		}

		if (car[i].speed == 3)
		{
			++car[i].slowtime;
		}

		if (car[i].slowtime >= 70 && car[i].finish == false)
		{
			if(car[i].speed < 12) car[i].speed += acc * 30 * (14 + i)*0.1;
			else if (car[i].speed >= 12) car[i].speed = 12;
			car[i].slowtime = 0;
		}
	}
}


void createItem()
{
	for (int i = 0; i < num; ++i)
	{
		if (_Gained[i] == 0 && car[0].countLap() == i)
		{
			Item newItem(Vector2f(44.0f, 45.0f));
			newItem.setPos(Vector2f(iPoints[i][0], iPoints[i][1]));
			item.push_back(newItem);
			_Gained[i] = 1;
		}
	}
}

void gainItem()
{
	for (int i = 0; i < item.size(); ++i)
	{
		if (item[i].getX() < car[0].getPosition().x
			&& item[i].getY() < car[0].getPosition().y
			&& item[i].getX() + 44.f > car[0].getPosition().x
			&& item[i].getY() + 45.f > car[0].getPosition().y)
		{
			_Bul = 1;
			_Oil = 1;
			item.erase(item.begin() + i);
		}
	}
}


void NitroBoost()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		Sprint = true;
		if (Sprint && nitro > 0)
		{
			maxSpeed = 16.f;
			nitro -= 1;
		}
		if (nitro <= 0)
		{
			maxSpeed = 13.f;
		}
	}

	else
	{
		maxSpeed = 13.f;
	}
	
}

void Menu(Sprite sMenu, Sprite sIns)
{
	for (int i = 0; i < N; ++i)
	{
		car[i].x = float(325);
		car[i].y = float(1384 - i * 134);
		car[i].speed = float(0);
		car[i].n = 0;
		car[i].angle = 0;
		car[i].lap = 0;
	}
	angle = 0;
	speed = 0;


	app.clear();
	app.draw(sMenu);
	view.setCenter(Vector2f(800.0f, 450.0f));
	app.setView(view);
	if (Keyboard::isKeyPressed(Keyboard::I))
	{
		sIns.setPosition(Vector2f(100.0f, 100.0f));
		app.draw(sIns);
	}
	app.display();

}

void Endgame(Sprite sBackground, Sprite sFinish)
{

	Font font;
	font.loadFromFile("Font/Brushsbi.ttf");
	

	for (int i = 0; i < N; ++i)
	{
		Score[i].setFont(font);
		Score[i].setCharacterSize(50);

	}
	
	Player.setFont(font);
	Player.setCharacterSize(50);

	
	gaming = false;

	app.clear();
	app.draw(sBackground);
	sFinish.setPosition(200.0f, 100.0f);
	app.draw(sFinish);

	for (int i = 0; i < N; ++i)
	{
		Score[i].setPosition(250.0f, 220.0f + 80.0f*i);

		app.draw(Score[i]);
	}

	view.setCenter(Vector2f(800.0f, 450.0f));
	app.setView(view);

	app.display();
}

void Update(Sprite sBackground,Sprite sBullet, Sprite sOil, Sprite sCar, Sprite sBulPoint, Texture _armoredcar, Texture _guncar, Texture _oilcar, Texture _car)
{
		for (int i = 1; i < N; ++i)
		{
			if (car[i].finish == false && car[i].deathtime == 0 && car[i].slowtime == 0)
			{
				if (car[i].speed < 12)
					car[i].speed += acc * 20 * (14 + i)*0.1;

				if (car[i].speed >= 12)
					car[i].speed = 12;
			}
		}
	

	for (int i = 1; i < N; ++i)
	{
		if (car[i].finish == false && car[i].deathtime == 0 && car[i].slowtime == 0)
		{
			if (car[i].speed < 12)
				car[i].speed += acc * 20 * (14 + i)*0.1;

			if (car[i].speed >= 12)
				car[i].speed = 12;
		}
	}

	Up = 0, Right = 0, Down = 0, Left = 0, Drift = 0;


	playerInput();
	playerMovement();

	for (int i = 0; i < N; i++) car[i].move();
	for (int i = 1; i < N; i++) car[i].findTarget();

	_carCollision();
	playerSlowdown_Block();
	car_block();

	bulletFire();
	bulletErase();
	bulletDestroy();

	oilSpray();
	OilEffect();

	createItem();
	gainItem();
	NitroBoost();

	checkUp();

	finishLap(3);
	app.clear(Color::Black);

	app.draw(sBackground);

	view.setCenter(car[0].getPosition());
	app.setView(view);




	for (int i = 2; i < buleet.size(); ++i)
	{
		float bulletAngle = angle;
		buleet[i].fire(bulletAngle, bulletSpeed);
		sBullet.setPosition(buleet[i].getX() - offsetX, buleet[i].getY() - offsetY);
		sBullet.setRotation(float(bulletAngle * 180 / 3.141593));
		_Bul = 0;
	}
	app.draw(sBullet);

	for (int i = 0; i < oil.size(); ++i)
	{
		sOil.setPosition(oil[i].getOilX(), oil[i].getOilY());
	}
	app.draw(sOil);

	for (int i = 0; i < item.size(); ++i)
	{
		sBulPoint.setPosition(item[i].getX(), item[i].getY());
		app.draw(sBulPoint);
	}


	if (_Bul && _Oil)
	{
		sCar.setPosition(car[0].x - offsetX, car[0].y - offsetY);
		sCar.setRotation(float(car[0].angle * 180 / 3.141593));
		sCar.setColor(colors[0]);
		sCar.setTexture(_armoredcar);
		app.draw(sCar);
	}
	else if (_Bul && !_Oil)
	{
		sCar.setPosition(car[0].x - offsetX, car[0].y - offsetY);
		sCar.setRotation(float(car[0].angle * 180 / 3.141593));
		sCar.setColor(colors[0]);
		sCar.setTexture(_guncar);
		app.draw(sCar);
	}

	else if (_Oil && !_Bul)
	{
		sCar.setPosition(car[0].x - offsetX, car[0].y - offsetY);
		sCar.setRotation(float(car[0].angle * 180 / 3.141593));
		sCar.setColor(colors[0]);
		sCar.setTexture(_oilcar);
		app.draw(sCar);
	}
	else
	{
		sCar.setPosition(car[0].x - offsetX, car[0].y - offsetY);
		sCar.setRotation(float(car[0].angle * 180 / 3.141593));
		sCar.setColor(colors[0]);
		app.draw(sCar);
	}


	for (int i = 1; i < N; i++)
	{
		sCar.setPosition(car[i].x - offsetX, car[i].y - offsetY);
		sCar.setRotation(float(car[i].angle * 180 / 3.141593));
		sCar.setColor(colors[i]);
		sCar.setTexture(_car);
		app.draw(sCar);
	}

	view.setCenter(car[0].getPosition());
	app.setView(view);


	app.display();
}