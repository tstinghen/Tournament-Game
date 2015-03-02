
/*********************
*Program: troll.cpp 
*Author: Tracy Stinghen
*Date Created: 5/7/14
*Last Date Modified: 5/11/14
*Description: implementation of the class elf, child of creature
***************************/


#include <iostream>
#include <string>
#include "troll.h"							//include the header


troll::troll() : creature()					//constructor of troll, child of creature
{
	this->strength = 18; 					//sets the stats to troll standard
	this->armour = 7;
	//this->armour = 0; 					//reduced defence for testing 
	this->name = "troll";
	this->type = "Mountain Troll"; 
	this->attack_rolls = 3; 
	this->attack_sides = 6; 
	this->defence_rolls = 1; 
	this->defence_sides = 6; 
	this->wins = 0;   
}

void troll::set_str(int points, creature *attacker)	 	 	 //set the strength of the creature
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


