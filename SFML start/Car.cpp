#include "pch.h"
#include "Car.h"


Car::Car(Vector2f size)
{
	car.setSize(size);
	speed = 2; 
	angle = 0; 
	n = 0;
}


Car::~Car()
{
}


Vector2f Car::getPosition()
{
	Vector2f carPos(x, y);
	return carPos;
}

void Car::move()
{
	x += sin(angle) * speed;
	y -= cos(angle) * speed;
}

int Car::countCheckPoint()
{
	float checkX = points[n][0];
	float checkY = points[n][1];
	if ((x - checkX)*(x - checkX) + (y - checkY)*(y - checkY) < 300 * 300)
	{
		checkpoint = n + 1 % (num + 1);
		n = (n + 1) % num;
	}
	return checkpoint;
}

int Car::countLap()
{
	if (checkpoint == 8)
	{
		++lap;
		checkpoint = 0;
	}
	return lap;
}


void Car::findTarget()
{
	float targetX = points[n][0];
	float targetY = points[n][1];
	float beta = angle - atan2(targetX - x, -targetY + y);
	if (sin(beta) < 0) angle += 0.004*speed; else angle -= 0.004*speed;
	if ((x - targetX)*(x - targetX) + (y - targetY)*(y - targetY) < 5 * 5) n = (n + 1) % num;
}


float Car::getSizeX()
{
	return car.getSize().x;
}

float Car::getSizeY()
{
	return car.getSize().y;
}