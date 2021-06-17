#pragma once

#include <SFML/Graphics.hpp>
#include "Mur.h"

class Raquette
{
public:
	const int larg = 100, haut = 10, vitesse = 2;

	Raquette();

	int getPosX();
	int getPosY();
	sf::RectangleShape getShape();
	void setPosition(int, int);
	void maj();
	void gauche();
	void droite();

private:
	int posX, posY;
	sf::RectangleShape raquette;
};