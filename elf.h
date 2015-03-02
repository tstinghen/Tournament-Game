#ifndef elf_H					//if the header has not been defined
#define elf_H 					//define it

#include "creature.h" 			//include the creature header
#include <string>

class elf : public creature 	//declare class elf, a child class of creature
{
public: 
	elf();						//constructor for elf object 
	void set_str(int points, creature *attacker); 	 	 //overridden function for elf strength	   

	 
	
protected: 
  



};

#endif							//end the definition

