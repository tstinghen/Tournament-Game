
/*********************
*Program: pixie.cpp 
*Author: Tracy Stinghen
*Date Created: 5/7/14
*Last Date Modified: 5/11/14
*Description: implementation of the class elf, child of creature
***************************/


#include <iostream>
#include <string>
#include "pixie.h"						//include the header


pixie::pixie() : creature()				//constructor of pixie, child of creature
{
	this->strength = 8; 				//sets the stats to pixie standard
	//this->armour = 0;   				//reduced defence for testing
	this->armour = 3;	  	  	  	  
	this->name = "pixie";
	this->type = "Pixie";   
	this->attack_rolls = 2; 
	this->attack_sides = 6; 
	this->defence_rolls = 1; 
	this->defence_sides = 6;   
	this->wins = 0; 
}

void pixie::set_str(int points, creature *attacker)
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


