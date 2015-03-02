
/*********************
*Program: tournament.cpp
*Author: Tracy Stinghen
*Date Created: 6/2/14
*Last Date Modified: 
*Description: 
*Input: 
*Output:  
*Resources: 
***************************/

 
#include <iostream>
#include <ctime> 				//included for the dice mechanism function
#include <climits>				//included for input checking
#include <vector> 
#include <algorithm>
//#include "creature.h" 
#include "pixie.h"				//header files for the 4 classes of creatures
#include "elf.h"
#include "troll.h"
//#include "btroll.h"
#include "ogre.h"
#include "lep.h"
#include "redcap.h"
#include "gnome.h"
 
 
 

fighter_ptr build_team(fighter_ptr head, int team_num, std::string player_name, int player_num);			//(interface function) creates new fighters and puts them in teams
																											//this file is here, not in an external file, because it requires 
																											//access to all of the classes in order for it to work

int strike(fighter_ptr p_1, fighter_ptr p_2); 																//simulates one fighter attacking another one time
fighter_ptr encounter (fighter_ptr bef_1, fighter_ptr champ_1, fighter_ptr bef_2, fighter_ptr champ_2); 	//simulates two fighters fighting until one is defeated
int dice_roll(int sides, int rolls); 																		//simulates dice rolls 
void play_tournament();
void sort_damage(std::vector<fighter_ptr> &list, fighter_ptr first, fighter_ptr second, fighter_ptr third); //determines the top three damage dealers of the tournament

int main ()
{

	char again; 
	srand(time(0)); 						//seeds the rand function for the dice rolls 	 	 	 	 	 	 	 
	
	std::cout<<"It's time for CREATURE BASH TOURNAMENT!\n\nWe all loved Creature Bash...\nNow it's faster, rougher and tumblin'er than ever!\n"; 
	std::cout<<"First, pick the number of fighters on each team\nThen you'll both individually give your names, and draft your teams\n\nAnd then the BASH BEGINS!\n\n";
	
	play_tournament();
	
	std::cout<<"\n\nDo you want to play again?\nYou can battle the same opponent, or someone else!\n\n Enter y to play again:\n "; 
	std::cin>>again; 
	
	again = tolower(again); 
	
	while (again == 'y')
	{
	play_tournament(); 
	std::cout<<"\n\nDo you want to play again?\nYou can battle the same opponent, or someone else!\n\n Enter y to play again, or anything else to exit:\n "; 
	std::cin>>again; 
	}

	std::cout<<"Thanks for playing!\n\nBye!\n"; 

	
	return 0; 

} 

