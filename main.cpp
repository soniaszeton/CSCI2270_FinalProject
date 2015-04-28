/* 
 * File:   main.cpp
 * Author: Sonia Szeton, Connor Fitzgerald
 *
 * Created on April 23, 2015, 4:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct HG_Situation {
    string scenario;
    int score1;
    int score2;
    int score3;
    int score4;
};


class Character
{
    public:
        bool HP_Complete;
        bool HG_Complete;
        bool LOTR_Complete;
        bool poke_Complete;
        string player_name;
        int district;
        string pokemon;
        string rival_pokemon;
        string weapon;
        int strength;
        int age;
        int survivalOdd;
        Character() {
            HP_Complete = false;
            HG_Complete = false;
            LOTR_Complete = false;
            poke_Complete = false;
            player_name = "None";
            district = 0;
            age = 0;
            survivalOdd = 0;
            pokemon = "None";
            rival_pokemon = "None";
            weapon = "None";
            strength = 50;
        }
        int calcSurvival(int district, int age);
        int setSurvival(int answer, HG_Situation scenario);
        void setPokemon(Character user, string user_poke);
        void evolvePokemon(Character user);
        void setWeapon(Character user, string weapon_choice);
        void setStrength(Character user, int newStrength);
        void setHP_Comp(Character user);
        void setHG_Comp(Character user);
        void setLOTR_Comp(Character user);
        void setpoke_Comp(Character user);
        void printInfo(Character user);
        
};

int Character::calcSurvival(int district, int age) {
    int initial_survivalOdd = 0;
    switch(district) {
        case 1:
        {
            initial_survivalOdd += 5;
            break;
        }
        case 2:
        {
            initial_survivalOdd += 5;
            break;
        }
        case 3:
        {
            initial_survivalOdd += 3;
            break;
        }
        case 4:
        {
            initial_survivalOdd += 5;
            break;
        }
        case 5:
        {
            initial_survivalOdd += 3;
            break;
        }
        case 6:
        {
            initial_survivalOdd += 2;
            break;
        }
        case 7:
        {
            initial_survivalOdd += 4;
            break;
        }
        case 8:
        {
            initial_survivalOdd += 1;
            break;
        }
        case 9:
        {
            initial_survivalOdd += 1;
            break;
        }
        case 10:
        {
            initial_survivalOdd += 2;
            break;
        }
        case 11:
        {
            initial_survivalOdd += 3;
            break;
        }
        case 12:
        {
            initial_survivalOdd += 2;
            break;
        }
    }
    switch(age) {
        case 12:
        {
            initial_survivalOdd += 1;
            break;
        }
        case 13:
        {
            initial_survivalOdd += 1;
            break;
        }
        case 14:
        {
            initial_survivalOdd += 2;
            break;
        }
        case 15: 
        {
            initial_survivalOdd += 3;
            break;
        }
        case 16:
        {
            initial_survivalOdd += 3;
            break;
        }
        case 17:
        {
            initial_survivalOdd += 4;
            break;
        }
        case 18:
        {
            initial_survivalOdd += 5;
            break;
        }
    }
    return initial_survivalOdd;
}

int Character::setSurvival(int answer, HG_Situation scenario) {
    int survivalScore = 0;
    switch(answer) {
        case 1:
        {
            survivalScore += scenario.score1;
            break;
        }
        case 2:
        {
            survivalScore += scenario.score2;
            break;
        }
        case 3:
        {
            survivalScore += scenario.score3;
            break;
        }
        case 4:
        {
            survivalScore += scenario.score4;
            break;
        }
    }
    return survivalScore;
}

void Character::setStrength(Character user, int newStrength){
    user.strength += newStrength;
    cout<<"Your strength has increasedby "<<newStrength<<" to "<<user.strength<<"!"<<endl;
}

void Character::setPokemon(Character user, string user_poke) {
	user.pokemon = user_poke;
}

void Character::evolvePokemon(Character user){
	
	cout<<endl;
	cout<<"What? Your "+user.pokemon+" is evolving!"<<endl;
	
	if (user.pokemon == "Bulbasaur"){
		user.setPokemon(user, "Ivysaur");
		cout<<"Your Bulbasaur has evolved into Ivysaur!"<<endl;
	}
	else if (user.pokemon == "Charmander"){
		user.setPokemon(user, "Charmeleon");
		cout<<"Your Charmander has evolved into Charmeleon!"<<endl;
	}
	else if (user.pokemon == "Squirtle"){
		user.setPokemon(user, "Wartortle");
		cout<<"Your Squirtle has evovled into Wartortle!"<<endl;
	}
	else if (user.pokemon == "Ivysaur"){
		user.setPokemon(user, "Venusaur");
		cout<<"Your Ivysaur has evolved into Venusaur!"<<endl;
	}
	else if (user.pokemon == "Charmeleon"){
		user.setPokemon(user, "Charizard");
		cout<<"Your Charmeleon has evolved into Charizard!"<<endl;
	}
	else if (user.pokemon == "Wartortle"){
		user.setPokemon(user, "Blastoise");
		cout<<"Your Wartortle has evolved into Blastoise!"<<endl;
	}
	
	user.setStrength(user, 25);
	
}

void Character::setWeapon(Character user, string weapon_choice){
	user.weapon = weapon_choice;
}

void Character::setHP_Comp(Character user) {
    user.HP_Complete = true;
}

void Character::setHG_Comp(Character user) {
    user.HG_Complete = true;
}

void Character::setLOTR_Comp(Character user) {
    user.LOTR_Complete = true;
}

void Character::setpoke_Comp(Character user) {
    user.poke_Complete = true;
}

void Character::printInfo(Character user) {
    cout << "====Player Information====" << endl;
    cout << "Name: " << user.player_name << endl;
    if(user.HG_Complete) {
        cout << "Age: " << user.age << endl;
        cout << "District: " << user.district << endl;
    }
    if(user.poke_Complete) {
        cout << "Pokemon: " << user.pokemon << endl;
    }
    if(user.LOTR_Complete) {
        cout << "Weapon: " << user.weapon << endl;
    }
    cout << "Strength: " << user.strength << endl;
    
}



struct HP_Chamber {
    string name;
    string question;
    int correct_answer;
    string correct_response;
};
HP_Chamber Harry_Potter[6];

HG_Situation Hunger_Games[6];

struct poke_battle {
    string question;
    int correct_move;
    string correct_response;
    string incorrect_response;
};

poke_battle Pokemon[6];

struct lotr_battle {
	string outcome;
};

lotr_battle LotR[9];

int main(int argc, char** argv) {
	
	Character user;
	
    // Building Harry Potter World
    HP_Chamber fluffy;
    fluffy.name = "Fluffy";
    fluffy.question = "\nWelcome to Hogwarts! The Sorcerer's Stone is in danger of falling into the Dark Lord's hands. You must face a series of tasks to reach the stone before he can get his hands on it.\n"
            "A three headed dog guards a trap door in the room before you. Choose a weapon to get past it:\n"
            "1) A wand\n"
            "2) A juicy steak\n"
            "3) A flute\n";
    fluffy.correct_answer = 3;
    fluffy.correct_response = "\nThe flute's song causes the 3 headed dog to fall asleep instantly. You push his paw away to reveal a trap door and jump into the pitch black void.\n";
    Harry_Potter[0] = fluffy;
    
    HP_Chamber devilSnare;
    devilSnare.name = "Devil's Snare";
    devilSnare.question = "\nDevil's snare cushions your fall. Thick vines start to wrap around your body intent on choking you. What do you do?\n"
            "1) Reducto: a relinquishing spell\n"
            "2) Lumos Solem: produces a powerful ray of light\n"
            "3) Immobulus: renders living targets immobile\n";
    devilSnare.correct_answer = 2;
    devilSnare.correct_response = "\nThe vines retreat from the light, freeing you and revealing a door.\n";
    Harry_Potter[1] = devilSnare;
    HP_Chamber keys;
    keys.name = "Winged Keys";
    keys.question = "\nThe next room contains hundreds of winged keys flying above your head. You must use the broomstick to chase down the correct key and unlock the next door.\n"
            "Are you a good enough quidditch player to retrieve the right key? Prove it by identifying which of the following is NOT a rule:\n"
            "1) Only the keeper can block quaffle shots from the opposing team\n"
            "2) Bumphing is the foul called when a beater hits a bludger towards spectators\n"
            "3) A chaser is permitted to catch the snitch only if the seeker has been injured\n";
    keys.correct_answer = 3;
    keys.correct_response = "\nCorrect. Only the seeker may catch the snitch whether they are injured or not. Your knowledge of quidditch serves you well and you are able to snag the correct key.\n";
    Harry_Potter[2] = keys;
    
    HP_Chamber chess;
    chess.name = "Chess Board";
    chess.question = "\nThe door opens to reveal a massive chess board with 10 feet tall pieces. They block the path to the next door, can you play your way across the room?\n"
				"(Enter 1 to continue)\n";
    chess.correct_answer = 1;
    chess.correct_response = "\nYou've outsmarted the queen and reached the next door.\n";
    Harry_Potter[3] = chess;
    
    HP_Chamber potions;
    potions.name = "Snape's Riddle";
    potions.question = "\nPurple flames block the door you just came through while black flames ignite in front of the next door. A table with 7 unmarked bottles sits in front of you with a piece of parchment that reads:\n"
            "Danger lies before you, while safety lies behind,\n"
            "Two of us will help you, whichever you would find,\n"
            "One among us seven will let you move ahead,\n"
            "Another will transport the drinker back instead,\n"
            "Two among our number hold only nettle wine,\n"
            "Three of us are killers, waiting hidden in line.\n"
            "Choose, unless you wish to stay here for evermore,\n"
            "To help you in your choice, we give you these clues four:\n"
            "First, however slyly the poison tries to hide\n"
            "You will always find some on nettle wine's left side;\n"
            "Second, different are those who stand at either end,\n"
            "But if you would move onwards neither is your friend;\n"
            "Third, as you see clearly, all are different size,\n"
            "Neither dwarf nor giant holds death in their insides;\n"
            "Fourth, the second left and the second on the right\n"
            "Are twins once you taste them, though different at first sight.\n"
            "Which bottle do you drink from to survive the black flames and advance to the final chamber?\n"
            "(from left to right)\n"
            "1) Small round clear bottle\n"
            "2) Medium red bottle\n"
            "3) Tiny square blue bottle\n"
            "4) Tall orange bottle\n"
            "5) Small green bottle\n"
            "6) Large black bottle\n"
            "7) Small round purple bottle\n";
    potions.correct_answer = 3;
    potions.correct_response = "\nYou drink the potion and step through the black flames and successfully reach the final door.\n";
    Harry_Potter[4] = potions;
    
    HP_Chamber quirrell;
    quirrell.name = "\nThe Final Chamber\n";
    quirrell.question = "\n'You!' 'Me. I wondered whether I'd be meeting you here.' Standing in front of the Mirror of Erised is not Snape, but none other than Brett, the TA! Bret can't seem to get the stone from the Mirror, he tells you to look in the Mirror.\n"
            "What do you see when you look at your reflection?\n"
            "1) You're handing the stone to Dumbledore\n"
            "2) You use the stone's power of eternal life to fight Voldemort\n"
            "3) You are using the stone to bring back Harry Potter's parents\n";
    quirrell.correct_answer = 1;
    quirrell.correct_response = "\nCongratulations, the stone is in your pocket! Only someone who wanted to find the stone, find it and not use it- would be able to get it.\n"
            "Brett of course comes after you for the stone, but the magic of love in your hands effectively turns him to stone and he crumbles away freeing the evil wizard attached to the back of his head (wait, what?)\n"
            "With the stone safe and sound, Dumbledore rewards you with a piece of the code you need: si\n";
    Harry_Potter[5]= quirrell;
    
    // Constructing the Hunger Games
    
    HG_Situation cornucopia;
    cornucopia.scenario = "\nBANG! The 76th Annual Hunger Games have begun! Most of the weapons and supplies are concentrated in the Cornucopia with some backpacks and weapons scattered throughout the rest of the clearing. A lake lies to the left of the Conucopia and there's forest behind you.\n"
            "What's your plan?\n"
            "1) Charge the Cornucopia to secure resources and find allies\n"
            "2) Run to the nearest weapon, kill anyone within reach\n"
            "3) Grab the nearest backpack and run\n"
            "4) Run without approaching the Cornucopia\n";
    cornucopia.score1 = -3;
    cornucopia.score2 = -1;
    cornucopia.score3 = 1;
    cornucopia.score4 = 0;
    Hunger_Games[0] = cornucopia;
    
    HG_Situation dehydration;
    dehydration.scenario = "\nYou're in the forest miles from the Cornucopia. You are hungry and in desperate need of water. You passed a small spring with a tent near it a mile back.\n"
            "How do you proceed?\n"
            "1) Keep moving into the forest, there will probably be another spring\n"
            "2) Ask your sponsors for water\n"
            "3) Turn around and try to kill the tribute in the tent\n"
            "4) Follow animals who will hopefully lead you to water\n";
    dehydration.score1 = -1;
    dehydration.score2 = -2;
    dehydration.score3 = -1;
    dehydration.score4 = 1;
    Hunger_Games[1] = dehydration;
    
    HG_Situation weapons;
    weapons.scenario = "\nYou spot an unoccupied camp site. From your hiding place you can see a trident, an axe, a coil of wire, and a bow and arrow.\n"
            "You only have time to grab one, which do you choose?\n"
            "1) The Trident\n"
            "2) The Axe\n"
            "3) The Wire\n"
            "4) The Bow\n";
    weapons.score1 = 1;
    weapons.score2 = 1;
    weapons.score3 = 1;
    weapons.score4 = 1;
    Hunger_Games[2] = weapons;
    
    HG_Situation fight_or_flight;
    fight_or_flight.scenario = "\nYou've made your way back to the Cornucopia looking to snag some food. The district 4 Career spots you and is charging towards you.\n"
            "What do you do?\n"
            "1) Run towards the nearest tree and start climbing\n"
            "2) Head for the lake, district 4 tributes usually can't swim\n"
            "3) Pull out your weapon and brace for battle\n"
            "4) Ask to be allies\n";
    fight_or_flight.score1 = 1;
    fight_or_flight.score2 = -3;
    fight_or_flight.score3 = -1;
    fight_or_flight.score4 = -1;
    Hunger_Games[3] = fight_or_flight;
    
    HG_Situation night;
    night.scenario = "\nNight has fallen and the temperature has dropped. From the cave you've found to sleep in you spot the light of a fire a few hundred yards away.\n"
            "You're freezing cold, what do you do?\n"
            "1) Ask the tribute to be allies to share the fire's warmth\n"
            "2) Kill the tribute to use the fire for yourself\n"
            "3) Try to build your own fire\n"
            "4) Suck it up and cover yourself in more pine needles\n";
    night.score1 = -3;
    night.score2 = -3;
    night.score3 = -2;
    night.score4 = 1;
    Hunger_Games[4] = night;
    
    HG_Situation finale;
    finale.scenario = "\nThe 76th Hunger Games are coming to a close. You and the boy from district 2 are the only ones left. \n"
            "To claim the victor's crown you must face him in the final battle. What is your strategy?\n"
            "1) Set various traps and snares throughout the arena and wait till he falls into one to attack\n"
            "2) Take the straight up approach and face him head on\n"
            "3) Trick him into eating poisonous berries\n"
            "4) Set up a diversion, use the element of surprise to take the upper hand\n";
    finale.score1 = 1;
    finale.score2 = -3;
    finale.score3 = -1;
    finale.score4 = 1;
    Hunger_Games[5] = finale;
    
    //constructing the pokemon world
    poke_battle Ash_grass;
    Ash_grass.question = "\n'Wow! A "+user.pokemon+"! That's so cool!' Says the boy with the yellow mouse. 'This is my Pikachu! And I'm Ash Ketchum!' He exclaims proudly.\n"
			"'So, Professor Oak is giving you a Pokemon too! That's great!'\n"
			"'We should have a battle!'\n"
			"You send out your brand new "+user.pokemon+", and Ash sends out his Pikachu.\n"
    
			"\nWhat move will you use? \n"
			"1. Spark- Electric type\n"
			"2. Mud Bomb- Ground type\n"
			"3. Tackle- Normal type\n"
			"4. Vine Whip- Grass type\n";
			
	Ash_grass.correct_move = 2;
	Ash_grass.correct_response = "\nYour move was super effective! Pikachu was knocked out in one hit!\n";
	Ash_grass.incorrect_response = "\nYour move was not very effective! Pikachu countered with Volt Tackle, his signature move, and "+user.pokemon+" was knocked out in one hit!\n";
    Pokemon[0] = Ash_grass;
    
    poke_battle Rival_grass;
	Rival_grass.question = "\n'That was a fun battle!' Ash exclaims.\n"
			"The door opens behind you and TA Matt walks in. Ash has an angry look on his face. 'Oh no,' he mutters, 'it's my rival, TA Matt!'\n"
			"'Oh good, now you're all here!' Says Professor Oak. 'Why don't you choose a Pokemon, TA Matt'\n"
			"'I'll take whatever is super-effective against "+user.player_name+"'s Pokemon, because that's just the type of guy I am,' says TA .\n"
			"'Alright then, here's your "+user.rival_pokemon+",' says Professor Oak, handing him the "+user.rival_pokemon+".\n"
			"Now let's battle, "+user.player_name+"!\n"
			"You send out your "+user.pokemon+", and TA Matt sends out his "+user.rival_pokemon+".\n"
			
			"What move will "+user.pokemon+" use?\n"
			"1. Tackle- Normal type\n"
			"2. Ember- Fire type\n"
			"3. Water Gun- Water type\n"
			"4. Vine Whip- Grass type\n";
			
	Rival_grass.correct_move = 3;
	Rival_grass.correct_response = "\nYour move was super effective! "+user.rival_pokemon+" was knocked out in one hit!\n";
	Rival_grass.incorrect_response = "\nYour move wasn't very effective, "+user.rival_pokemon+" coutered and "+user.pokemon+" was knocked out in one hit!\n";
    Pokemon[1] = Rival_grass;
    
    
    poke_battle Ash_fire;
    Ash_fire.question = "\n'Wow! A "+user.pokemon+"! That's so cool!' Says the boy with the yellow mouse. 'This is my Pikachu! And I'm Ash Ketchum!' He exclaims proudly.\n"
			"'So, Professor Oak is giving you a Pokemon too! That's great!'\n"
			"'We should have a battle!'\n"
			"You send out your brand new "+user.pokemon+", and Ash sends out his Pikachu.\n"
    
			"\nWhat move will you use? \n"
			"1. Spark- Electric type\n"
			"2. Mud Bomb- Ground type\n"
			"3. Tackle- Normal type\n"
			"4. Ember- Fire type\n";
			
	Ash_fire.correct_move = 2;
	Ash_fire.correct_response = "\nYour move was super effective! Pikachu was knocked out in one hit!\n";
	Ash_fire.incorrect_response = "\nYour move was not very effective! Pikachu countered with Volt Tackle, his signature move, and "+user.pokemon+" was knocked out in one hit!\n";
    Pokemon[2] = Ash_fire;
    
    poke_battle Rival_fire;
	Rival_fire.question = "\n'That was a fun battle!' Ash exclaims.\n"
			"The door opens behind you and TA Matt walks in. Ash has an angry look on his face. 'Oh no,' he mutters, 'it's my rival, TA Matt!'\n"
			"'Oh good, now you're all here!' Says Professor Oak. 'Why don't you choose a Pokemon, TA Matt'\n"
			"'I'll take whatever is super-effective against "+user.player_name+"'s Pokemon, because that's just the type of guy I am,' says TA Matt.\n"
			"'Alright then, here's your "+user.rival_pokemon+",' says Professor Oak, handing him the "+user.rival_pokemon+".\n"
			"Now let's battle, "+user.player_name+"!\n"
			"You send out your "+user.pokemon+", and TA Matt sends out his "+user.rival_pokemon+".\n"
			
			"What move will "+user.pokemon+" use?\n"
			"1. Tackle- Normal type\n"
			"2. Ember- Fire type\n"
			"3. Water Gun- Water type\n"
			"4. Vine Whip- Grass type\n";
			
	Rival_fire.correct_move = 4;
	Rival_fire.correct_response = "\nYour move was super effective! "+user.rival_pokemon+" was knocked out in one hit!\n";
	Rival_fire.incorrect_response = "\nYour move wasn't very effective, "+user.rival_pokemon+" coutered and "+user.pokemon+" was knocked out in one hit!\n";
    Pokemon[3] = Rival_fire;
    
    
    poke_battle Ash_water;
    Ash_water.question = "\n'Wow! A "+user.pokemon+"! That's so cool!' Says the boy with the yellow mouse. 'This is my Pikachu! And I'm Ash Ketchum!' He exclaims proudly.\n"
	"'So, Professor Oak is giving you a Pokemon too! That's great!'\n"
	"'We should have a battle!'\n"
	"You send out your brand new "+user.pokemon+", and Ash sends out his Pikachu.\n"
    
			"\nWhat move will you use? \n"
			"1. Spark- Electric type\n"
			"2. Mud Bomb- Ground type\n"
			"3. Tackle- Normal type\n"
			"4. Water Gun- Water type\n";
			
	Ash_water.correct_move = 2;
	Ash_water.correct_response = "\nYour move was super effective! Pikachu was knocked out in one hit!\n";
	Ash_water.incorrect_response = "\nYour move was not very effective! Pikachu countered with Volt Tackle, his signature move, and "+user.pokemon+" was knocked out in one hit!\n";
    Pokemon[4] = Ash_water;
			
	poke_battle Rival_water;
	Rival_water.question = "\n'That was a fun battle!' Ash exclaims.\n"
			"The door opens behind you and TA Matt walks in. Ash has an angry look on his face. 'Oh no,' he mutters, 'it's my rival, TA Matt!'\n"
			"'Oh good, now you're all here!' Says Professor Oak. 'Why don't you choose a Pokemon, TA Matt'\n"
			"'I'll take whatever is super-effective against "+user.player_name+"'s Pokemon, because that's just the type of guy I am,' says TA Matt.\n"
			"'Alright then, here's your "+user.rival_pokemon+",' says Professor Oak, handing him the "+user.rival_pokemon+".\n"
			"Now let's battle, "+user.player_name+"!\n"
			"You send out your "+user.pokemon+", and TA Matt sends out his "+user.rival_pokemon+".\n"
			
			"What move will "+user.pokemon+" use?\n"
			"1. Tackle- Normal type\n"
			"2. Ember- Fire type\n"
			"3. Water Gun- Water type\n"
			"4. Vine Whip- Grass type\n";
			
	Rival_water.correct_move = 2;
	Rival_water.correct_response = "\nYour move was super effective! "+user.rival_pokemon+" was knocked out in one hit!\n";
	Rival_water.incorrect_response = "\nYour move wasn't very effective, "+user.rival_pokemon+" coutered and "+user.pokemon+" was knocked out in one hit!\n";
    Pokemon[5] = Rival_water;
    
    string user_command;
    string user_name;
    string user_district;
    string user_age;
    string user_poke;
    string user_weapon;
    string user_station;
    
    //building lotr battle outcomes
    
    lotr_battle Spear_Front;
    Spear_Front.outcome = "\nYou meet Aragorn on the front lines, leading the bravest defenders in battle."
			"'Good to see you, "+user.player_name+"', he says. 'I hope you brought a strong spear to hold off the Urukhai.'"
			"Fortunately, you did. The battle goes well for you and Aragorn. You help him lead the men on the front lines, and the men of Rohan hold Helm's Deep through the siege.\n"
			"For fighting with him valiantly, Aragorn rewards you with his token, a golden medallion with a crown on it. Gazing on it fills you with courage.\n";
	LotR[0] = Spear_Front;
	
	lotr_battle notSpear_Front;
	notSpear_Front.outcome = "\nYou meet Aragorn on the front lines, leading the bravest defenders in battle."
			"'Good to see you, "+user.player_name+"', he says. 'I hope you brought a strong spear to hold off the Urukhai.'"
			"Unfortunately, you didn't. The battle goes poorly for you and Aragorn. The Urukhai break through your front lines, but men in other parts of the keep drive them off.\n"
			"No thanks to you, the men of Rohan hold Helm's Deep through the siege.\n";
	LotR[1] = notSpear_Front;
	
	lotr_battle strSpear_Front;
    Spear_Front.outcome = "\nYou meet Aragorn on the front lines, leading the bravest defenders in battle."
			"'Good to see you, "+user.player_name+"', he says. 'I hope you brought a strong spear to hold off the Urukhai.'"
			"You didn't, but fortunately your strength allows you to use your "+user.weapon+" to great effect. You help him lead the men on the front lines, and the men of Rohan hold Helm's Deep through the siege.\n"
			"For fighting with him valiantly, Aragorn rewards you with his token, a golden medallion with a crown on it. Gazing on it fills you with courage.\n";
	LotR[2] = Spear_Front;	
	
	lotr_battle Sword_Keep;
	Sword_Keep.outcome = "\nYou meet Gimli in the inner keep, preparing the men for the melee.\n"
			"'Good to see you, "+user.player_name+"', he says. 'I hope you have a strong sword so you'll be ready for anything.'\n"
			"Fortunately, you do. The battle goes well for you and Gimli. You help him lead the brawl in the inner keep, and the men of Rohan hold Helm's Deep through the siege.\n"
			"For fighting with him valiantly, Gimli rewards you with his token, a stone medallion with a hammer on it. Gazing on it fills you with strength.\n";
	LotR[3] = Sword_Keep;
	
	lotr_battle notSword_Keep;
	notSword_Keep.outcome = "\nYou meet Gimli in the inner keep, preparing the men for the melee.\n"
			"'Good to see you, "+user.player_name+"', he says. 'I hope you have a strong sword so you'll be ready for anything.'\n"
			"Unfortunately, you don't. The battle goes poorly for you and Gimli. The Urukhai wreak havoc in the inner keep, but men in other parts of the keep drive them off./n"
			"No thanks to you, the men of Rohan hold Helm's Deep through the siege./n";
	LotR[4] = notSword_Keep;
	
	lotr_battle strSword_Keep;
	Sword_Keep.outcome = "\nYou meet Gimli in the inner keep, preparing the men for the melee.\n"
			"'Good to see you, "+user.player_name+"', he says. 'I hope you have a strong sword so you'll be ready for anything.'\n"
			"You don't, but fortunately your strength allows you to use your "+user.weapon+" to great effect. You help him lead the brawl in the inner keep, and the men of Rohan hold Helm's Deep through the siege.\n"
			"For fighting with him valiantly, Gimli rewards you with his token, a stone medallion with a hammer on it. Gazing on it fills you with strength.\n";
	LotR[5] = Sword_Keep;
	
	lotr_battle Bow_Walls;
	Bow_Walls.outcome = "\nYou meet Legolas on the castle walls, preparing archers as the last line of defense.\n"
			"'Good to see you, "+user.player_name+"', he says. 'I hope you have a taught bow to help pick off the enemy.'\n"
			"You don't, but fortunately your strength allows you to use your "+user.weapon+" to great effect. You help him hold off Urukhai from the walls, and the men of Rohan hold Helm's Deep through the siege.\n"
			"For fighting with him valiantly, Legolas rewards you with his token, a green gemstone medallion shaped like a leaf. Gazing on it fills you with calm.\n";
	LotR[6] = Bow_Walls;
	
	lotr_battle notBow_Walls;
	notBow_Walls.outcome = "\nYou meet Legolas on the castle walls, preparing archers as the last line of defense.\n"
			"'Good to see you, "+user.player_name+"', he says. 'I hope you have a taught bow to help pick off the enemy.'\n"
			"Unfortunately, you don't. The battle goes poorly for you and Legolas. You serve no purpose on the castle walls, but men in other parts of the keep drive them off.\n"
			"No thanks to you, the men of Rohan hold Helm's Deep through the siege.\n";
	LotR[7] = notBow_Walls;
	
	lotr_battle strBow_Walls;
	Bow_Walls.outcome = "\nYou meet Legolas on the castle walls, preparing archers as the last line of defense.\n"
			"'Good to see you, "+user.player_name+"', he says. 'I hope you have a taught bow to help pick off the enemy.'\n"
			"Fortunately, you do. The battle goes well for you and Legolas. You help him shoot down Urukhai from the walls, and the men of Rohan hold Helm's Deep through the siege.\n"
			"For fighting with him valiantly, Legolas rewards you with his token, a green gemstone medallion shaped like a leaf. Gazing on it fills you with calm.\n";
	LotR[8] = Bow_Walls;
    
    cout << "Help! Professor Hoenigman has built a super computer to open portals to the top Nerd Fandoms. She has sent her minions out to invade their Kingdoms and wreak havoc on the Nerd Universe." << endl;
    cout << "Your mission, should you choose to accept it, is to enter each of the worlds and complete a quest to restore order." << endl;
    
    cout << endl;
    cout << "Enter your name:" << endl;
    getline(cin, user_name);
    user.player_name = user_name;
    
    while (true) {
		cout << endl;
        cout << "5 doors each emblazed with a different symbol are before you. Pick one to enter:" << endl;
        cout << "1. Lightning bolt" << endl;
        cout << "2. A bird taking flight" << endl;
        cout << "3. A pokeball" << endl;
        cout << "4. Two towers" << endl;
        cout << "5. Enter the code to kill the super computer" << endl;
        cout << "6. View info" << endl;
        cout << "7. Refuse the quest" << endl;
        getline(cin, user_command);

        switch (stoi(user_command)) {
            case 1:
            {
                if(user.HP_Complete) {
                   cout << "You've already completed this quest!" << endl;
                   break;
                }
                if(user.strength < 100) {
					cout << "You're not strong enough for this door yet! Try other quests first!" << endl;
					break;
				}
                HP_Chamber currentChamber;
                string user_answer;
                for(int i = 0; i < 6; i++) {
                    currentChamber = Harry_Potter[i];
                    cout << currentChamber.question << endl;
                    getline(cin, user_answer);
                    if(stoi(user_answer) == currentChamber.correct_answer) {
                        cout << currentChamber.correct_response << endl;
                    } else {
                        cout << "Wrong choice. You have failed to make it to the next chamber." << endl;
                        break;
                    }
                }
                user.setHP_Comp(user);
                break;
            }
            case 2:
            {
                if(user.HG_Complete) {
                   cout << "You've already completed this quest!" << endl;
                   break;
                }
                if(user.strength < 100) {
					cout << "You're not strong enough for this door yet! Try other quests first!" << endl;
					break;
				}
                cout << "Pick a number between 1 and 12" << endl;
                getline(cin, user_district);
                while(stoi(user_district) < 1 || stoi(user_district) > 12) {
                    cout << "Pick a valid number." << endl;
                    getline(cin, user_district);
                }
                cout << "Pick a number between 12 and 18" << endl;
                getline(cin, user_age);
                while(stoi(user_age) < 12 || stoi(user_district) > 18) {
                    cout << "Pick a valid number." << endl;
                    getline(cin, user_age);
                }
                int startingSurvival = user.calcSurvival(stoi(user_district), stoi(user_age));
                user.survivalOdd += startingSurvival;
                HG_Situation currentScenario;
                string user_answer;
                for(int i = 0; i < 6; i++) {
                    if(user.survivalOdd <= 0) {
                        cout << "YOU DIED." << endl;
                        break;
                    }
                    currentScenario = Hunger_Games[i];
                    cout << currentScenario.scenario << endl;
                    getline(cin, user_answer);
                    int survivalScore = user.setSurvival(stoi(user_answer), currentScenario);
                    user.survivalOdd += survivalScore;
                }
                user.setHG_Comp(user);
                cout << endl;
                cout << "The blast of the cannon goes off signifying your last competitor's death. You have survived the Hunger Games." << endl;
                cout << "You're whisked away to the closing ceremony where everyone is celebrating your victory. " << endl;
                cout << "You take your place on the throne, as the president comes to present you the victors crown." << endl;
                cout << "Wearing a finely tailored suit with his signature white rose in the lapel, President TA Nilesh places the gold crown on top of your head saying," << endl;
                cout << "'Congratulations, your recitation must be very proud.' " << endl;
                cout << "Engraved on the crown is the next piece of the code: curetrusts" << endl;
                break;
            }
            case 3:
            {
                if (user.poke_Complete){
                    cout << "You've already completed this quest!" << endl;
                    break;
                }
                cout<<endl;                                                         
                cout<<"You find yourself in a laboratory. Unfamiliar machines whir and buzz around you, and you see an elderly man in a labcoat and a boy of about 10 years across the room, discucssing something excitedly. "<<endl;
                cout<<"They notice you and turn, and you see that the boy has a giant yellow mouse in his arms."<<endl;
                cout<<"'Ah, "+user.player_name+" it's you!' The professor exclaims. 'I almost thought you wouldn't make it. Come, have a look. It's your turn to choose.'"<<endl;
                cout<<"He gestures to a table behind him, where three more of the terrifying creatures sit:"<<endl;
                cout<<"A green animal with a flower bud on its back, labeled 'Bulbasaur',"<<endl;
                cout<<"a large orange lizard with a flame on the end of its tail, labeled 'Charmander',"<<endl;
                cout<<"and some kind of cross between a squirrel and a turtle. labeled 'Squirtle'."<<endl;
                
                cout<<endl;
                cout<<"Which will you choose?"<<endl;
                cout<<"1. Bulbasaur"<<endl;
                cout<<"2. Charmander"<<endl;
                cout<<"3. Squirtle"<<endl;
                
                int user_poke;
                cin>>user_poke;
                while (user_poke < 1 || user_poke > 3){
					cout<<"Enter a valid number."<<endl;
					cin>>user_poke;
				}
				switch (user_poke){
					case 1:{
						user.setPokemon(user, "Bulbasaur");
						break;
					}
					case 2:{
						user.setPokemon(user, "Charmander");
						break;
					}
					case 3:{
						user.setPokemon(user, "Squirtle");
						break;
					}
					default:{
						cout<<"Enter a valid number."<<endl;
						cin>>user_poke;
					}
				}

                cout<<endl;
                cout<<"You now have a Pokemon!"<<endl;
                user.setStrength(user, 25);
                
                poke_battle current_battle;
                int user_answer;
                
                if (user_poke == 1){
					for (int i = 0; i < 2; i++){
						current_battle = Pokemon[i];
						cout << current_battle.question << endl;
						cin >> user_answer;
						while (user_answer < 1 || user_answer > 4){
							cout<<"Enter a valid number."<<endl;
							cin>>user_answer;
						}
						if (user_answer == current_battle.correct_move){
							cout<<current_battle.correct_response<<endl;
							
						}
						else {
							cout<<current_battle.incorrect_response<<endl;
						}
					}
				}
				
				else if (user_poke == 2){
					for (int i = 2; i < 4; i++){
						current_battle = Pokemon[i];
						cout << current_battle.question << endl;
						cin >> user_answer;
						while (user_answer < 1 || user_answer > 4){
							cout<<"Enter a valid number."<<endl;
							cin>>user_answer;
						}
						if (user_answer == current_battle.correct_move){
							cout<<current_battle.correct_response<<endl;
						}
						else {
							cout<<current_battle.incorrect_response<<endl;
						}
					}
				}
				
				else if (user_poke == 3){
					for (int i = 4; i < 6; i++){
						current_battle = Pokemon[i];
						cout << current_battle.question << endl;
						cin >> user_answer;
						while (user_answer < 1 || user_answer > 4){
							cout<<"Enter a valid number."<<endl;
							cin>>user_answer;
						}
						if (user_answer == current_battle.correct_move){
							cout<<current_battle.correct_response<<endl;
						}
						else {
							cout<<current_battle.incorrect_response<<endl;
						}
					}
				}
                
                cout<<endl;
				cout<<"'Wow, another great battle!' Says Ash."<<endl;
				cout<<"With your new "+user.pokemon+" as a companion, you feel ready to take on more adventures."<<endl;
				cout<<"You say goodbye to TA Matt, Professor Oak, and Ash, and leave the laboratory, but not before Oak gives you another clue: tada"<<endl;
				user.setpoke_Comp(user);
                break;
            }
            case 4: 
            {
				if (user.LOTR_Complete){
                    cout << "You've already completed this quest!" << endl;
                    break;
                }
                
                cout<<endl;
				cout<<"This door leads you to a great stone keep. Men in armor with swords, bows, and lances hurry to and fro all around you. It seems like they are preparing for a battle."<<endl;
				cout<<"One of the shortest, stoutest men you've ever seen approaches you. He has a thick red beard and a huge double sided batle axe, as tall as he is."<<endl;
				cout<<"'Come on, quit standing around gawking!' He bellows at you. 'We need all able bodied citizens preparing to defend Helm's Deep against TA Kannan's Urukhai!'"<<endl;
				cout<<"A tall, slender, fair-skinned man strolls up beside the first. An elegant bow is strapped across his back."<<endl;
				cout<<"'For once, I agree with the dwarf,' he states. 'Who are you? I've never seen you before.'"<<endl;
				cout<<"'Please excuse the behavior of my companions,' says a strong, dark-haired man as he approaches. You feel a sense of power coming from this thrid man."<<endl;
				cout<<"'This is "<<user.player_name<<",' he says, gesturing to you.' "<<user.player_name<<" has been sent to aide us in the battle that lies before us.'"<<endl;
				cout<<"'These two are Legolas the elf,' he says, pointing to the tall, fair man, 'and Gimli the dwarf,' pointing to the short man with the beard."<<endl;
				cout<<"'And I am Aragorn, son of Arathorn,' he states. 'And you had best get to the armory to find yourself a weapon.'"<<endl;

				cout<<endl;
				cout<<"He directs you to the armory. The smiths outfit you with adequate armor. Then they point to the weapon racks, and ask what kind of weapon you prefer."<<endl;
				cout<<"There are spears, almost as tall as you are, heavy, and with deadly points on the ends,"<<endl;
				cout<<"there are swords, with sharp blades, that feel light and maneuverable in your hand,"<<endl;
				cout<<"and there are bows, with quivers of arrows, deadly from a distance, but nearly useless up close."<<endl;
				
				cout<<endl;
				cout<<"Which weapon will you choose?"<<endl;
				cout<<"1. Spear"<<endl;
				cout<<"2. Sword"<<endl;
				cout<<"3. Bow"<<endl;

				int weapon_choice;
				cin>>weapon_choice;

				switch(weapon_choice){
					case 1:{
						user.setWeapon(user, "Spear");
						break;
					}
					case 2:{
						user.setWeapon(user, "Sword");
						break;
					}
					case 3:{
						user.setWeapon(user, "Bow");
						break;
					}
					default:{
						cout<<"Invalid selection."<<endl;
						cin>>weapon_choice;
					}
				}
				
				cout<<"You know have a "<<user.weapon<<"!"<<endl;
                user.setStrength(user, 25);
                
                cout<<endl;
				cout<<"'Ah, the "<<user.weapon<<" , an excellent choice,' says a man behind you, dressed in glistening gold and green armor, with a golden horse across his chest."<<endl;
				cout<<"'I am Theoden, king of Rohan,' he says, 'and king of this keep. I don't intend to lose it tonight, but I'll need your help for that."<<endl;
				cout<<"I'll let you choose your own station, where you think you'll be of most use to us, based on your own skills,' he says."<<endl;
				cout<<"'We need strong, fearless soldiers on the front lines, ready to hold off waves of enemies,"<<endl;
				cout<<"we need quick, reactive men ready for anything in the inner keep, in case the enemy breaks through anywhere,"<<endl;
				cout<<"and last, we need the staunchest defenders on the castle walls, keeping a watchful eye over the battle.'"<<endl;
				
				cout<<endl;
				cout<<"So, what'll it be?"<<endl;
				cout<<"1. Front Lines"<<endl;
				cout<<"2. Inner Keep"<<endl;
				cout<<"3. Castle Walls"<<endl;
				
				lotr_battle outcome_battle;
				int station_choice;
				cin>>station_choice;

				switch (station_choice){
					case 1:{
						if (weapon_choice == 1){
							outcome_battle = LotR[0];
							cout<<outcome_battle.outcome<<endl;
							user.setStrength(user, 25);
						}
						else if (user.strength > 100){
							outcome_battle = LotR[2];
							cout<<outcome_battle.outcome<<endl;
							user.setStrength(user, 25);
						}
						else {
							outcome_battle = LotR[1];
						}
						break;
					}
					case 2:{
						if (weapon_choice == 2){
							outcome_battle = LotR[3];
							cout<<outcome_battle.outcome<<endl;
							user.setStrength(user, 25);
						}
						else if (user.strength > 100){
							outcome_battle = LotR[5];
							cout<<outcome_battle.outcome<<endl;
							user.setStrength(user, 25);
						}
						else {
							outcome_battle = LotR[4];
						}
						break;
					}
					case 3:{
						if (weapon_choice == 3){
							outcome_battle = LotR[6];
							cout<<outcome_battle.outcome<<endl;
							user.setStrength(user, 25);
						}
						else if (user.strength > 100){
							outcome_battle = LotR[8];
							cout<<outcome_battle.outcome<<endl;
							user.setStrength(user, 25);
						}
						else {
							outcome_battle = LotR[7];
						}
						break;
					}
					default:{
						cout<<"Invalid Selection."<<endl;
						cin>>station_choice;
					}
				}
                
                cout<<endl;
				cout<<"The armorers let you keep your "<<user.weapon<<" to use in your future adventures. You say your goodbyes to Aragorn, Legolas, Gimli, and Theoden."<<endl;
				cout<<"King Theoden hands you another piece of the code before you go: nfu"<<endl;
                
                user.setLOTR_Comp(user);
                break;
            }
            case 5:
            {
				string kill_code;
				cout<<"Please enter the code:"<<endl;
				getline(cin, kill_code);
				if (kill_code == "data structures is fun"){
					cout<<"ACCESS GRANTED"<<endl;
					cout<<"Congratulations! You have shut down the super computer and destroyed the COG script once and for all!"<<endl;
					cout<<"You have defeated Professor Hoenigman and her evil TA's! Thanks for playing!"<<endl;
					return 0;
				}
				
				else if (kill_code == "si curetrusts tada nfu"){
					cout<<"ACCESS DENIED"<<endl;
					cout<<"Oh no! That's not the code!"<<endl;
					cout<<"Maybe you should try unscrambling it."<<endl;
				}
				
				else {
					cout<<"ACCESS DENIED"<<endl;
					cout<<"Oh no! That's not the code!"<<endl;
				}
                break;
            }
            case 6:
            {
                user.printInfo(user);
                break;
            }
            case 7:
            {
                cout << "Goodbye!" << endl;
                return 0;
            }
            default:
            {
                cout << "Pick the number of the door you wish to enter." << endl;
            }
        }
    }
    return 0;
}
