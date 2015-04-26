/*
 * File:   main.cpp
 * Author: Sonia
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

class Character
{
    bool haveStone;
    int district;
    int age;
    int survivalOdd;
    Character();
    void calcSurvival();
};

Character::Character(){
    haveStone = false;
    district = 0;
    age = 0;
    survivalOdd = 0;

}

struct HP_Chamber {
    string name;
    string question;
    int correct_answer;
    string correct_response;
};
HP_Chamber Harry_Potter[6];

struct HG_Situation {
    string scenario;
    int score1;
    int score2;
    int score3;
    int score4;
};
HG_Situation Hunger_Games[6];

int main(int argc, char** argv) {
    // Building Harry Potter World
    HP_Chamber fluffy;
    fluffy.name = "Fluffy";
    fluffy.question = "Welcome to Hogwarts! The Sorcerer's Stone is in danger of falling into the Dark Lord's hands. You must face a series of tasks to reach the stone before he can get his hands on it. "
            "A three headed dog guards a trap door in the room before you. Choose a weapon to get past it:"
            "1) A wand"
            "2) A juicy steak "
            "3) A flute";
    fluffy.correct_answer = 3;
    fluffy.correct_response = "The flute's song causes the 3 headed dog to fall asleep instantly. You push his paw away to reveal a trap door and jump into the pitch black void.";
    Harry_Potter[0] = fluffy;
    HP_Chamber devilSnare;
    devilSnare.name = "Devil's Snare";
    devilSnare.question = "Devil's snare cushions your fall. Thick vines start to wrap around your body intent on choking you. What do you do?"
            "1) Reducto: a relinquishing spell"
            "2) Lumos Solem: produces a powerful ray of light"
            "3) Immobulus: renders living targets immobile";
    devilSnare.correct_answer = 2;
    devilSnare.correct_response = "The vines retreat from the light, freeing you and revealing a door.";
    Harry_Potter[1] = devilSnare;
    HP_Chamber keys;
    keys.name = "Winged Keys";
    keys.question = "The next room contains hundreds of winged keys flying above your head. You must use the broomstick to chase down the correct key and unlock the next door."
            "Are you a good enough quidditch player to retrieve the right key? Prove it by identifying which of the following is NOT a rule:"
            "1) Only the keeper can block quaffle shots from the opposing team"
            "2) Bumphing is the foul called when a beater hits a bludger towards spectators"
            "3) A chaser is permitted to catch the snitch only if the seeker has been injured";
    keys.correct_answer = 3;
    keys.correct_response = "Correct. Only the seeker may catch the snitch whether they are injured or not. Your knowledge of quidditch serves you well and you are able to snag the correct key.";
    Harry_Potter[2] = keys;
    HP_Chamber chess;
    chess.name = "Chess Board";
    chess.question = "The door opens to reveal a massive chess board with 10 feet tall pieces. They block the path to the next door, can you play your way across the room?";
    chess.correct_answer = 1;
    chess.correct_response = "You've outsmarted the queen and reached the next door.";
    Harry_Potter[3] = chess;
    HP_Chamber potions;
    potions.name = "Snape's Riddle";
    potions.question = "Purple flames block the door you just came through while black flames ignite in front of the next door. A table with 7 unmarked bottles sits in front of you with a piece of parchment that reads: "
            "Danger lies before you, while safety lies behind,"
            "Two of us will help you, whichever you would find,"
            "One among us seven will let you move ahead,"
            "Another will transport the drinker back instead,"
            "Two among our number hold only nettle wine,"
            "Three of us are killers, waiting hidden in line."
            "Choose, unless you wish to stay here for evermore,"
            "To help you in your choice, we give you these clues four:"
            "First, however slyly the poison tries to hide"
            "You will always find some on nettle wine's left side;"
            "Second, different are those who stand at either end,"
            "But if you would move onwards neither is your friend;"
            "Third, as you see clearly, all are different size,"
            "Neither dwarf nor giant holds death in their insides;"
            "Fourth, the second left and the second on the right"
            "Are twins once you taste them, though different at first sight."
            "Which bottle do you drink from to survive the black flames and advance to the final chamber?"
            "(from left to right)"
            "1) Small round clear bottle"
            "2) Medium red bottle"
            "3) Tiny square blue bottle"
            "4) Tall orange bottle"
            "5) Small green bottle"
            "6) Large black bottle"
            "7) Small round purple bottle";
    potions.correct_answer = 3;
    potions.correct_response = "You drink the potion and step through the black flames and successfully reach the final door.";
    Harry_Potter[4] = potions;
    HP_Chamber quirrell;
    quirrell.name = "The Final Chamber";
    quirrell.question = "'You!' 'Me. I wondered whether I'd be meeting you here.' Standing in front of the Mirror of Erised is not Snape, but none other than Brett, the TA! Bret can't seem to get the stone from the Mirror, he tells you to look in the Mirror."
            "What do you see when you look at your reflection?"
            "1) You're handing the stone to Dumbledore"
            "2) You use the stone's power of eternal life to fight Voldemort"
            "3) You are using the stone to bring back Harry Potter's parents";
    quirrell.correct_answer = 1;
    quirrell.correct_response = "Congratulations, the stone is in your pocket! Only someone who wanted to find the stone, find it and not use it- would be able to get it. "
            "Bret of course comes after you for the stone, but the magic of love in your hands effectively turns him to stone and he crumbles away freeing the evil wizard attached to the back of his head (wait, what?)"
            "With the stone safe and sound, Dumbledore rewards you with a piece of the code you need.";
    Harry_Potter[5]= quirrell;

    // Constructing the Hunger Games

    HG_Situation cornucopia;
    cornucopia.scenario = "BANG! The 76th Annual Hunger Games have begun! Most of the weapons and supplies are concentrated in the Cornucopia with some backpacks and weapons scattered throughout the rest of the clearing. A lake lies to the left of the Conucopia and there's forest behind you. "
            "What's your plan?"
            "1) Charge the Cornucopia to secure resources and find allies"
            "2) Run to the nearest weapon, kill anyone within reach"
            "3) Grab the nearest backpack and run"
            "4) Run without approaching the Cornucopia";
    cornucopia.score1 = -3;
    cornucopia.score2 = -1;
    cornucopia.score3 = 1;
    cornucopia.score4 = 0;
    Hunger_Games[0] = cornucopia;

    HG_Situation dehydration;
    dehydration.scenario = "You're in the forest miles from the Cornucopia. You are hungry and in desperate need of water. You passed a small spring with a tent near it a mile back."
            "How do you proceed?"
            "1) Keep moving into the forest, there will probably be another spring"
            "2) Ask your sponsors for water"
            "3) Turn around and try to kill the tribute in the tent"
            "4) Follow animals who will hopefully lead you to water";
    dehydration.score1 = -1;
    dehydration.score2 = -2;
    dehydration.score3 = -1;
    dehydration.score4 = 1;
    Hunger_Games[1] = dehydration;

    HG_Situation weapons;
    weapons.scenario = "You spot an unoccupied camp site. From your hiding place you can see a trident, an axe, a coil of wire, and a bow and arrow. "
            "You only have time to grab one, which do you choose?"
            "1) The Trident"
            "2) The Axe"
            "3) The Wire"
            "4) The Bow";
    weapons.score1 = 1;
    weapons.score2 = 1;
    weapons.score3 = 1;
    weapons.score4 = 1;
    Hunger_Games[2] = weapons;

    HG_Situation fight_or_flight;
    fight_or_flight.scenario = "You've made your way back to the Cornucopia looking to snag some food. The district 4 Career spots you and is charging towards you."
            "What do you do?"
            "1) Run towards the nearest tree and start climbing"
            "2) Head for the lake, district 4 tributes usually can't swim"
            "3) Pull out your weapon and brace for battle"
            "4) Ask to be allies";
    fight_or_flight.score1 = 1;
    fight_or_flight.score2 = -3;
    fight_or_flight.score3 = -1;
    fight_or_flight.score4 = -1;
    Hunger_Games[3] = fight_or_flight;

    HG_Situation night;
    night.scenario = "Night has fallen and the temperature has dropped. From the cave you've found to sleep in you spot the light of a fire a few hundred yards away."
            "You're freezing cold, what do you do?"
            "1) Ask the tribute to be allies to share the fire's warmth"
            "2) Kill the tribute to use the fire for yourself"
            "3) Try to build your own fire"
            "4) Suck it up and cover yourself in more pine needles";
    night.score1 = -3;
    night.score2 = -3;
    night.score3 = -2;
    night.score4 = 1;
    Hunger_Games[4] = night;

    HG_Situation finale;
    finale.scenario = "The 76th Hunger Games are coming to a close. You and the boy from district 2 are the only ones left. "
            "To claim the victor's crown you must face him in the final battle. What is your strategy?"
            "1) Set various traps and snares throughout the arena and wait till he falls into one to attack"
            "2) Take the straight up approach and face him head on"
            "3) Trick him into eating poisonous berries"
            "4) Set up a diversion, use the element of surprise to take the upper hand";
    finale.score1 = 1;
    finale.score2 = -3;
    finale.score3 = -1;
    finale.score4 = 1;
    Hunger_Games[5] = finale;

    string user_command;
    Character user;
    string user_district;
    string user_age;

    cout <<"Help! Professor Hoenigman has built a super computer to open portals to the top Nerd Fandoms. She has sent her minions out to invade their Kingdoms and wreak havoc on the Nerd Universe. Your mission, should you choose to accept it, is to enter each of the worlds and complete a quest to restore order." << endl;

    while (true) {
        cout << "5 doors each emblazed with a different symbol are before you. Pick one to enter:" << endl;
        cout << "1. Lightning bolt" << endl;
        cout << "2. A bird taking flight" << endl;
        cout << "3. Two towers" << endl;
        cout << "4. A moon" << endl;
        cout << "5. A pokeball" << endl;
        cout << "6. Refuse the quest" << endl;
        getline(cin, user_command);

        switch (stoi(user_command)) {
            case 1:
            {
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
                break;
            }
            case 2:
            {
                cout << "Pick a number between 1 and 12" << endl;
                getline(cin, user_district);
                cout << "Pick a number between 12 and 18" << endl;
                getline(cin, user_age);

                HG_Situation currentScenario;
                string user_answer;
                for(int i = 0; i < 6; i++) {
                    currentScenario = Hunger_Games[i];
                    cout << currentScenario.scenario << endl;
                    getline(cin, user_answer);

                }
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
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
