/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	Photon Class Header File
//
//Dev Env:	Visual Studio
//
//Description: Definition of the photon class and function prototypes.
//		
=======================================================================================================================*/

#ifndef PHOTON_H  
#define PHOTON_H  

#include <SFML/Graphics.hpp>
#include "SpaceObject.h"


//**************Put the stuff for photons here******************//
class Photon : public SpaceObject
{
private:
	int timeToLive; //counts down to 0

public:
	Photon();
	Photon(myVector loc, myVector vel, float ang);
	bool timeToDie();
	void drawPhoton(sf::RenderWindow& win);
};
#endif