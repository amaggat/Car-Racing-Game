#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Animations
{
public:
	Animations(Texture* texture, Vector2u ImageCount, float SwitchTime);
	~Animations();

	void Upda(int row, float DeltaTime);

public:
	IntRect uvRect;

private :
	Vector2u ImageCount;
	Vector2u currentImage;

	float TotalTime;
	float SwitchTime;
};

