#pragma once

#include <SFML/Graphics.hpp>

class Brique
{
public:
	static const int larg = 60;
	static const int haut = 15;
	bool breaked = false;

	Brique();

	int getPosX();
	int getPosY();
	sf::RectangleShape getShape();
	void setPosition(int, int);
	void maj();
	void reset();

private:
	int posX = 0;
	int posY = 0;
	sf::RectangleShape brique;
};
