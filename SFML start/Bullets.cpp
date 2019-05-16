#include "pch.h"
#include "Bullet.h"


Bullet::Bullet(float size)
{
	bullet.setRadius(size);
}


Bullet::~Bullet()
{
}

void Bullet::fire(float angle, float bulletSpeed)
{
	Vector2f speed;
	speed.x += sin(angle)*bulletSpeed;
	speed.y -= cos(angle)*bulletSpeed;
	bullet.move(speed);
}

float Bullet::getX()
{
	return bullet.getPosition().x;
}

float Bullet::getY()
{
	return bullet.getPosition().y;
}

void Bullet::setPos(Vector2f newPos)
{
	bullet.setPosition(newPos);
}


