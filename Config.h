/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	Configuration Class Header File
//
//Dev Env:	Visual Studio
//
//Description: Definition of the configuration class and function prototypes.
//		
=======================================================================================================================*/

#ifndef CONFIGURATION_H  
#define CONFIGURATION_H  

#include <iostream>
#include <fstream>
#include <string>
#include "constants.h"

using namespace std;

//**************Put the stuff for configuration here******************//
class Config {
public:
	Config();
	void loadData();

	char configChar;
	
	int	width;
	int	height;
	int	numAst;
	float configTurn;
	float configThrust;
	
	
};

#endif