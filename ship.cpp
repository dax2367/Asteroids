/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	Ship Class Implementation File
//
//Dev Env:	Visual Studio
//
//Description: Implementation of the functions for the ship class
//		
=======================================================================================================================*/

#include "ship.h"

Ship::Ship() {
	setLocation(getMaxLocations().x/2, getMaxLocations().y/2);
	setVelocity(0,0);
	setAngle(0);
	setRadius(SHIP_RADIUS);
	state=SS_GOOD;
	shipExists();
}

//================================================================================
//Function: 	float getTurnConfig() float getThrustConfig();
//Description: accessor - 
//
//================================================================================
void Ship::setTurn(float someRate)
{
	turn= someRate;

}

//================================================================================
//Function: float getThrustConfig();
//Description: accessor
//
//================================================================================
void Ship::setThrust(float someRate)
{
	thrust = someRate;		
}

//================================================================================
//Function: rotateLeft
//Description: other - Turns the Ship to the left 1 degree counterclockwise
//
//================================================================================
void Ship::rotateLeft()
{
	if(state == SS_GOOD)
	{
		chgAngle(-turn);
	}
}

//================================================================================
//Function: rotateRight
//Description: other  - Turns the Ship to the left 1 degree counterclockwise
//
//================================================================================
void Ship::rotateRight()
{
	if(state == SS_GOOD)
	{
		chgAngle(turn);
	}
}

//================================================================================
//Function: applyThrust
//Description: other - Accelerates the Ship and updates the location
//
//================================================================================
void Ship::applyThrust()
{
	if(state == SS_GOOD)
	{
		float angleDeg = getAngle();
		float forcex= cos((angleDeg-90)*PI/180) * thrust;
		float forcey= sin((angleDeg-90)*PI/180) * thrust;
		thrustFactor(forcex, forcey);
	}
}

//================================================================================
//Function: explode
//Description: other - changes the Ship state from SS_GOOD to SS_EXPLODING and
//					   changes it's velocity to zero and turns off the ability to
//					   apply thrust or turn.
//
//================================================================================
void Ship::explode()
{
	state = SS_EXPLODING;
	setVelocity(0,0);
}

//================================================================================
//Function: shipExists
//Description: other - checks to see if the ship exists before detecting collsions
//					   with asteroids. This prevents the ship from re-exploding
//
//================================================================================	
bool Ship::shipExists()
{
	if(state == SS_GOOD)
	{
		return true;	
	}
	return false;	
}

//================================================================================
//Function: drawShip 
//Description: other - Deterines the ship state and calls either drawGoodShip() or
//					   drawExplodingShip() which in turn draws it on the screen.
//
//================================================================================
void Ship::drawShip(sf::RenderWindow& win)
{
	if(state ==SS_GOOD)
		drawGoodShip(win);
	else if(state == SS_EXPLODING)
		drawExplodingShip(win);
}

//================================================================================
//Function: drawGoodShip draws the ship if it's state is SS_GOOD which is 
//			dertermined and called by drawShip();
//Description: other - Draws the good ship on the screen
//
//================================================================================
void Ship::drawGoodShip(sf::RenderWindow& win)
{
	// drawGoodShip

		sf::ConvexShape Ship;
		Ship.setPointCount(3);
		Ship.setPoint(0, sf::Vector2f(10, 0));
		Ship.setPoint(1, sf::Vector2f(0, 25));
		Ship.setPoint(2, sf::Vector2f(20, 25));

		sf::Vector2f midpoint(10,15);
		Ship.setOrigin(midpoint);

		Ship.setFillColor(sf::Color(0, 0, 0));
		Ship.setOutlineThickness(2);
		Ship.setOutlineColor(sf::Color(255, 255, 255));

		myVector location=getLocation();
		float angle = getAngle();
		Ship.setPosition(location.x, location.y);
		Ship.setRotation(angle);
		win.draw(Ship);
}

//================================================================================
//Function: drawExplodingShip draws the ship if it's state is SS_EXPLODING which is 
//			dertermined and called drawShip();
//Description: other - Draws the exploding ship on the screen
//
//================================================================================

void Ship::drawExplodingShip(sf::RenderWindow& win)
{
	//drawExplodingShip

		sf::CircleShape Ship;

		sf::Vector2f midpoint(getRadius()/2, getRadius()/2);
		Ship.setOrigin(midpoint);

		myVector location = getLocation();
		Ship.setPosition(location.x, location.y);

		Ship.setRadius(getRadius());
		Ship.setOutlineColor(sf::Color::White);
		Ship.setFillColor(sf::Color::Red);
		win.draw(Ship);
		chgRadius(0.1);

		if(getRadius()>50)
		{
			setRadius(50);
			state = SS_GONE;	
		}
}