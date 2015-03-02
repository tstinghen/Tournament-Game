
/*********************
*Program: elf.cpp 
*Author: Tracy Stinghen
*Date Created: 5/7/14
*Last Date Modified: 5/11/14
*Description: implementation of the class elf, child of creature
***************************/


#include <iostream>
#include <string>
#include "elf.h"						//include the header


elf::elf() : creature()					//constructor of elf, child of creature
{
	this->strength = 12; 				//sets the stats to elf standard
	this->armour = 0;
	this->name = "elf";
	this->type = "Elf"; 
	this->attack_rolls = 2; 
	this->attack_sides = 6; 
	this->defence_rolls = 2; 
	this->defence_sides = 6;  
	this->wins = 0;  
}

void elf::set_str(int points, creature *attacker)
{
	int heal;
	
	if (strength == points) 
	{
		heal = (rand() % 3); 				//produce either a 0 or a 1 
		
		if (heal > 0)
		{
			std::cout<<std::endl<<"The "<<name <<" magically heals himself "<<heal<<" strength."; 
			strength = strength + heal; 
		}
	
	}
	 
	
	if (points > 0)							//if the new strength is greater than 0
	{
	  
		strength = points; 					//set the strength to the number
	}
	
	if (points <=0)							//if the new strength is equal to or less than zero
	{
		strength = 0; 						// set the strength to 0
	}  

}




