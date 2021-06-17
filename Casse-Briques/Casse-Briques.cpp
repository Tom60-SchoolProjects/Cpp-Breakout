#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include "Balle.h"
#include "Raquette.h"
#include "Brique.h"
#include "Mur.h"

bool pause;
Balle balle;
Raquette raquette;
Brique* briques[40];
sf::RenderWindow window(sf::VideoMode(420, 420), "Casse-Briques");
sf::RectangleShape mur({ Mur::xMax, Mur::yMax + 20 });
sf::Text pauseText;

void init()
{
	// Wall init
	mur.setFillColor(sf::Color(213, 213, 213));
	mur.setPosition(Mur::xMin, Mur::yMin);

	// Bricks init
	int i = 0;
	for (int l = 0; l < 5; l++)
		for (int c = 0; c < 8; c++)
		{
			briques[i] = new Brique(
				Mur::xMin * 2 + c * (Brique::larg + 5),
				Mur::yMin * 2 + l * (Brique::haut + 5),
				sf::Color(20, 200 + l * 10, 20));
			i++;
		}

	// Pause text init
	pauseText.setFillColor(sf::Color(13, 13, 13));
	sf::Font font;

	// Ne fonctionne pas
	/*if (!font.loadFromFile("Fonts/arial.ttf")) // 
		return;

	pauseText.setFont(font);*/
	pauseText.setCharacterSize(24);
	pauseText.setString("Press space to start");
	sf::FloatRect bounds = pauseText.getGlobalBounds();
	pauseText.setPosition(bounds.width / 2, Mur::yMax / 2);
}

void newGame()
{
	// Reset all bricks
	for (int i = 0; i < 40; i++)
		briques[i]->reset();

	// Pause to let the player be ready
	pause = true;

	// Set the default ball position
	balle.setPosition(Mur::xMin + Mur::xMax / 2 - balle.larg, Mur::yMax - balle.larg * 2);
	balle.setDirection(Balle::Direction::NordEst);

	// Set the default racket position
	raquette.setPosition(Mur::xMin + Mur::xMax / 2 - raquette.larg / 2, Mur::yMax);
}

bool hasLose()
{
	return balle.getPosY() >= Mur::yMax;
}

bool hasWon()
{
	int brickRamaning = 0;

	for (int i = 0; i < 40; i++)
		if (!briques[i]->isBreaked())
			brickRamaning++;

	return brickRamaning == 0;
}

void update()
{
	if (!pause)
	{
		// Input handler
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			raquette.gauche();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			raquette.droite();

		// Win/Lose
		if (hasLose())
		{
			int msgboxID = MessageBox(NULL, (LPCWSTR)L"Try again?", (LPCWSTR)L"You lose!", MB_ICONASTERISK | MB_YESNO);

			switch (msgboxID)
			{
			case IDYES:
				newGame();
				break;
			case IDNO:
				window.close();
				break;
			}
		}

		if (hasWon())
		{
			int msgboxID = MessageBox(NULL, (LPCWSTR)L"Try again?", (LPCWSTR)L"You won!", MB_ICONASTERISK | MB_YESNO);

			switch (msgboxID)
			{
			case IDYES:
				newGame();
				break;
			case IDNO:
				window.close();
				break;
			}
		}

		// Ball colider
		for (int i = 0; i < 40; i++)
			balle.rebondir_br(*briques[i]);
		balle.rebondir_m();
		balle.rebondir_r(raquette);

		// Update
		balle.maj();
		raquette.maj();
	}

	// Draw handle
	window.clear(sf::Color::White);

	window.draw(mur);
	window.draw(balle.getShape());
	window.draw(raquette.getShape());
	for (int i = 0; i < 40; i++)
		if (!briques[i]->isBreaked())
			window.draw(briques[i]->getShape());

	if (pause)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			pause = false;

		window.draw(pauseText);
	}

	window.display();
}

int main()
{
	sf::Clock clock;

	init();
	newGame();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					return 0;
			}
		}

		if (clock.getElapsedTime().asMilliseconds() > 10)
		{
			update();
			clock.restart();
		}
	}
	window.close();
}