
/*********************
*Program: ogre.cpp 
*Author: Tracy Stinghen
*Date Created: 5/7/14
*Last Date Modified: 5/11/14
*Description: implementation of the class elf, child of creature
***************************/


#include <iostream>
#include <string>
#include "ogre.h"							//include the header


ogre::ogre() : creature()					//constructor of ogre, child of creature
{
	this->strength = 12; 					//sets the stats to ogre standard
	this->armour = 3;
	this->name = "ogre";
	this->type = "Ogre"; 
	this->attack_rolls = 2; 
	this->attack_sides = 10; 
	//this->defence_rolls = 1; 				//reduced defence for testing
	this->defence_rolls = 3; 	  	  	  
	this->defence_sides = 6;  
	this->wins = 0;  
}

void ogre::set_str(int points, creature *attacker)			//set the strength of the creature
{
	if (points > 0)							//if the new strength is greater than 0
	{
		strength = points; 					//set the strength to the number
	}
	
	if (points <=0)							//if the new strength is equal to or less than zero
	{
		strength = 0; 						// set the strength to 0
	}  

}



/*****************************************
*Function: 
*Description: 
*Parameters:
*Pre-Conditions: 
*Post-Conditions:
******************************************/ 


