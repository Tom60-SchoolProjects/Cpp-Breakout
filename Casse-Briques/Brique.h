#pragma once

#include <SFML/Graphics.hpp>

class Brique
{
public:
	static const int larg = 38, haut = 15;

	//Brique();
	Brique(int, int, sf::Color);

	int getPosX();
	int getPosY();
	sf::RectangleShape getShape();
	//void init(int, int, sf::Color);
	void _break();
	bool isBreaked();
	void reset();

private:
	int posX = 0, posY = 0;
	bool breaked;
	sf::RectangleShape brique;
};
