#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
using namespace std;

// Creating the node for the Hunger Games Quest
struct HG_Situation {
    std::string scenario;
    int score1;
    int score2;
    int score3;
    int score4;
};

using namespace std;

class Character {
private:
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
	
public:
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
    void setName(string user_name);
    string getName();
    void setAge(int user_age);
    int getAge();
    void setDistrict(int user_district);
    int getDistrict();
    int calcSurvival(int district, int age);
    int setSurvival(int answer, HG_Situation scenario);
    void setSurvivalOdd(int newSurvivalOdd);
    int getSurvivalOdd();
    void setPokemon(string user_poke);
    string getPokemon();
    void evolvePokemon();
    void setWeapon(string weapon_choice);
    string getWeapon();
    void setStrength(int newStrength);
    int getStrength();
    void setHP_Comp();
    bool getHP_Comp();
    void setHG_Comp();
    bool getHG_Comp();
    void setLOTR_Comp();
    bool getLOTR_Comp();
    void setpoke_Comp();
    bool getpoke_Comp();
    void printInfo();

};

#endif
