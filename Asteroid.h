/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	Asteroid Class Header File
//
//Dev Env:	Visual Studio
//
//Description: Definition of the asteroid class and function prototypes.
//		
=======================================================================================================================*/

#ifndef ASTEROID_H  
#define ASTEROID_H  

#include <SFML/Graphics.hpp>
#include "SpaceObject.h"


//**************Put the stuff for asteroids here******************//
class Asteroid : public SpaceObject {
private:
	int sides;
	float rotationalVelocity;
	myVector validStartLocation();
public:
	Asteroid();
	void draw(sf::RenderWindow& win);
};

#endif