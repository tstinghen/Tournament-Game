#ifndef CREATURE_H 							//if the header is not defined 
#define CREATURE_H 							//define it



#include <string> 

class creature								//definition of class creature
{
public: 


	creature(); 							//constructor
	
	int get_att_sides(); 					//getters
	int get_def_sides();
	int get_att_rolls(); 
	int get_def_rolls();  
	int get_armour(); 
	int get_str();
	int get_wins(); 
	std::string get_name(); 
	std::string get_type();
	
 
	void set_wins(int damage_done); 
	void set_name(std::string name); 		//setters
	virtual void set_str(int points, creature *attacker) = 0;
	  


protected: 
	std::string name;
	std::string type;  	 	 	 	 	 	 //protected variables that are accessible to child classes
	int attack_rolls; 
	int attack_sides; 
	int defence_rolls;
	int defence_sides;  
	int armour; 
	int strength;
	int wins;  
	


};



struct fighter 
{
	creature *fae; 
	std::string p_name; 
	int p_number; 
	fighter *link; 

};

typedef fighter* fighter_ptr;

fighter_ptr get_next(fighter_ptr first); 

void expell_fighter(fighter_ptr before, fighter_ptr kick_me_out); 

fighter_ptr create_fighter(fighter_ptr new_guy, std::string name, int number); 

#endif

