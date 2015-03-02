
/*********************
*Program: gnome.cpp 
*Author: Tracy Stinghen
*Date Created: 5/7/14
*Last Date Modified: 5/11/14
*Description: implementation of the class gnome, child of pixie
***************************/


#include <iostream>
#include <string>
#include "gnome.h"	    				//include the header


gnome::gnome() : pixie()	 	 	 //constructor of pixie, child of creature
{
	this->strength = 8; 				//sets the stats to pixie standard
	//this->armour = 0;   				//reduced defence for testing
	this->armour = 3;	  	  	  	  
	this->name = "gnome";
	this->type = "Gnome";   
	this->attack_rolls = 2; 
	this->attack_sides = 6; 
	this->defence_rolls = 1; 
	this->defence_sides = 6;  
	this->wins = 0;  
}

void gnome::set_str(int points, creature *attacker)
{

	int spirit;
	
	this->attack_rolls = 2; 
	
	spirit = (rand()%8);
	
	if (spirit == 0)
	{
		if(this->strength > points)
		{
			std::cout<<"The "<<this->name<<" harnasses the swiftness of the wind\n"<<this->name<<" evades the attack and takes no damage.\n"; 
		}
	}
	
	if(spirit == 1) 
	{
		if(this->armour < 6) 
		{
			this->armour = this->armour + 1; 
			std::cout<<"The "<<this->name<<" draws on the strength of the earth\n"<<this->name<<" gains +1 to his armour.\n"; 	   
			this->strength = points; 	
		}
	}
	
	if(spirit == 2)
	{
		this->attack_rolls = 3; 
		std::cout<<"The "<<this->name<<" burns with the heat of fire.\n"<<"The "<<this->name<<" rolls 3 dice to attack, until he is attacked again.\n"; 	
		this->strength = points; 
	} 
	
	if(spirit == 3) 
	{
		this->strength = this->strength + 1; 
		std::cout<<"The "<<this->name<<" is soothed by the cooling balm of water.\n"<<"The "<<this->name<<" heals +1 strength.\n"; 
		this->strength = points; 
	}
	
	if(spirit > 3) 
	{
		std::cout<<"The "<<this->name<<" tries to call on the forces of nature to help him.\n"; 
		std::cout<<"But none answer...\n"; 
		this->strength = points; 
	}
	
	

}


/*****************************************
*Function: 
*Description: 
*Parameters:
*Pre-Conditions: 
*Post-Conditions:
******************************************/ 


