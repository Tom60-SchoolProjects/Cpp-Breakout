#pragma once

#include <SFML/Graphics.hpp>
#include "Brique.h"
#include "Raquette.h"

class Balle
{
public:
	enum Direction { NordEst = 1, NordOuest = 2, SudEst = 3, SudOuest = 4 };

	const int vitesse = 1, larg = 10;
	Direction dir = NordEst;

	Balle();

	int getPosX();
	int getPosY();
	sf::CircleShape getShape();
	void setPosition(int, int);
	void setDirection(Direction);
	void maj();
	void rebondir_br(Brique&);
	void rebondir_m();
	void rebondir_r(Raquette);

private:
	sf::CircleShape balle;
	int posX = 10, posY = 10;
};
