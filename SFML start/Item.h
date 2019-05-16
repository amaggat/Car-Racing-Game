#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Item
{
public:
	Item(Vector2f size);
	~Item();

	float getX();
	float getY();
	void setPos(Vector2f newPos);


public:
	RectangleShape item;
};

