#include "pch.h"
#include "Item.h"


Item::Item(Vector2f size)
{
	item.setSize(size);
}


Item::~Item()
{
}


float Item::getX()
{
	return item.getPosition().x;
}

float Item::getY()
{
	return item.getPosition().y;
}

void Item::setPos(Vector2f newPos)
{
	item.setPosition(newPos);
}