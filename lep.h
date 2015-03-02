#ifndef LEP_H	  	  	  	  	  //if the header has not been defined
#define LEP_H 	  	  	  	  	  //define it

#include "pixie.h" 	 	 	 	 //include the creature header
#include <string> 

class lep : public pixie 	   //declare class lep, a child class of pixie
{
public: 
	lep(); 	  	  	  	  	  	  //constructor for pixie object	
	void set_str(int points, creature *attacker); 
	
protected: 
  



};

#endif								//end the definition

