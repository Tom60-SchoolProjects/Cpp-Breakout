#include <SFML/Graphics.hpp>
#include "Raquette.h"
#include "Mur.h"

Raquette::Raquette()
{
	sf::Vector2f size(larg, haut);
	raquette = sf::RectangleShape(size);
	raquette.setFillColor(sf::Color::Cyan);
}

int Raquette::getPosX()
{
	return posX;
}

int Raquette::getPosY()
{
	return posY;
}

sf::RectangleShape Raquette::getShape()
{
	return raquette;
}

void Raquette::setPosition(int x, int y)
{
	posX = x;
	posY = y;
	raquette.setPosition(posX, posY);
}

void Raquette::maj()
{
	raquette.setPosition(posX, posY);
}

void Raquette::gauche()
{
	if (posX != Mur::xMin)
		posX--;
}

void Raquette::droite()
{
	if (posX + larg != Mur::xMin + Mur::xMax)
		posX++;
}