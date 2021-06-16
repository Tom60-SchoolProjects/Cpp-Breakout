#pragma once

#include <SFML/Graphics.hpp>
#include "Brique.h"
#include "Raquette.h"

class Balle
{
public:
	enum Direction { NordEst = 1, NordOuest = 2, SudEst = 3, SudOuest = 4 };
	Direction dir = NordEst;
	int vitesse = 1;
	int larg = 10;

	Balle();

	int getPosX();
	int getPosY();
	sf::CircleShape getShape();
	void setPosition(int, int);
	void setDirection(Direction);
	void maj();
	void rebondir_br(Brique);
	void rebondir_m();
	void rebondir_r(Raquette);

private:
	sf::CircleShape balle;
	int posX = 10;
	int posY = 10;
};
