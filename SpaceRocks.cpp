/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	Asteroids-like game... Asteroids is a registered trademark of Atari, Inc. so this is NOT Asteroids.
//
//Dev Env:	Visual Studio
//
//Description: Implementation of the functions for the ship class
//		
=======================================================================================================================*/
#include "ship.h"
#include "Asteroid.h"
#include "Photon.h"
#include "Config.h"


int main()
{
    Config setGame;
	setGame.loadData();



	sf::RenderWindow window( sf::VideoMode(setGame.width, setGame.height), 
		"Delta Quadrant", sf::Style::Titlebar | sf::Style::Close);

	window.setFramerateLimit(120); 
	// this causes loop to execute 120 times a second at most.
	// (a delay is automatically added after screen is drawn)

	Ship deathStar;
	deathStar.setTurn(setGame.configTurn);
	deathStar.setThrust(setGame.configThrust);
	deathStar.setMaxLocations(setGame.width, setGame.height);


	//Create an array of Photon pointers and initialize them to NULL
	Photon* torpedo[MAX_PHOTONS] = {NULL};


	//Create an array of 20 Asteroid pointers and initialize them to NULL
	Asteroid* pAsteroid[MAX_ASTEROIDS]={NULL};

	//put some Asteroids in the array
	for (int x=0; x<setGame.numAst; x++)
	{
		pAsteroid[x] = new Asteroid;
	}

	while (window.isOpen())
	{
		//----------------------------------------------------------
		//handle user input (events and keyboard keys being pressed)
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Space && deathStar.shipExists())
				{
					int x = 0;
					while(x< MAX_PHOTONS && torpedo[x] != NULL)
						x++;
					if(x < MAX_PHOTONS)
					{
						torpedo[x] = new Photon(deathStar.getLocation(), deathStar.getVelocity(), deathStar.getAngle());
					}
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			deathStar.rotateLeft();

		//Rotate ship right when right arrow is pressed.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			deathStar.rotateRight();

		//Apply Thrust when up arrow is pressed.
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			deathStar.applyThrust();
			//displayShipInfo(deathStar);
		}


		//----------------------------------------------------------
		//draw new frame
		window.clear();

		//draw photons
		for(int x=0; x<MAX_PHOTONS; x++)
		{
			if(torpedo[x] !=NULL)
			{
				torpedo[x]->updateLocation();
				torpedo[x]->drawPhoton(window);

				if(!torpedo[x]->timeToDie())
				{
					delete torpedo[x];
					torpedo[x] = NULL;
				}
			}
		}

		//draw ship
		deathStar.updateLocation();
		deathStar.drawShip(window);

		//draw the asteroids using pointers pAsteroid
		for (int x=0; x<MAX_ASTEROIDS; x++)
		{
			if (pAsteroid[x] !=NULL)
			{
				pAsteroid[x]->updateLocation();
				pAsteroid[x]->draw(window);	
			}
		}

		//ship->asteroid collision detection
		if(deathStar.shipExists())
		{
			for (int x=0; x<MAX_ASTEROIDS; x++)
			{
				if (pAsteroid[x] !=NULL)
				{
					if	(objectsIntersect (deathStar, *pAsteroid[x]))
					{
						deathStar.explode();
						deathStar.drawShip(window);
					}
				}
			}
		}

		//asteroid->torpedo collision detection
		for(int x= 0; x < MAX_PHOTONS; x++)
			for(int y = 0; y < MAX_ASTEROIDS; y++)
			{
				if((pAsteroid[y] != NULL) && (torpedo[x] != NULL))
				{
					if(objectsIntersect(*torpedo[x], *pAsteroid[y]))
					{
						delete torpedo[x];
						torpedo[x] = NULL;
						delete pAsteroid[y];
						pAsteroid[y] = NULL;
					}			
				}		
			}

			//redisplay window
			window.display();
	}

	return 0;
}
