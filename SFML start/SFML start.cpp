#include "pch.h"
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Update.h"
#include "SFML/Audio.hpp"

using namespace sf;
  

int main()
{

	for (int i = 0; i < N; ++i)
	{
		Car newCar(Vector2f(43.0f, 45.0f));
		newCar.x = float(325);
		newCar.y = float(1384 - i * 134);
		newCar.speed = float(0);
		car.push_back(newCar);
	}


	Texture _back, _car, _bullet, _laser, _oil, _armoredcar, _bullPoint, _oilcar, _guncar, _menu, _instruction, _finish;
	Music song1;

	song1.openFromFile("Music/RacingMusic.wav");


	_menu.loadFromFile("images/Menu.png");
	_back.loadFromFile("images/background.png");
	_car.loadFromFile("images/car_green_3.png");
	_armoredcar.loadFromFile("images/gun_oil_car.png");
	_oilcar.loadFromFile("images/oil_car_3.png");
	_guncar.loadFromFile("images/gun_car.png");
	_bullet.loadFromFile("images/fire_red.png");
	_oil.loadFromFile("images/oil.png");
	_bullPoint.loadFromFile("images/cone_straight.png");
	_instruction.loadFromFile("images/instruction.png");
	_finish.loadFromFile("images/Scoreboard.png");

	_bullPoint.setSmooth(true);
	_oil.setSmooth(true);
	_back.setSmooth(true);
	_car.setSmooth(true);
	_bullet.setSmooth(true);
	_laser.setSmooth(true);

	Sprite sBackground(_back), sCar(_car), sBullet(_bullet), sLaser(_laser), sOil(_oil), sBulPoint(_bullPoint), sMenu(_menu), sIns(_instruction), sFinish(_finish);

	app.setFramerateLimit(60);
	sBackground.scale(2, 2);
	sCar.setOrigin(21.5f, 22.5f);
	sCar.scale(0.5f, 0.5f);
	sBullet.scale(1.f, 1.f);
	sOil.scale(1.0f, 1.0f);
	sIns.scale(0.75f, 0.75f);

	song1.play();

	while (app.isOpen())
	{
		Event e;

		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();




			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				gaming = true;
				command = false;
				_endgame = 0;
				for (int i = 0; i < N; ++i)
				{
					car[i].finish = false;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				gaming = false;
				command = true;
			}
		}

		if(gaming)
		{
			Update(sBackground, sBullet, sOil, sCar, sBulPoint, _armoredcar, _guncar, _oilcar, _car);
			
		}

		if (_endgame == 5 && !command)
		{
			Endgame(sBackground, sFinish);
		}

		if (!gaming && command)
		{
			Menu(sMenu, sIns);
		}

	}

	return 0;
}
