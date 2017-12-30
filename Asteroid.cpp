/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	Asteroid Class Implementation File
//
//Dev Env:	Visual Studio
//
//Description: Implementation of the functions for the Asteroid class
//		
=======================================================================================================================*/

#include "Asteroid.h"

//================================================================================
//Function: Default constructor
//Description: instantiates Asteroids
//================================================================================

Asteroid::Asteroid()
{
		
	setRadius(ASTEROID_RADIUS);
	setVelocity(getRandomFloat(),getRandomFloat());
	myVector startLocation = validStartLocation();
	setLocation(startLocation.x, startLocation.y);

	
		
	/*myVector tempRandom;
	tempRandom.x = getRandomInt(1,getMaxLocations().x);
	tempRandom.y = getRandomInt(1,getMaxLocations().y);
	while (sqrt(pow(tempRandom.x - (1/2 * getMaxLocations().x), 2) + 
				pow(tempRandom.y - (1/2 * getMaxLocations().y), 2))
			<= (ASTEROID_RADIUS + (SHIP_RADIUS * SAFE_ZONE_MULTIPLIER)))
	{
					tempRandom.x = getRandomInt(1,getMaxLocations().x);
					tempRandom.y = getRandomInt(1,getMaxLocations().y);
					setLocation(tempRandom.x, tempRandom.y);
	}*/

	
	rotationalVelocity=.5;	//set rotational velocity start w/ 0.1 or -0.1 (could be random rotational velocities)
	if ((rand()%2)==1)
		rotationalVelocity *= -1;
	
	
	
}

//================================================================================
//Function: validStartLocation
//Description: generates the start location an asteroids but prevents it from being
//will not be in the middle destroying the ship immediatlly
//
//================================================================================
myVector Asteroid::validStartLocation()
{
	myVector myCoordinates;
	int first;
	int second;

	//randomize the x and y coordinates
	if((rand() %2) ==1)
	{
		first = getRandomInt(1, getMaxLocations().x);
		second = getRandomInt(1, getMaxLocations().y);
		while((first > getMaxLocations().x * 2/5 && first < getMaxLocations().x * 3/5)
			&&(second > getMaxLocations().y * 2/5 && second < getMaxLocations().y * 3/5))
			second = getRandomInt(1,getMaxLocations().y);
	}
	else
	{
		first = getRandomInt(1, getMaxLocations().y);
		second = getRandomInt(1, getMaxLocations().x);
		while((first > getMaxLocations().y * 2/5 && first < getMaxLocations().y * 3/5)
			&&(second > getMaxLocations().x * 2/5 && second < getMaxLocations().x * 3/5))
			second = getRandomInt(1,getMaxLocations().x);
	}

	myCoordinates.x = first;
	myCoordinates.y = second;

	return myCoordinates;
}

//================================================================================
//Function: draw
//Description: other - Draws an asteroid on the screen
//
//================================================================================
void Asteroid::draw(sf::RenderWindow& win) {
	// draw Asteroid
	sf::ConvexShape Asteroid;
	Asteroid.setPointCount(8);
	Asteroid.setPoint(0, sf::Vector2f(13, 0));
	Asteroid.setPoint(1, sf::Vector2f(36, 0));
	Asteroid.setPoint(2, sf::Vector2f(50, 10));
	Asteroid.setPoint(3, sf::Vector2f(53, 40));
	Asteroid.setPoint(4, sf::Vector2f(40, 50));
	Asteroid.setPoint(5, sf::Vector2f(15, 52));
	Asteroid.setPoint(6, sf::Vector2f(0, 37));
	Asteroid.setPoint(7, sf::Vector2f(3, 12));
	

	sf::Vector2f midpoint(25,25);
	Asteroid.setOrigin(midpoint);

	Asteroid.setFillColor(sf::Color(0, 0, 0, 0.5));
	Asteroid.setOutlineThickness(2);
	Asteroid.setOutlineColor(sf::Color(255, 255, 255));

	myVector location=getLocation();
	chgAngle(rotationalVelocity);
	Asteroid.setPosition(location.x, location.y);
	Asteroid.setRotation(getAngle());
	win.draw(Asteroid);

	//is asteroid near the edge of the screen
	if(location.x> (getMaxLocations().x - getRadius()))
	{
		Asteroid.setPosition(location.x - getMaxLocations().x, location.y);
		win.draw(Asteroid);
	}
	if (location.x < (getRadius()))
	{
		Asteroid.setPosition(location.x + getMaxLocations().x, location.y);
		win.draw(Asteroid);
	}
	if(location.y > (getMaxLocations().y - getRadius()))
	{
		Asteroid.setPosition(location.x, location.y -getMaxLocations().y);
		win.draw(Asteroid);
	}
	if(location.y < (getRadius()))
	{
		Asteroid.setPosition(location.x, location.y + getMaxLocations().y);
		win.draw(Asteroid);
	}
	
	
}