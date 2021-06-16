#include <SFML/Graphics.hpp>
#include "Balle.h"
#include "Brique.h"
#include "Mur.h"
#include "Raquette.h"

Balle::Balle()
{
	balle = sf::CircleShape(larg);
	balle.setFillColor(sf::Color::Red);
}

int Balle::getPosX()
{
	return posX;
}

int Balle::getPosY()
{
	return posY;
}

sf::CircleShape Balle::getShape()
{
	return balle;
}

void Balle::setPosition(int x, int y)
{
	posX = x;
	posY = y;
	balle.setPosition(posX, posY);
}

void Balle::setDirection(Direction d)
{
	dir = d;
}

void Balle::maj()
{
	switch (dir)
	{
	case Direction::NordEst:
		posX += vitesse;
		posY -= vitesse;
		break;

	case Direction::NordOuest:
		posX -= vitesse;
		posY -= vitesse;
		break;

	case Direction::SudEst:
		posX += vitesse;
		posY += vitesse;
		break;

	case Direction::SudOuest:
		posX -= vitesse;
		posY += vitesse;
		break;
	}

	balle.setPosition(posX, posY);
}

void Balle::rebondir_br(Brique br)
{
	switch (dir)
	{
	case Direction::NordEst:
		if (posX == br.getPosX())
			dir = Direction::NordOuest;
		if (posY == br.getPosY())
			dir = Direction::SudEst;
		break;

	case Direction::NordOuest:
		if (posX == br.getPosX() + br.larg)
			dir = Direction::NordEst;
		if (posY == br.getPosY())
			dir = Direction::SudOuest;
		break;

	case Direction::SudEst:
		if (posX == br.getPosX())
			dir = Direction::SudOuest;
		if (posY == br.getPosY() + br.haut)
			dir = Direction::NordEst;
		break;

	case Direction::SudOuest:
		if (posX == br.getPosX() + br.larg)
			dir = Direction::SudEst;
		if (posY == br.getPosY() + br.haut)
			dir = Direction::NordOuest;
		break;
	}
}

void Balle::rebondir_m()
{
	switch (dir)
	{
	case Direction::NordEst:
		if (posY <= Mur::yMin) // Nord
			dir = Direction::SudEst;
		if (posX >= Mur::xMax) // Est
			dir = Direction::NordOuest;
		break;

	case Direction::NordOuest:
		if (posY <= Mur::yMin) // Nord
			dir = Direction::SudOuest;
		if (posX <= Mur::xMin) // Ouest
			dir = Direction::NordEst;
		break;

	case Direction::SudEst:
		/*if (posY >= Mur::yMax) // Sud
			dir = Direction::NordEst;*/
		if (posX >= Mur::xMax) // Est
			dir = Direction::SudOuest;
		break;

	case Direction::SudOuest:
		/*if (posY >= Mur::yMax) // Sud
			dir = Direction::NordOuest;*/
		if (posX <= Mur::xMin) // Ouest
			dir = Direction::SudEst;
		break;
	}
}

void Balle::rebondir_r(Raquette r)
{
	if (0 < posX - r.getPosX() && posX - r.getPosX() < r.larg && 0 < (posY + larg * 2) - r.getPosY())
	{
		switch (dir)
		{
		case Direction::SudEst:
			dir = Direction::NordOuest;
			break;

		case Direction::SudOuest:
			dir = Direction::NordEst;
			break;
		}
	}
}