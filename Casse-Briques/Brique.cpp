#include "Brique.h"

Brique::Brique(int posX, int posY, sf::Color color)
{
	this->posX = posX;
	this->posY = posY;

	sf::Vector2f size(larg, haut);
	brique.setSize(size);
	brique.setFillColor(color);
	brique.setPosition(posX, posY);
}

int Brique::getPosX()
{
	return posX;
}

int Brique::getPosY()
{
	return posY;
}

sf::RectangleShape Brique::getShape()
{
	return brique;
}

void Brique::_break()
{
	breaked = true;
}

bool Brique::isBreaked()
{
	return breaked;
}

void Brique::reset()
{
	breaked = false;
}