void play_tournament()
{


	std::string name;						//the player's name

	int loser_order; 						//indicates the standing for the losers of the competition
	int num_fighters;						//indicates the number of fighters per team
	int num_fights = 0; 					//counts the number of fights that have been played in the tournament
	
	fighter *head_1;						//the current head of the list (and current fighter)
	fighter *next_1; 
	fighter *next_2; 						//the next fighter after the current one   
	fighter *head_2; 
	fighter *loser; 						//the loser of the most recent encounter
	fighter *winner;						//the winner of the tournament
	fighter *stop;  						//indicates where to stop iterating through the linked list
	fighter *f_place; 
	fighter *s_place; 
	fighter *t_place; 
	
	std::vector<fighter_ptr> loser_list; 	//vector holds the nodes of the losers after they are defeated
	std::vector<fighter_ptr> high_scores; 

	std::cout<<"Enter number of creatures per team: "; 		
 	 std::cin>> num_fighters; 
	
	while(!std::cin || num_fighters <= 1 || num_fighters >= 100) 	 		//checks input
	{ 			
   			std::cin.clear(); 
   			std::cin.ignore(INT_MAX, '\n'); 
   			std::cout<<"\nWe're looking for a reasonable number of creatures that could be on a team\nPlease enter a number greater than 1 and less than 100: "; 
		std::cin>>num_fighters; 
	}
 
	std::cout<<"Enter pleyer 1's name: "; 
	std::cin>>name; 
															//builds a team of creatures the player specifies
	head_1 = build_team(head_2, num_fighters, name, 1); 	//doesn't actually return the head, returns the node before the head. 
	
	std::cout<<"Enter player 2's name: "; 
	std::cin>>name; 
	
	head_2 = build_team(head_2, num_fighters, name, 2);
	
	

	getline(std::cin, name); 								//pauses the program until the player presses enter
	
	do 
	{
		std::cout<<"\nPress enter to start fight # "<<num_fights+1<<": ";	//indicates the number of the current fight
		getline(std::cin, name);  
		next_1 = get_next(head_1); 											//sets the next variables to the link for the head 
		next_2 = get_next(head_2); 
		
		loser = encounter(head_1, next_1, head_2, next_2); 					//the two heads encounter eachother and a loser is determined
		loser_list.push_back(loser);										//the loser is added to the loser list
		num_fights++;														//the number of fights advances
		 
		if (get_next(head_1) != NULL && get_next(head_2)  != NULL) 			//if there are is more than one fighter left on both teams, advance to the next pair
		{
			head_1 = get_next(head_1);  
			head_2 = get_next(head_2); 
		}
		
	}while (get_next(head_1) != head_1 && get_next(head_2) != head_2); 		//keep fighting until there is only one fighter left on at least one team
	
	

	if (get_next(head_1) == head_1 && get_next(head_2) != head_2) 			//if player 1 has only one fighter left, and player 2 has more than 1...
	{
		std::cout<<head_1->p_name<<" has only one fighter left!\n"; 		//... say so
		while (loser != head_1 && get_next(head_2) != head_2) 				//while player 1 doesn't lose, and player 2 still has more than 1 fighter...
		{
			std::cout<<"\nPress enter to start fight # "<<num_fights+1<<": ";
			getline(std::cin, name); 
			
			next_1 = get_next(head_1); 
			next_2 = get_next(head_2);  
			
			loser = encounter(head_1, next_1, head_2, next_2); 				//pit the two fighters against eachother
			loser_list.push_back(loser);
			num_fights++;	   
		}  
		
		if (loser->p_name == head_1->p_name) 								//if player 1 loses, then player 2 is the winner
		{
			winner = head_2; 
		
		}
	
	}
	
	
	
	if (get_next(head_2) == head_2 && get_next(head_1) != head_1) 			//same as above, but for the case where player 2 has only one fighter
	{
		
		std::cout<<head_2->p_name<<" has only one fighter left!\n";	
		
		while (loser != head_2 && get_next(head_1) != head_1) 
		{
			std::cout<<"\nPress enter to start fight # "<<num_fights+1<<": ";
			getline(std::cin, name); 
			
			next_1 = get_next(head_1); 
			next_2 = get_next(head_2);  
			
			loser = encounter(head_1, next_1, head_2, next_2); 
			loser_list.push_back(loser);
			num_fights++;	   
		}  
		
		if (loser->p_name == head_2->p_name) 
		{

			winner = head_1; 
		
		}
	
	}
	
	
	
	if (get_next(head_2) == head_2 && get_next(head_1) == head_1) 			//if both teams have only one fighter left...
	{
			std::cout<<"Both teams have only one fighter left!\n";			//...say so
			
			std::cout<<"\nPress enter to start fight # "<<num_fights+1<<": ";
			getline(std::cin, name); 
			
			next_1 = get_next(head_1); 										//pit the last two fighters against eachother
			next_2 = get_next(head_2); 
			
			loser = encounter(head_1, next_1, head_2, next_2); 
			loser_list.push_back(loser); 
			
		if (loser->p_name == head_2->p_name)  								//if player 2 loses, player 1 wins
		{ 
			winner = head_1; 
		
		}
		
		if (loser->p_name == head_1->p_name) 								//if player 1 loses, player 2 wins 
		{
			winner = head_2; 
		
		}
	
	
	}	      
	
	high_scores = loser_list; 
	
	if(winner == head_1 || winner == head_2) 								//if the winner has been identified
	{
		stop = winner; 														//indicates where the iteration should stop printing team names
		std::cout<<std::endl<<winner->p_name<<" is the Winner!\n"<<"The members of "<<winner->p_name<<" team left standing are:\n"; 
		
		do	  	  	  	  	  	  	  	  	 								//print the team members still in the list for the winning team	   	   	   	   	   	   	   
		{
		std::cout<<winner->p_name<<"'s "<<winner->fae->get_name()<<std::endl; 
		high_scores.push_back(winner); 
		winner = get_next(winner); 
		}while(winner != stop); 
	
	}
	
	
	
	/***************************************
	std::cout<<"\n\nIn order of elimination...\nThe List of Losers is:\n"; 	//shows the rankings of the defeated fighters
	loser_order = loser_list.size(); 										//the last ranking is the size of the vector
	for (int i = 0; i < loser_list.size(); i++) 							//print out the losers
	{
		std::cout<<"Loser #"<<loser_order<<": "<<loser_list[i]->p_name<<"'s "<<loser_list[i]->fae->get_name()<<" with "<<" wins"<<std::endl; 
		loser_order--;														//each time, increase the ranking by 1 
	
	
	}
	*******************************************/ 
	
	sort_damage(high_scores, f_place, s_place, t_place); 

}

