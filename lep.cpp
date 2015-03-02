
/*********************
*Program: pixie.cpp 
*Author: Tracy Stinghen
*Date Created: 5/7/14
*Last Date Modified: 5/11/14
*Description: implementation of the class elf, child of creature
***************************/


#include <iostream>
#include <string>
#include "lep.h"	  	  	  	  	  //include the header


lep::lep() : pixie()	 	 	 //constructor of pixie, child of creature
{
	this->strength = 8; 				//sets the stats to pixie standard
	//this->armour = 0;   				//reduced defence for testing
	this->armour = 3;	  	  	  	  
	this->name = "leprechaun";
	this->type = "Leprechaun";   
	this->attack_rolls = 2; 
	this->attack_sides = 6; 
	this->defence_rolls = 1; 
	this->defence_sides = 6;   
	this->wins = 0; 
}

void lep::set_str(int points, creature *attacker)
{

	int escape; 	
	
	if (points > 0)							//if the new strength is greater than 0
	{
		if (points < strength)
		{
			escape = (rand()% 5); 
			std::cout<<"The "<<name <<" tries to disappear and avoid taking the damage.\n"; 
			
			if (escape >= 3) 
			{
			std::cout<<"The "<<name<<" disappears!\n"; 	   
			}
			
			if (escape < 3)
			{
				strength = points; 
				std::cout<<"The "<<name <<" fails to disappear, and takes the damage.\n"; 
			
			}
		}
		
	}
	
	if (points <=0)							//if the new strength is equal to or less than zero
	{
		strength = 0; 						// set the strength to 0
	}  
	
	else 
	{
		return; 
	}

}


/*****************************************
*Function: 
*Description: 
*Parameters:
*Pre-Conditions: 
*Post-Conditions:
******************************************/ 


