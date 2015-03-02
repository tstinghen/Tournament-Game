#ifndef troll_H							//if the header has not been defined
#define troll_H 						//define it

#include "creature.h" 					//include the creature header
#include <string> 

class troll : public creature 			//declare class troll, a child class of creature
{
public: 
	troll(); 	  						//constructor for troll object
	void set_str(int points, creature *attacker);
protected: 
  



};

#endif									//end the definition