/*****************************************
*Function: pick_team
*Description: prints a list of the player's options for fighters
*			and allows them to choose one for each slot on their team
*Parameters: int rank - which shows which spot on the team is being selected for
*Pre-Conditions: team has n members
*Post-Conditions: team has n members, and the n+1 member will be of a specific type
******************************************/ 

int pick_team(int rank) 
{
	int choice; 

	std::cout<<"1. Pixie\n2. Elf\n3. Leprechaun\n4. Redcap\n5. Troll\n6. Ogre\n7. Gnome\n"; 	//prints out the options
	std::cout<<"Pick the type of creature you want for spot #"<<rank<<": "<<std::endl; 			//asks user to pick the type of fighter they want
	std::cin>>choice; 
	
	while(!std::cin || choice >= 8) 															//checks input
		{ 			
   			std::cin.clear(); 
   			std::cin.ignore(INT_MAX, '\n'); 
   			std::cout<<"\nPlease pick a number that corresponds to a type of creature: "; 
			std::cin>>choice; 
		}

	return choice; 
	

}



/*****************************************
*Function: strike
*Description: one fighter attacking another one time 
*Parameters: fighter_ptr, fighter_ptr
*Pre-Conditions: two fighters exist 
*Post-Conditions: scores, created by dice roll simulations are added, and compared, resulting in a 
*				final number of "damage" which is returned
******************************************/ 

int strike(fighter_ptr attacker, fighter_ptr defender)
{

	int result = 0; 																				//this is the damage done 
		int att; 																					//the value of the attack
		int def; 																					//the value of the defence
		
		att = dice_roll(attacker->fae->get_att_sides(), attacker->fae->get_att_rolls()); 			//simulates dice roll for attack value
		def = dice_roll(defender->fae->get_def_sides(), defender->fae->get_def_rolls());			//simulates dice roll for defender value  
	
		result = att - (def + defender->fae->get_armour()); 	  	  	  	  	  	  				//damage done is the attack minuts, the defence, minus the armour 
		
		if (result < 0)																				//if there was more defence than attack
		{
			result = 0; 																			//don't return a negative, just make the result 0
		}
		std::cout<<std::endl<<defender->p_name<<"'s "<<defender->fae->get_name()<<" has "<<defender->fae->get_str()<<" strength."; 
		std::cout<<std::endl<<attacker->p_name<<"'s "<<attacker->fae->get_name()<<" attacks with a "<<att<<std::endl; //this is a narrative about what happened in the encounter
		std::cout<<defender->p_name<<"'s "<<defender->fae->get_name()<<" defends with a "<<def<<std::endl; 
		std::cout<<defender->p_name<<"'s "<<defender->fae->get_name()<<" has "<<defender->fae->get_armour()<<" armour. "<<std::endl;  
		std::cout<<defender->p_name<<"'s "<<defender->fae->get_name()<<" takes "<<result<<" damage!"<<std::endl; 
		;
		
		
		
		return result; 					

}


/*****************************************
*Function: dice_roll
*Description: simulates the roll of n number of p sided dice
*Parameters: int sides, int rolls
*Pre-Conditions: the number of dice, and number of sides are known
*Post-Conditions: the scores of those dice are returned
******************************************/ 

