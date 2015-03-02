
/*********************
*Program: creature.cpp
*Author: Tracy Stinghen
*Date Created: 5/7/14
*Last Date Modified: 5/11/14
*Description: Immplementation of class creature
***************************/

 



#include <iostream>
#include <string> 
#include <cstdlib>
#include "creature.h"

	creature::creature()				//constructor for creature
	{
		//deliberately empty
	}
	
	int creature::get_att_sides()		//get the number of sides on the attack dice
	{
		return this->attack_sides; 
	
	}
	
	int creature::get_att_rolls()		//get the number of rolls for attack
	{
		return this->attack_rolls; 
	
	}
	
	
	int creature::get_def_sides()		//get the number of sides on the defence dice
	{
		return this->defence_sides; 
	
	}
	
	int creature::get_def_rolls()		//get the number of rolls for defence
	{
		return this->defence_rolls; 
	
	}
	
	
	int creature::get_armour()			//get the number for armour 
	{
		return this->armour; 
	
	}
	
	int creature::get_str()				//get the number for strength
	{
		return this-> strength; 
	
	}
	
	
	std::string creature::get_name()	//get the name of the creature
	{
		return this->name; 
	
	}
	
	std::string creature::get_type()
	{
		return this->type; 
	}
	
	int creature:: get_wins()
	{
		return wins; 
	}
	
	
	void creature::set_name(std::string name)	//set the name of the creature
	{
		this->name = name; 
	
	}
	
	void creature::set_wins(int damage_done) 
	{
		this->wins = (this->wins + damage_done); 
	
	}
	



	
fighter_ptr get_next(fighter_ptr first)
{
	return first->link; 


} 


void expell_fighter(fighter_ptr before, fighter_ptr kick_me_out)
{
	before->link = kick_me_out->link; 

}

fighter_ptr create_fighter(fighter_ptr current, std::string player_name, int player_num)
{
	//current = new fighter; 
	current->p_name = player_name; 
	current->p_number = player_num; 
	current->link = NULL;  	 	    
}

