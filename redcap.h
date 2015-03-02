#ifndef REDCAP_H	 	 	 	 	 //if the header has not been defined
#define REDCAP_H 	 	 	 	 	 //define it

#include "pixie.h" 	 	 	 	 //include the creature header
#include <string> 

class redcap : public pixie 	  //declare class pixie, a child class of creature
{
public: 
	redcap(); 	 	 	 	 	 	 //constructor for pixie object	   
	void set_str(int points, creature *attacker); 
	
protected: 
  
	int anger; 


};

#endif								//end the definition

