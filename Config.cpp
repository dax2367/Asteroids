/*=============================================================================================================
//Author:	Holly Eaton
//
//Program:	Config Class Implementation File
//
//Dev Env:	Visual Studio
//
//Description: Implementation of the Config class
//		
=======================================================================================================================*/


#include "Config.h"
#include "Constants.h"


Config::Config()
{
	configChar = NULL;
	width = NULL;
	height = NULL;
	numAst = NULL;
	configTurn = NULL;
	configThrust = NULL;
}

void Config::loadData()
{
	ifstream inputData;
	
	//Open the data stream
	inputData.open("SFMLsetup.txt");
	if(!inputData)
		std::cout<< "Error file read in!";
		
	//read the data
	while (!inputData.eof())
	{
		inputData >> configChar;

		if(configChar == 'w')
		{
			inputData >> width;
			inputData >> height;		
		}

		if(configChar == 'a')
			inputData >> numAst;

		if(configChar == 's')
		{
			inputData >> configTurn;
			inputData >> configThrust;
		}
	}

		//close the file
		inputData.close();

		//validate what we have in width, height, numAst, configTurn and configThrust
		if (width < 300 || width > 2000)
			width = THE_EDGE_OF_THE_UNIVERSE;

		if(height < 200 || height > 1000)
			height = THE_EDGE_OF_THE_UNIVERSE;

		if(numAst < 5 || numAst > 20)
			numAst = STARTING_NO_BIG_ASS_ROCKS;

		if (configTurn < 1 || configTurn > 5)
			configTurn = 1;

		if(configThrust < 0.02 || configThrust > 0.5)
			configThrust = THRUST;
}