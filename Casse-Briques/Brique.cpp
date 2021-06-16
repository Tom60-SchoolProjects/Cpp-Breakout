#include "Brique.h"

Brique::Brique()
{
	sf::Vector2f size(larg, haut);
	brique.setSize(size);
	brique.setFillColor(sf::Color::Green);
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

void Brique::setPosition(int x, int y)
{
	posX = x;
	posY = y;
	brique.setPosition(posX, posY);
}

void Brique::maj()
{

}

void Brique::reset()
{

}
