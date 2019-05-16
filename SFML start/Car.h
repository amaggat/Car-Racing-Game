#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

const int num = 8;



class Car
{
public:
	Car(Vector2f size);
	~Car();

public:
	int deathtime = 0, slowtime = 0;
	float maxSpeed = 12;
	RectangleShape car;
	float x, y, speed, angle;
	int n, checkpoint = 0, lap = 0;
	int position;
	bool finish = false;
	float points[num][2] = { 300, 380,
				  1400,400,
				  1380,2600,
				  1940,2600,
				  1940,1550,
				  2565,1550,
				  2560,3240,
				  250, 3340 };


public:
	Vector2f getPosition();

	void move();

	int countCheckPoint();

	int countLap();

	void findTarget();	

	float getSizeY();

	float getSizeX();


};

