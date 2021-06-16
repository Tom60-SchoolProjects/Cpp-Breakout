#pragma once

class Brique
{
public:
	const int larg = 30;
	const int haut = 10;
	bool breaked;

	Brique();

	int getPosX();
	int getPosY();
	void reset();

private:
	int posX = 0;
	int posY = 0;
};
