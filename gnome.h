#ifndef GNOME_H	    				//if the header has not been defined
#define GNOME_H 					//define it

#include "pixie.h" 	 	 	 	 //include the creature header
#include <string> 

class gnome : public pixie 	     //declare class gnome, a child class of pixie
{
public: 
	gnome(); 						//constructor for pixie object	  
	void set_str(int points, creature *attacker); 
	
protected: 
  



};

#endif								//end the definition