int dice_roll(int sides, int rolls)
{

	int score = 0; 										//sets score to 0
		int roll; 										//represents the current roll
		
		for (int i = 0; i <rolls; i++) 					//for the number of rolls specified
		{
		roll = (1+rand()%sides);						//the current roll is a random number between 1 and the max number of sides
		score = roll + score;  							//add the current roll to the score
		
		}
		
		
		
		return score; 									//return all of the rolls added together as the final score	   

}

/*****************************************
*Function: encounter
*Description: each team strikes at the other, alternating, until one fighter has 0 strength left
*Parameters: fighter_ptr, fighter_ptr, fighter_ptr, fighter_ptr
*Pre-Conditions: two fighters each on two different linked lists are submitted for BATTLE
*Post-Conditions: one fighter is removed from their linked list, and is returned 
******************************************/ 

fighter_ptr encounter (fighter_ptr bef_1, fighter_ptr champ_1, fighter_ptr bef_2, fighter_ptr champ_2) 
{
	int damage; 
	int new_str; 
	int first_play; 
	fighter_ptr loser; 
	fighter_ptr pre_loser; 
	//fighter_ptr winner; 
	
	first_play = (1+ rand()%2); 						//chooses which team strikes first, at random 
	
	if (first_play == 2)								// if player 2 plays first...
	{
		damage = strike(champ_2, champ_1); 				//player 2 attacks player 1, and does some damage 
		new_str = (champ_1->fae->get_str() - damage);	//calculates what player 1's new strength will be	 
														
		champ_2->fae->set_wins(damage); 				//adds damage done to the attacker's total damage inflicted 
		champ_1->fae->set_str(new_str, champ_2->fae); 	//player 1's strength is set to reflect the new damage done	
														//(magical abilities may be revealed in this step) 													
	}
	
	
	
	
	while (champ_1->fae->get_str() > 0 && champ_2->fae->get_str() > 0) 	//while both fighters are still standing 
	{
		damage = strike(champ_1, champ_2); 				//a strike happens, as above
		new_str = (champ_2->fae->get_str() - damage);
		champ_1->fae->set_wins(damage);
		champ_2->fae->set_str(new_str, champ_1->fae); 
		
		if(champ_2->fae->get_str() > 0 && champ_1->fae->get_str() > 0) 	//if the first attack didn't knock anybody out
		{
			damage = strike(champ_2, champ_1); 			//another strike happens
			new_str = (champ_1->fae->get_str() - damage);
			champ_2->fae->set_wins(damage);
			champ_1->fae->set_str(new_str, champ_2->fae); 
		
		}
	}
	
	if(champ_2->fae->get_str() <= 0) 					//if one fighter's strength is at 0, they lose
	{
		loser = champ_2;								//indicates the loser
		pre_loser =  bef_2;  							//indicates the fighter before the loser
	 
	}
	
	if(champ_1->fae->get_str() <= 0) 					
	{
		loser = champ_1;
		pre_loser = bef_1; 
	
	}
	
 
	std::cout<<std::endl<<loser->p_name<<"'s "<<loser->fae->get_name()<<" is knocked out of the competition.\n"; 
	expell_fighter(pre_loser, loser);   				//calls the function to expell the defeated fighter from their team
	
	return loser; 										//returns the loser, so that they can be added to the loser's list

}

/*****************************************
*Function: sort_damage
*Description: figures out which three creatures did the highest amount of damage in the tournament
*Parameters: vector<fighter_ptr>, fighter_ptr, fighter_ptr, fighter_ptr
*Pre-Conditions: there is a list with all of the fighters on both teams
*Post-Conditions: the three fighters with the highest scores are printed
******************************************/ 


