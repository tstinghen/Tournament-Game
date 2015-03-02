#ifndef PIXIE_H						//if the header has not been defined
#define PIXIE_H 					//define it

#include "creature.h" 				//include the creature header
#include <string> 

class pixie : public creature 		//declare class pixie, a child class of creature
{
public: 
	pixie(); 						//constructor for pixie object	  
	void set_str(int points, creature *attacker); 
	
protected: 
  



};

#endif								//end the definition

