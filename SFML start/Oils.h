#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;


class Oil
{
public:
	Oil(Vector2f size);
	~Oil();

	float getOilX();
	float getOilY();
	void setOilPos(Vector2f newPos);

public:
	RectangleShape oil;


};

