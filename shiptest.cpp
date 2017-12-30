/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	Ship Class Test File
//
//Dev Env:	Visual Studio
//
//Description: To test the construction of the ship class
//		
=======================================================================================================================*/

#include<iostream>
#include "ship.h"
#include "myvector.h"
#include <iomanip>



//prototypes
void clearConsoleWindow();
void displayShipInfo(Ship testShip);
void turnShipLeft(Ship testShip);
void turnShipRight(Ship testShip);
void thrustShip(Ship testShip);
void updateLocation();
void testTheDamnShip(Ship testShip);

void main() {
	Ship deathStar;

	testTheDamnShip(deathStar);

	
	//keep console window open
	std::cout <<"\n\nPlease press ENTER to continue";
	std::cin.ignore(255,'\n');
	std::cin.get();
}


//clears the console window
void clearConsoleWindow() {
	for(int x=1; x<=50; x++) 
		std::cout << "\n";
}

void displayShipInfo(Ship testShip) 
{
	clearConsoleWindow();

	std::cout << "ship x coordinate is "<<std::showpoint<<std::fixed<<std::setprecision(3)<< testShip.getLocation().x << "\n";
	std::cout << "ship y coordinate is "<<std::showpoint<<std::fixed<<std::setprecision(3) << testShip.getLocation().y << "\n";
	std::cout<<"ship heading is "<<std::showpoint<<std::fixed<<std::setprecision(3)<<testShip.getAngle()<<"\n";
	std::cout<<"ship x velocity is "<<std::showpoint<<std::fixed<<std::setprecision(3)<<testShip.getVelocity().x<<"\n";
	std::cout<<"ship y velocity is "<<std::showpoint<<std::fixed<<std::setprecision(3)<<testShip.getVelocity().y<<"\n";
}

void testTheDamnShip(Ship testShip)

{
	for(int x=1; x<=360; x++)
	{
		testShip.rotateRight();
		testShip.applyThrust();
		//testShip.rotateLeft();
		//testShip.applyThrust();
		displayShipInfo(testShip);
	}


}