void sort_damage(std::vector<fighter_ptr> &list, fighter_ptr first, fighter_ptr second, fighter_ptr third)
{
	
	first = list.at(1); 												//initializes the pointers to a fighter (doesn't matter which)
	second = list.at(1);
	third = list.at(1); 
	
	for (int i = 0; i < list.size(); i++) 								//for each item in the vector
	{
		if (list.at(i)->fae->get_wins() >= first->fae->get_wins())		//if the current item is bigger than the current first place scorer
		{
			third = second; 											//shift each score down the ranks 
			second = first; 
			first = list.at(i); 										//sets the current item to first place	    
		
		}
		
		if (list.at(i)->fae->get_wins() >= second->fae->get_wins() && list.at(i)->fae->get_wins() < first->fae->get_wins()) 
		{																//if the current item is bigger than second place, smaller than first place
			third = second;  											//shift scores down
			second = list.at(i); 										//sets the current item to second place	      
		
		}
		
		if (list.at(i)->fae->get_wins() >= third->fae->get_wins() && list.at(i)->fae->get_wins() < second->fae->get_wins())
		{																//if the current item is bigger than third place, smaller than second place
			third = list.at(i); 										//sets the current item to third place
		
		}
	
	}
																		//prints out the top three scorer's information 
		std::cout<<"\nThe VIP of the tournament is the creature who did the most damage\n\n"; 	
		std::cout<<"In First Place: "<<first->p_name<<"'s "<<first->fae->get_name()<<" with "<<first->fae->get_wins()<<" total damage"<<std::endl; 
		std::cout<<"In Second Place: "<<second->p_name<<"'s "<<second->fae->get_name()<<" with "<<second->fae->get_wins()<<" total damage"<<std::endl; 
		std::cout<<"In Tirst Place: "<<third->p_name<<"'s "<<third->fae->get_name()<<" with "<<third->fae->get_wins()<<" total damage"<<std::endl; 


}

/**************************************
*Implementation Continued from Creature.cpp
***************************************/ 


/*****************************************
*Function: build_team
*Description: builds a linked of a specified size, of fighters with specific classes of creatures
*Parameters: fighter_ptr, int, string, int
*Pre-Conditions: there is no linked list
*Post-Conditions: there is a linked list of n length, with all of it's informational fields 
*				completed, and which is linked to itself to form a circuit
******************************************/ 

fighter_ptr build_team(fighter_ptr head, int team_num, std::string player_name, int player_num)
{
	int type; 											//indicates the type of fae that the player chooses for each fighter slot	 	 	 	 
	
	fighter *current;									//indicates the current fighter being created

	
	current = new fighter; 								//creates a new fighter
	current->p_name = player_name; 						//sets the stats for the new fighter
	current->p_number = player_num; 
	//current->wins = 0; 
	current->link = NULL; 	 
	head = current;  									//sets the current node to the head of the list 	
	
	type = pick_team(1); 								//allows the player to pick the type of fae they want
	
	switch(type)										//switch equates the chosen type to the class, and creates a new creature
	{
		case 1: 
		current->fae = new pixie;  
		break; 
		case 2: 
		current->fae = new elf; 
		break; 
		case 3: 
		current->fae = new lep; 
		break; 
		case 4: 
		current->fae = new redcap; 
		break; 
		case 5: 
		current->fae = new troll; 
		break; 
		case 6: 
		current->fae = new ogre; 
		break; 
		case 7: 
		current->fae = new gnome; 
		break; 
		default: 
		std::cout<<"Error"; 
	
	} 
	
	
	
	for (int i = 2; i <= team_num; i++) 			//for the rest of the fighters that need to be created to make up the team
	{
		  	  	  	  
		current->link = new fighter;				//create a new fighter after the previous fighter
		current = current->link; 					//makes the fighter in question, the fighter that just got created
		 
		current->p_name = player_name; 				//sets fighter stats
		current->p_number = player_num; 
		//current->wins = 0; 
		current->link = NULL; 
		
		
		type = pick_team(i); 						//allows the player to pick the creatures on their team
		
		switch(type)								//equates the choice to the creature and creates new creatures as selected
		{
			case 1: 
			current->fae = new pixie; 
			break; 
			case 2: 
			current->fae = new elf; 
			break; 
			case 3: 
			current->fae = new lep; 
			break; 
			case 4: 
			current->fae = new redcap; 
			break; 
			case 5: 
			current->fae = new troll; 
			break; 
			case 6: 
			current->fae = new ogre; 
			break; 
			case 7: 
			current->fae = new gnome; 
			break; 
			default: 
			std::cout<<"Error"; 
		
		}
		
		
		
	 
		 
		
	}
	
	current->link = head;   					//sets the last link in the chain to link up with the head of the chain, making a circuit. 	   
	
	return current; 							//returns the last fighter created


}

