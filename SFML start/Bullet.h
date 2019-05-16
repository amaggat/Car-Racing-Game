#pragma once
#include <SFML/Graphics.hpp>


using namespace sf;
class Bullet
{
public:

	Bullet(float size);
	~Bullet();
	CircleShape bullet;


public:

	void fire(float angle, float bulletSpeed);
	float getX();
	float getY();
	void setPos(Vector2f newPos);

private:


};

