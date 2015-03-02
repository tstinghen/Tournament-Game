#ifndef ogre_H					//if the header has not been defined
#define ogre_H 					//define it

#include "creature.h" 			//include the creature header
#include <string>

class ogre : public creature 	//declare class elf, a child class of creature
{
public: 
	ogre(); 					//constructor for ogre object 
	void set_str(int points, creature *attacker); 
protected: 
  



};

#endif							//end the definition

