#include <SFML/Graphics.hpp>
#include "Balle.h"
#include "Brique.h"
#include "Mur.h"
#include "Raquette.h"

Balle::Balle()
{
	balle.setRadius(larg);
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

void Balle::rebondir_br(Brique& br)
{
	if (br.isBreaked())
		return;

	if (0 < posX - br.getPosX() && posX - br.getPosX() < br.larg && posY + larg * 2 - br.getPosY() == 0) // Haut
	{
		br._break();

		switch (dir)
		{
		case Direction::SudEst:
			dir = Direction::NordEst;
			break;

		case Direction::SudOuest:
			dir = Direction::NordOuest;
			break;
		}
	}
	if (0 < posX + larg * 2 - br.getPosX() && posX - br.getPosX() < br.larg && posY - br.getPosY() == br.haut) // Bas
	{
		br._break();

		switch (dir)
		{
		case Direction::NordEst:
			dir = Direction::SudEst;
			break;

		case Direction::NordOuest:
			dir = Direction::SudOuest;
			break;
		}
	}
	if (0 < posY - br.getPosY() && posY - br.getPosY() < br.haut && posX + larg * 2 - br.getPosX() == 0) // Gauche
	{
		br._break();

		switch (dir)
		{
		case Direction::NordEst:
			dir = Direction::NordOuest;
			break;

		case Direction::SudEst:
			dir = Direction::SudOuest;
			break;
		}
	}
	if (0 < posY + larg * 2 - br.getPosY() && posY - br.getPosY() < br.haut && posX - br.getPosX() == br.larg) // Droite
	{
		br._break();

		switch (dir)
		{
		case Direction::NordOuest:
			dir = Direction::NordEst;
			break;

		case Direction::SudOuest:
			dir = Direction::SudEst;
			break;
		}
	}

	/*if (0 < posX + larg * 2 - br.getPosX() && posX - br.getPosX() < br.larg &&
		0 < posY + larg * 2 - br.getPosY() && posY - br.getPosY() < br.haut)
	{
		br._break();

		if (0 < posX - larg - br.getPosX() && posX - br.getPosX() < br.larg)
		{
			switch (dir)
			{
			case Direction::NordEst:
				dir = Direction::SudEst;
				break;

			case Direction::NordOuest:
				dir = Direction::SudOuest;
				break;

			case Direction::SudEst:
				dir = Direction::NordEst;
				break;

			case Direction::SudOuest:
				dir = Direction::NordOuest;
				break;
			}
		}
		else
		{
			switch (dir)
			{
			case Direction::NordEst:
				dir = Direction::NordOuest;
				break;

			case Direction::NordOuest:
				dir = Direction::NordEst;
				break;

			case Direction::SudEst:
				dir = Direction::SudOuest;
				break;

			case Direction::SudOuest:
				dir = Direction::SudEst;
				break;
			}
		}
	}*/
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
			dir = Direction::NordEst;
			break;

		case Direction::SudOuest:
			dir = Direction::NordOuest;
			break;
		}
	}
}