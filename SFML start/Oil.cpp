#include "pch.h"
#include "Oils.h"


Oil::Oil(Vector2f size)
{
	oil.setSize(size);
}


Oil::~Oil()
{
}

void Oil::setOilPos(Vector2f newPos)
{
	oil.setPosition(newPos);
}

float Oil::getOilX()
{
	return oil.getPosition().x;
}

float Oil::getOilY()
{
	return oil.getPosition().y;
}