/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	Photon Class Implementation File
//
//Dev Env:	Visual Studio
//
//Description: Implementation of the functions for the Photon class
//		
=======================================================================================================================*/

#include "Photon.h"
#include "SpaceObject.h"

//default constructor
Photon::Photon()
{
	setRadius(0.5);
	timeToLive = 0;
}

//================================================================================
//Function: Photon(myVector loc, myVector vel, float ang)
//Description: put photon relative to ship loction
//================================================================================
Photon::Photon(myVector loc, myVector vel, float ang)
{
	setLocation(loc.x, loc.y);
	setVelocity(vel.x + cos ((ang - 90) * PI / 180) * 3, vel.y + sin ((ang - 90) * PI / 180) * 3);
	setAngle(ang);
	timeToLive = 150;
}

//================================================================================
//Function: bool timeToDie()
//Description:	checks to see if it is time for the photon to die
//================================================================================
bool Photon::timeToDie()
{
	if(timeToLive <= 0)
		return false;

	return true;
}

//draw the photon
void Photon::drawPhoton(sf::RenderWindow& win)
{
	if(timeToDie())
	{
		timeToLive -=1;

		sf::ConvexShape Photon;
		Photon.setPointCount(4);
		Photon.setPoint(0, sf::Vector2f(0,0));
		Photon.setPoint(1, sf::Vector2f(0,1));
		Photon.setPoint(2, sf::Vector2f(1,1));
		Photon.setPoint(3, sf::Vector2f(1,0));

		sf::Vector2f midpoint(0.5, 0.5);
		Photon.setOrigin(midpoint);

		Photon.setFillColor(sf::Color::Yellow);
		Photon.setOutlineThickness(2);
		Photon.setOutlineColor(sf::Color::Red);
		
		myVector location = getLocation();

		Photon.setPosition(location.x, location.y);

		win.draw(Photon);
	}
}
