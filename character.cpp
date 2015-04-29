#include <iostream>
#include <string>
#include "character.h"

using namespace std;

void Character::setName(string user_name){
	player_name = user_name;
}

string Character::getName(){
	return player_name;
}

void Character::setAge(int user_age){
	age = user_age;
}

int Character::getAge(){
	return age;
}

void Character::setDistrict(int user_district){
	district = user_district;
}

int Character::getDistrict(){
	return district;
}

// Calculate the starting survival odd of a character based on age and district
// Districts 1,2,4 are elite "Career" and give the highest chance of survival
// The other districts are weighted by what their district's specialty is (agriculture, electronics, textiles, ect)
// For age the chances of a 12 year old winning are a lot smaller than those of an 18 year old
// The weights of each are added together to give the user a starting survival odd
int Character::calcSurvival(int district, int age) {
    int initial_survivalOdd = 0;
    switch (district) {
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
    switch (age) {
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

void Character::setSurvivalOdd(int newSurvivalOdd) {
    survivalOdd += newSurvivalOdd;
}

// This updates the player's survival odd as they go through each scenario
// Smart decisions yield positive scores, bad decisions give negative scores
int Character::setSurvival(int answer, HG_Situation scenario) {
    int survivalScore = 0;
    switch (answer) {
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

int Character::getSurvivalOdd(){
	return survivalOdd;
}

// updates the strength of the player as they move through the Lord of the Rings and Pokemon quests
void Character::setStrength(int newStrength) {
    strength += newStrength;
    cout << "Your strength has increased by " << newStrength << " to " << strength << "!" << endl;
}

int Character::getStrength(){
	return strength;
}

// sets player's pokemon
void Character::setPokemon(string user_poke) {
    pokemon = user_poke;
}

string Character::getPokemon(){
	return pokemon;
}

// If the player wins the pokemon battle their pokemon evolves and their strength increases
void Character::evolvePokemon() {

    cout << endl;
    cout << "What? Your " + pokemon + " is evolving!" << endl;

    if (pokemon == "Bulbasaur") {
        setPokemon("Ivysaur");
        cout << "Your Bulbasaur has evolved into Ivysaur!" << endl;
    } else if (pokemon == "Charmander") {
        setPokemon("Charmeleon");
        cout << "Your Charmander has evolved into Charmeleon!" << endl;
    } else if (pokemon == "Squirtle") {
        setPokemon("Wartortle");
        cout << "Your Squirtle has evovled into Wartortle!" << endl;
    } else if (pokemon == "Ivysaur") {
        setPokemon("Venusaur");
        cout << "Your Ivysaur has evolved into Venusaur!" << endl;
    } else if (pokemon == "Charmeleon") {
        setPokemon("Charizard");
        cout << "Your Charmeleon has evolved into Charizard!" << endl;
    } else if (pokemon == "Wartortle") {
        setPokemon("Blastoise");
        cout << "Your Wartortle has evolved into Blastoise!" << endl;
    }

    setStrength(25);

}

// set user weapon
void Character::setWeapon(string weapon_choice) {
    weapon = weapon_choice;
}

string Character::getWeapon(){
	return weapon;
}
// set when the player completes the Harry Potter quest
void Character::setHP_Comp() {
    HP_Complete = true;
}

bool Character::getHP_Comp(){
	return HP_Complete;
}

// set when the player completes the Hunger Games quest
void Character::setHG_Comp() {
    HG_Complete = true;
}

bool Character::getHG_Comp(){
	return HG_Complete;
}

// set when the player completes the Lord of the Rings quest
void Character::setLOTR_Comp() {
    LOTR_Complete = true;
}

bool Character::getLOTR_Comp(){
	return LOTR_Complete;
}

// set when the player completes the Pokemon quest
void Character::setpoke_Comp() {
    poke_Complete = true;
}

bool Character::getpoke_Comp(){
	return poke_Complete;
}

// Prints the info of the player, changes as they complete quests
void Character::printInfo() {
    cout << "====Player Information====" << endl;
    cout << "Name: " << player_name << endl;
    if (HP_Complete) {
        cout << "Sorcerer's Stone: Secured" << endl;
    }
    if (HG_Complete) {
        cout << "Age: " << age << endl;
        cout << "District: " << district << endl;
        cout << "Hunger Games Status: Survived" << endl;
    }
    if (poke_Complete) {
        cout << "Pokemon: " << pokemon << endl;
        cout << "Pokemon Trainer Status: Champion" << endl;
    }
    if (LOTR_Complete) {
        cout << "Weapon: " << weapon << endl;
        cout << "Helm's Deep: Defended" << endl;
    }
    cout << "Strength: " << strength << endl;
    cout << "Code: ";
    if(HP_Complete) {
        cout << "si ";
    }
    if(HG_Complete) {
        cout << "curetrusts ";
    }
    if(poke_Complete) {
        cout << "tada ";
    }
    if(LOTR_Complete) {
        cout << "nfu" << endl;
    }

}
