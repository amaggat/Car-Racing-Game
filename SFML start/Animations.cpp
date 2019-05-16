#include "pch.h"
#include "Animations.h"


Animations::Animations(Texture* texture, Vector2u ImageCount, float SwitchTime)
{
	this->ImageCount = ImageCount;
	this->SwitchTime = SwitchTime;

	TotalTime = 0.0f;
	currentImage.x = 0;


	uvRect.width = texture->getSize().x / float(ImageCount.x);
	uvRect.height = texture->getSize().y / float(ImageCount.y);

}


Animations::~Animations()
{
}


void Animations::Upda(int row, float DeltaTime)
{
	currentImage.y = row;
	TotalTime += DeltaTime;

	if (TotalTime >= SwitchTime)
	{
		TotalTime -= SwitchTime;
		++currentImage.x;

		if (currentImage.x >= ImageCount.x)
		{
			currentImage.x = 0;
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}