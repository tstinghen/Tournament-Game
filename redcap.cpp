
/*********************
*Program: redcap.cpp 
*Author: Tracy Stinghen
*Date Created: 5/22/14
*Last Date Modified: 5/11/14
*Description: implementation of the class redcap, child of pixie
***************************/


#include <iostream>
#include <string>
#include "redcap.h"	 	 	 	 	 	 //include the header


redcap::redcap() : pixie()	   	   	   //constructor of pixie, child of creature
{
	this->strength = 8; 				//sets the stats to pixie standard
	//this->armour = 0;   				//reduced defence for testing
	this->armour = 3;	  	  	  	  
	this->name = "redcap";
	this->type = "Redcap";   
	this->attack_rolls = 2; 
	this->attack_sides = 5; 
	this->defence_rolls = 1; 
	this->defence_sides = 6;
	this->anger = 0;  
	this->wins = 0;   
}

void redcap::set_str(int points, creature *attacker)
{

	 	 
	
	if (points > 0)							//if the new strength is greater than 0
	{
		anger++; 
		std::cout<<"The "<<this->name<<"'s anger is building.\n";	 
		
		if (points < strength)
		{
			this->strength = points; 	 
		}
		
		if (anger == 5) 
		{
			attacker->set_str(0, this);  
			std::cout<<std::endl<<"The "<<this->name<<" flew into a blind fury and knocked out "<<attacker->get_name()<<std::endl;
			anger = 0; 
		
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


