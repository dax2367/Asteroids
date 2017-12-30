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

#ifndef SPACE_OBJECT_H  
#define SPACE_OBJECT_H  

#include <iostream>
#include <cmath>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "myVector.h"
#include "Constants.h"
#include "Config.h"


class SpaceObject {
private: 
	myVector maxLocations;	//maximum allowable values for location
	myVector location;		//current location (x,y)
	myVector velocity;		//current velocity (in pixels/frame)
	float angleDeg;		//angle ship is facing, in degrees
	float radius;	//gross radius of ship (for collision detection)

public:
	SpaceObject();
	//=============================================
	//mutators
	void setLocation(float x, float y);
	void setVelocity(float velocityX, float velocityY);
	void setAngle(float angDeg);
	void setRadius(float radius);
	void thrustFactor(float deltaVx, float deltaVy); //NEW!
	void chgAngle(float deltaA);				//NEW!
	void chgRadius(float deltaR);				//NEW!
	float getRandomFloat();
	int getRandomInt(int min, int max );
	void setMaxLocations(int someLoc1, int someLoc2);

	//============================================
	//accessors
	float getRadius();
	myVector getLocation();
	myVector getVelocity();
	float getAngle();
	myVector getMaxLocations();

	//============================================
	//others
	void updateLocation();
	friend bool objectsIntersect (SpaceObject object1, SpaceObject object2);
    //Config setGame;
};

#endif