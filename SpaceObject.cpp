/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	SpaceObject Class Implementation File
//
//Dev Env:	Visual Studio
//
//Description: Implementation of the functions for the SpaceObject class
//		
=======================================================================================================================*/

#include "SpaceObject.h"


//================================================================================
//Function: Default constructor
//Description: instantiates an instance of a SpaceObject
//================================================================================
SpaceObject::SpaceObject()
{
	//myVector thisGame;
	//setGame.x = setGa,e
	//maxLocations.x=THE_EDGE_OF_THE_UNIVERSE;
	//maxLocations.y=THE_EDGE_OF_THE_UNIVERSE;
	
	Config setGame;
	setGame.loadData();
	setMaxLocations(setGame.width, setGame.height);
	location.x=0;
	location.y=0;
	velocity.x=0;
	velocity.y=0;
	angleDeg=0;
	radius=0;
}

//================================================================================
//Function: setLocation
//Description: mutator - If the x and y coordinates are off the screen it modifys 
//						them to put the SpaceObject back on the screen.
//
//Argument List:	(I/O) x - the x coordinate under consideration.
//					(I/O) y - the y coordinate under consideration.
//================================================================================
void SpaceObject::setLocation(float x, float y)
{
	while(x>maxLocations.x)
		x-=maxLocations.x;

	while(y>maxLocations.y)
		y-=maxLocations.y;

	while(x<0)
		x +=maxLocations.x;

	while(y<0)
		y +=maxLocations.y;

	location.x=x;
	location.y=y;
}

//================================================================================
//Function: setVelocity
//Description: mutator - Sets the velocity of the SpaceObject
//
//Argument List: 	(I) velocityx - the x axis velocity of the SpaceObject.
//					(I) velocityy - the x axis velocity of the SpaceObject.
//================================================================================
void SpaceObject::setVelocity(float velocityX, float velocityY)
{
	velocity.x=velocityX;
	velocity.y=velocityY;
}

//================================================================================
//Function: setAngle
//Description: mutator- sets angle of the SpaceObject.
//
//Argument List: (I) - angDeg - The angle of the SpaceObject.
//================================================================================
void SpaceObject::setAngle(float angDeg)
{
	angleDeg=angDeg;
}

void SpaceObject::setRadius(float r) {
	radius = r;
}

//================================================================================
//Function: getRadius
//Description: accessor - Determines the size of the SpaceObject
//
//Return Value: The size of the SpaceObject
//================================================================================
float SpaceObject::getRadius()
{
	return radius;
}

//================================================================================
//Function: getLocation
//Description: accessor - Determines the current location of the SpaceObject.
//
//Return Value: The current location of the SpaceObject
//================================================================================
myVector SpaceObject::getLocation()
{
	return location;
}

//================================================================================
//Function: getVelocity
//Description: accessor - Gets the current velocity of the SpaceObject
//
//Return Value: The current velocity of the SpaceObject 
//================================================================================
myVector SpaceObject::getVelocity()
{
	return velocity;
}

//================================================================================
//Function: getAngle
//Description: accessor - Gets the current angle of the SpaceObject
//
//Return Value: The current angle of the SpaceObject
//================================================================================
float SpaceObject::getAngle()
{
	return angleDeg;
}

//================================================================================
//Function: myVector getMaxLocations();
//Description: accessor - Gets the maximum location of the object
//
//Return Value: The maximum location of the SpaceObject
//================================================================================
myVector SpaceObject::getMaxLocations()
{
	return maxLocations;
}

//================================================================================
//Function: void setMaxLocations(myVector someLoc)
//Description: mutator - Sets the maximum location of the object
//
//================================================================================
void SpaceObject::setMaxLocations(int someLoc1, int someLoc2)
{
	maxLocations.x = someLoc1;
	maxLocations.y = someLoc2;	
}
	
//================================================================================
//Function: chgAngle
//Description: Changes the angle by the given amount
//================================================================================
void SpaceObject::chgAngle(float deltaA)
{
	angleDeg += deltaA;
	while(angleDeg<0)
		angleDeg+=360;
	while (angleDeg>=360)
		angleDeg-=360;
}

//================================================================================
//Function: chgVeloity
//Description: Change velocity by given amount
//================================================================================
void SpaceObject::thrustFactor(float deltaVx, float deltaVy)
{
	velocity.x+=deltaVx;
	velocity.y+=deltaVy;
}

//================================================================================
//Function: chgRadius
//Description: Changes radius by given amount
//================================================================================
void SpaceObject::chgRadius(float deltaR)
{
	radius+=deltaR;
}

//================================================================================
//Function: updateLocation
//Description: other -	Updates the location of the SpaceObject after velocity has
//						been applied and checks to see if the SpaceObject is still
//						on the screen						
//
//================================================================================
void SpaceObject::updateLocation()
{
	setLocation(location.x+velocity.x, location.y+velocity.y);
}

//================================================================================
//Function: getRandomFloat
//Description: other - generates a random float
//
//================================================================================
float SpaceObject::getRandomFloat()
{

	float randomFloat=0.01*(rand()%10+4);
	if ((rand()%2)==1)randomFloat *= -1;
	return randomFloat;
}

//================================================================================
//Function: getRandomInt
//Description: other - generates a random Integer
//
//================================================================================
int SpaceObject::getRandomInt(int min, int max)
{	
	

	static bool firstTime = true;
	int randNum;

	if(min > max)
	{
		int temp = min;
		max = min;
		min = temp;	
	}

	int range  = max-min+1;

	//start random generator with time
	if(firstTime)
	{
		srand(static_cast<unsigned int>(time(NULL)));
		firstTime = false;
	}

	//get random number between given low and high
	randNum = min + (rand() % range);

	return randNum;


}

//================================================================================
//Function: objectsIntersect
//Description: Checks to see if two objects are intersecting. If the distance
//			   between them is less than their combined radii, then they are and
//			   true is returned else false is returned.
//
//================================================================================
bool objectsIntersect(SpaceObject object1, SpaceObject object2)
{
	if (sqrt(pow((object1.getLocation().x - object2.getLocation().x), 2)
		+ pow((object1.getLocation().y - object2.getLocation().y), 2)) <=
		(object1.getRadius() + object2.getRadius()))
	{

		return true;
	}
	return false;
}
