/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	Ship Class Header File
//
//Dev Env:	Visual Studio
//
//Description: Definition of the ship class and function prototypes.
//		
=======================================================================================================================*/

#ifndef SHIP_H  
#define SHIP_H  

#include <SFML/Graphics.hpp>
#include "SpaceObject.h"

enum ShipState{SS_GOOD, SS_EXPLODING, SS_GONE};


class Ship : public SpaceObject {
public:
	Ship();
	void rotateLeft();
	void rotateRight();
	void applyThrust();
	void drawShip(sf::RenderWindow& win);
	void drawGoodShip(sf::RenderWindow& win);
	void drawExplodingShip(sf::RenderWindow& win);
	void explode();
	bool shipExists();
	void setTurn(float someRate);
	void setThrust(float someRate);

	
private:
	ShipState state;
	float turn;
	float thrust;

};

#endif