#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;



const int num = 8;
float points[num][2] = { 330, 450,
					  1355,450,
					  1412,2530,
					  1906,2530,
					  1800,1600,
					  2555,1600,
					  2560,3150,
					  390, 3300 };

struct Car
{
	float x, y, speed, angle;
	int n, checkpoint = 0, lap = 0;
	bool finish = false;

	Car() { speed = 2; angle = 0; n = 0; }

	Vector2f getPosition()
	{
		Vector2f carPos(x, y);
		return carPos;
	}

	void move()
	{
		x += sin(angle) * speed;
		y -= cos(angle) * speed;
	}

	int countCheckPoint()
	{
		float tx = points[n][0];
		float ty = points[n][1];
		if ((x - tx)*(x - tx) + (y - ty)*(y - ty) < 200 * 200)
		{
			checkpoint = n + 1 % (num+1);
			n = (n + 1) % num;
		}
		return checkpoint;
	}

	int countLap()
	{
		if (checkpoint == 8)
		{
			++lap;
			checkpoint = 0;
		}
		return lap;
	}

	void findTarget()
	{
		float targetX = points[n][0];
		float targetY = points[n][1];
		float beta = angle - atan2(targetX - x, -targetY + y);
		if (sin(beta) < 0) angle += 0.004*speed; else angle -= 0.004*speed;
		if ((x - targetX)*(x - targetX) + (y - targetY)*(y - targetY) < 10 * 10) n = (n + 1) % num;
	}
};