/*
CSCI 2270 Quest
* Connor Fitzgerald and Sonia Szeton
*/

#include <iostream>
#include <string>
using namespace std;

struct Player{                                                          //player struct, should be a class, not gonna try to mess with that right now
	string name;                                                        //lots of different attributes, general ones like name, difficulty and strength
	string mon;                                                         //world specific ones like mon(pokemon), rival mon, weapon(LotR)
	string rival_mon;
	string weapon;
	int str;
	int difficulty;
	bool poke_complete;                                                 //bools to determine if you've finished a world or not
	bool lotr_complete;
};

Player *player = new Player;


void FinalBoss(){                                                       //what's gonna happen here? I don't even know
	
	cout<<endl;
	cout<<"You've beaten all the levels, now it's time for the final boss!"<<endl;
	cout<< endl;
	cout<<"Congrats on making it this far. I honestly have no idea what's going to happen next."<<endl;
	cout<<endl;
}

void choose_pokemon(){                                                  //function for choosing pokemon
	cout<<endl;
	cout<<"Which will you choose?"<<endl;
	cout<<"1. Bulbasaur"<<endl;
	cout<<"2. Charmander"<<endl;
	cout<<"3. Squirtle"<<endl;
	
	int poke_choice;
	cin>>poke_choice;
	
	if (poke_choice == 1){                                              //input sets player->mon to your selection and player->rival_mon based on your selection
		player->mon = "Bulbasaur";
		player->rival_mon = "Charmander";
	}
	
	else if (poke_choice == 2){
		player->mon = "Charmander";
		player->rival_mon = "Squirtle";
	}
	
	else if (poke_choice == 3){
		player->mon = "Squirtle";
		player->rival_mon = "Bulbasaur";
	}
	
	else{
		cout<<"Invalid selection."<<endl;
		choose_pokemon();
	}
	
	cout<<endl;
	cout<<"You now have a Pokemon!"<<endl;
	
	if (player->difficulty != 94){                                      //updating player strength, unless you're in god mode 
		player->str = player->str+(40-10*(player->difficulty-1));       //player strength increased by 10, 20, 30, or 40, depending on difficulty
		cout<<"Your strength has increased by "<<(40-10*(player->difficulty-1))<<" to "<<player->str<<"!"<<endl;
	}
	
	else{
		
	}
}

void pokemon_evolve(){                                                  //function for if your pokemon evolves (you have to win a battle for that)
	
	cout<<endl;
	cout<<"What? Your "<<player->mon<<" is evolving!"<<endl;            //What? Text from the games!
	if (player->mon == "Bulbasaur"){
		player->mon = "Ivysaur";                                        //pokemon evolves depending on what pokemon you have (duh)
		cout<<"Your Bulbasaur has evolved into Ivysaur!"<<endl;
	}
	else if (player->mon == "Charmander"){
		player->mon = "Charmeleon";
		cout<<"Your Charmander has evolved into Charmeleon!"<<endl;
	}
	else if (player->mon == "Squirtle"){
		player->mon = "Wartortle";
		cout<<"Your Squirtle has evovled into Wartortle!"<<endl;
	}
	else if (player->mon == "Ivysaur"){
		player->mon = "Venusaur";
		cout<<"Your Ivysaur has evolved into Venusaur!"<<endl;
	}
	else if (player->mon == "Charmeleon"){
		player->mon = "Charizard";
		cout<<"Your Charmeleon has evolved into Charizard!"<<endl;
	}
	else if (player->mon == "Wartortle"){
		player->mon = "Blastoise";
		cout<<"Your Wartortle has evolved into Blastoise!"<<endl;
	}
		
	if (player->difficulty != 94){                                      //updating player strength, unless your in god mode
		player->str = player->str+(20-5*(player->difficulty-1));        //strength increases by 5, 10, 15, or 20, depending on difficulty
		cout<<"Your strength has increased by "<<(20-5*(player->difficulty-1))<<" to "<<player->str<<"!"<<endl;
	}
	
	else{
		
	}
}

void AshBattle(){                                                       //function for the Ash battle encounter
	
	cout<<endl;
	cout<<"What move will "<<player->mon<<" use?"<<endl;                //select a move
	cout<<"1. Spark- Electric type"<<endl;
	cout<<"2. Mud Bomb- Ground type"<<endl;
	cout<<"3. Tackle- Normal type"<<endl;
	
	if (player->mon == "Bulbasaur"){                                    //specific moves for each mon (they all do the same thing though)
		cout<<"4. Vine Whip- Grass type"<<endl;
	}
	else if (player->mon == "Charmander"){
		cout<<"4. Ember- Fire type"<<endl;
	}
	else if (player->mon == "Squirtle"){
		cout<<"4. Water Gun- Water type"<<endl;
	}
	
	int move_choice;
	cin>>move_choice;
	
	if (move_choice == 1){                                              //auto lose move
		cout<<"Your move was not very effective! Pikachu countered with Volt Tackle, his signature move, and your "<<player->mon<<" was knocked out in one hit!"<<endl;
	}
	else if (move_choice == 2){                                         //auto win move
		cout<<"Your move was super effective! Pikachu was knocked out in one hit!"<<endl;
		pokemon_evolve();                                               //if you win, your pokemon evolves
	}
	else if (move_choice == 3){                                         //this move has different results, depending on player strength
		if (player->str > 75){                                          //if your strength is above 75, it's a tie, and nothing happens
			cout<<"Pikachu used Tackle as well, it's a stalemate!"<<endl;
			AshBattle();                                                //start the battle over!
		}
		else{                                                           //if your strength isn't high enough, you lose!
			cout<<"Your move wasn't very strong, Pikachu coutered with Spark and "<<player->mon<<" was knocked out in one hit!"<<endl;
		}
	}
	else if (move_choice == 4){                                         //more different results
		if (player->str > 75){                                          //if your strength is above 75, you win!
			cout<<"Critical hit! Pikachu was knocked out in one hit!"<<endl;
			pokemon_evolve();                                           //and your pokemon evolves
		}
		else{                                                           //if your strength is below 75, it's a tie
			cout<<"Your move wasn't very strong. Pikachu countered with Spark! It's a stalemate!"<<endl;
			AshBattle();                                                //start the batle over
		}
	}
	else{
		cout<<"Invalid Selection."<<endl;                               //if you push the wrong button, you get yelled at
		AshBattle();
	}
}

void RivalBattle(){                                                     //the function for the rival battle (harder)
	
	cout<<endl;
	cout<<"What move will "<<player->mon<<" use?"<<endl;                //pick your move!
	cout<<"1. Tackle- Normal type"<<endl;
	
	if (player->mon == "Bulbasaur" || player->mon == "Ivysaur"){        //the same moves for all three mons, but in different orders
		cout<<"2. Vine Whip- Grass type"<<endl;                         //each one does something different, depending on which mon you and your rival have
		cout<<"3. Ember- Fire type"<<endl;                              //what each move does depends on where it is in the list
		cout<<"4. Water Gun- Water type"<<endl;
	}
	else if (player->mon == "Charmander" || player->mon == "Charmeleon"){
		cout<<"2. Ember- Fire type"<<endl;
		cout<<"3. Water Gun- Water type"<<endl;
		cout<<"4. Vine Whip- Grass type"<<endl;
	}
	else if (player->mon == "Squirtle" || player->mon == "Wartortle"){
		cout<<"2. Water Gun- Water type"<<endl;
		cout<<"3. Vine Whip- Grass type"<<endl;
		cout<<"4. Ember- Fire type"<<endl;
	}
	int move_choice;
	cin>>move_choice;
	
	if (move_choice == 1){                                              //move 1 (tackle) has different outcomes
		if (player->str > 75){                                          //if your strength is above 75 its a tie
			cout<<player->rival_mon<<" used Tackle as well, it's a stalemate!"<<endl;
			RivalBattle();                                              //start over
		}
		else{                                                           //if your strength is below 75, you lose
			cout<<"Your move wasn't very strong, "<<player->rival_mon<<" coutered with Tackle and got a critical hit! "<<player->mon<<" was knocked out in one hit!"<<endl;
		}
	}
	
	else if (move_choice == 3){                                         //move 3 (I decided to switch 2 and 3) has a type that's not very effective against rivals mon
		if (player->str > 100){                                         //if your strength is above 100 its a tie
			cout<<"Your move wasn't very effective, it's a stalemate!"<<endl;
			RivalBattle();                                              //start over
		}
		else{                                                           //if your strength is below 100 you lose (I told you it was harder)
			cout<<"Your move wasn't very effective, "<<player->rival_mon<<" coutered and "<<player->mon<<" was knocked out in one hit!"<<endl;
		}
	}
	else if (move_choice == 2){                                         //move 2 is also ineffective
		if (player->str > 100){                                         //however a strength over 100 lands you a critical hit and the win
			cout<<"Critical hit! "<<player->rival_mon<<" was knocked out in one hit!"<<endl;
			pokemon_evolve();                                           //and your pokemon evolves
		}
		else{                                                           //a strength below 100 resuls in a tie
			cout<<"Your move wasn't very effective, it's a stalemate!"<<endl;
			RivalBattle();                                              //start over
		}
	}
	else if (move_choice == 4){                                         //move 4 is super effective and nets you the auto win
		cout<<"Your move was super effective! "<<player->rival_mon<<" was knocked out in one hit!"<<endl;
		pokemon_evolve();                                               //and your pokemon evolves as a result
	}
	else{                                                               //please choose a number between 1 and 4
		cout<<"Invalid Selection."<<endl;
		RivalBattle();
	}
	
}

void Pokemon(){                                                         //the story and framework for the pokemon world
	cout<<endl;                                                         //it has cout statements and calls other functions
	cout<<"You find yourself in a laboratory. Unfamiliar machines whir and buzz around you, and you see an elderly man in a labcoat and a boy of about 10 years across the room, discucssing something excitedly. "<<endl;
	cout<<"They notice you and turn, and you see that the boy has a giant yellow mouse in his arms."<<endl;
	cout<<"'Ah, "<<player->name<<" it's you!' The professor exclaims. 'I almost thought you wouldn't make it. Come, have a look. It's your turn to choose.'"<<endl;
	cout<<"He gestures to a table behind him, where three more of the terrifying creatures sit:"<<endl;
	cout<<"A green animal with a flower bud on its back, labeled 'Bulbasaur',"<<endl;
	cout<<"a large orange lizard with a flame on the end of its tail, labeled 'Charmander',"<<endl;
	cout<<"and some kind of cross between a squirrel and a turtle. labeled 'Squirtle'."<<endl;
	
	choose_pokemon();
	
	cout<<endl;
	cout<<"'Wow! A "<<player->mon<<"! That's so cool!' Says the boy with the yellow mouse. 'This is my Pikachu! And I'm Ash Ketchum!' He exclaims proudly."<<endl;
	cout<<"'So, Professor Oak is giving you a Pokemon too! That's great!'"<<endl;
	cout<<"'We should have a battle!'"<<endl;
	cout<<"You send out your brand new "<<player->mon<<", and Ash sends out his Pikachu."<<endl;
	
	AshBattle();
	
	cout<<endl;
	cout<<"'That was a fun battle!' Ash exclaims."<<endl;
	cout<<"The door opens behind you and TA Gary walks in. Ash has an angry look on his face. 'Oh no,' he mutters, 'it's my rival, TA Gary!'"<<endl;
	cout<<"'Oh good, now you're all here!' Says Professor Oak. 'Why don't you choose a Pokemon, TA Gary'"<<endl;
	cout<<"'I'll take whatever is super-effective against "<<player->name<<"'s Pokemon, because that's just the type of guy I am,' says TA Gary."<<endl;
	cout<<"'Alright then, here's your "<<player->rival_mon<<",' says Professor Oak, handing him the "<<player->rival_mon<<"."<<endl;
	cout<<"Now let's battle, "<<player->name<<"!"<<endl;
	cout<<"You send out your "<<player->mon<<", and TA Gary sends out his "<<player->rival_mon<<endl;
	
	RivalBattle();
	
	cout<<endl;
	cout<<"'Wow, another great battle!' Says Ash."<<endl;
	cout<<"With your new "<<player->mon<<" as a companion, you feel ready to take on more adventures."<<endl;
	cout<<"You say goodbye to TA Gary, Professor Oak, and Ash, and leave the laboratory."<<endl;
	
	player->poke_complete = true;                                       //after completing this story, this bool is set to true, so you can never come back
}

void lotr_FrontLines(){                                                 //different functions for different branches of the story
	cout<<"Front lines"<<endl;                                          //Aragorn is here. if you have a spear the battle goes well and he rewards you
}                                                                       //if you don't have a spear, a high strength can still save you

void lotr_InnerKeep(){
	cout<<"Inner keep"<<endl;                                           //Gimli is here, a sword would help
}

void lotr_CastleWalls(){
	cout<<"Castle walls"<<endl;                                         //Legolas, bow
}

void choose_weapon(){
	
	cout<<endl;
	cout<<"Which weapon will you choose?"<<endl;                        //choose your weapon, it will be important later
	cout<<"1. Spear"<<endl;
	cout<<"2. Sword"<<endl;
	cout<<"3. Bow"<<endl;
	
	int weapon_choice;
	cin>>weapon_choice;
	
	if (weapon_choice == 1){
		player->weapon = "Spear";
	}
	else if (weapon_choice == 2){
		player->weapon = "Sword";
	}
	else if (weapon_choice == 3){
		player->weapon = "Bow";
	}
	else {
		cout<<"Invalid selection."<<endl;
		choose_weapon();
	}
	
	cout<<"You now have a "<<player->weapon<<". ";
	if (player->difficulty != 94){                                      //a weapon icreases your strength, unless you're in god mode
		player->str = player->str+(40-10*(player->difficulty-1));       //by 10, 20, 30, or 40, depending on difficulty
		cout<<"Your strength has increased by "<<(40-10*(player->difficulty-1))<<" to "<<player->str<<"."<<endl;
	}
	
	else{
		
	}
}

void choose_station(){                                                  //choose your station
	
	cout<<endl;
	cout<<"So, what'll it be?"<<endl;                                   //I hope I made the descriptions easy enough to tell where you should go with which weapon
	cout<<"1. Front Lines"<<endl;
	cout<<"2. Inner Keep"<<endl;
	cout<<"3. Castle Walls"<<endl;
	
	int station_choice;
	cin>>station_choice;
	
	if (station_choice == 1){
		lotr_FrontLines();
	}
	else if (station_choice == 2){
		lotr_InnerKeep();
	}
	else if (station_choice == 3){
		lotr_CastleWalls();
	}
	else{
		cout<<"Invalid Selection."<<endl;
		choose_station();
	}
}

void LotR(){                                                            //Lord of the Rings story and structure
	                                                                    //print statements and function calls
	cout<<endl;
	cout<<"This door leads you to a great stone keep. Men in armor with swords, bows, and lances hurry to and fro all around you. It seems like they are preparing for a battle."<<endl;
	cout<<"One of the shortest, stoutest men you've ever seen approaches you. He has a thick red beard and a huge double sided batle axe, as tall as he is."<<endl;
	cout<<"'Come on, quit standing around gawking!' He bellows at you. 'We need all able bodied citizens preparing to defend Helm's Deep against the Urukhai!'"<<endl;
	cout<<"A tall, slender, fair-skinned man strolls up beside the first. An elegant bow is strapped across his back."<<endl;
	cout<<"'For once, I agree with the dwarf,' he states. 'Who are you? I've never seen you before.'"<<endl;
	cout<<"'Please excuse the behavior of my companions,' says a strong, dark-haired man as he approaches. You feel a sense of power coming from this thrid man."<<endl;
	cout<<"'This is "<<player->name<<",' he says, gesturing to you. '"<<player->name<<" has been sent to aide us in the battle that lies before us.'"<<endl;
	cout<<"'These two are Legolas the elf,' he says, pointing to the tall, fair man, 'and Gimli the dwarf,' pointing to the short man with the beard.'"<<endl;
	cout<<"'And I am Aragorn, son of Arathorn,' he states. 'And you had best get to the armory to find yourself a weapon.'"<<endl;
	
	cout<<endl;
	cout<<"He directs you to the armory. The smiths outfit you with adequate armor. Then they point to the weapon racks, and ask what kind of weapon you prefer."<<endl;
	cout<<"There are spears, almost as tall as you are, heavy, and with deadly points on the ends,"<<endl;
	cout<<"there are swords, with sharp blades, that feel light and maneuverable in your hand,"<<endl;
	cout<<"and there are bows, with quivers of arrows, deadly from a distance, but nearly useless up close."<<endl;
	
	choose_weapon();
	
	cout<<endl;
	cout<<"'Ah, the "<<player->weapon<<" , an excellent choice,' says a man behind you, dressed in glistening gold and green armor, with a golden horse across his chest."<<endl;
	cout<<"'I am Theoden, king of Rohan,' he says, 'and king of this keep. I don't intend to lose it tonight, but I'll need your help for that."<<endl;
	cout<<"'I'll let you choose your own station, where you think you'll be of most use to us, based on your own skills,' he says."<<endl;
	cout<<"'We need strong, fearless soldiers on the front lines, ready to hold off waves of enemies,"<<endl;
	cout<<"'we need quick, reactive men ready for anything in the inner keep, in case the enemy breaks through anywhere,"<<endl;
	cout<<"'and last, we need the staunchest defenders on the castle walls, keeping a watchful eye over the battle."<<endl;
	
	choose_station();
	
	player->lotr_complete = true;                                       //you did it! set completion bools to true!
}

void view_stats(){                                                      //a fun little tool I made to see your players stats
	cout<<endl;                                                         //you can select it from the world select menu
	cout<<"Name: "<<player->name<<endl;                                 //it shows you your name,
	cout<<"Difficulty: ";                                               //difficulty
	switch (player->difficulty){
		case 1:
			cout<<"Easy"<<endl;
			break;
		case 2:
			cout<<"Normal"<<endl;
			break;
		case 3:
			cout<<"Hard"<<endl;
			break;
		case 4:
			cout<<"Insane"<<endl;
			break;
		case 94 :
			cout<<"God Mode"<<endl;
			break;
	}
	cout<<"Strength: "<<player->str<<endl;                              //current strength (very handy)
	cout<<"Other:"<<endl;                                               //other section for world specific items
	if (player->poke_complete){                                         //it tells you what your pokemon is, but only if you have completed that world
		cout<<"    Pokemon: "<<player->mon<<endl;
	}
	cout<<endl;                                                         //there will probably be something for every world, but I don't know what those are yet
	cout<<"Levels completed:"<<endl;                                    //it gives you a list of the worlds you've completed as well
	if (player->poke_complete){
		cout<<"    Pokemon"<<endl;
	}
	if (player->lotr_complete){
		cout<<"    Lord of the Rings"<<endl;
	}
}

void worlds(){                                                          //the world selection menu
	
	if (player->poke_complete && player->lotr_complete){                //if you've beaten all the levels
		FinalBoss();                                                    //it takes you right to the Final Boss level
		cout<<"Final Report:"<<endl;                                    //then it shows you your final stats
		view_stats();
		return;
	}
	
	int door_select;
	
	cout<<endl;                                                         //now we pick a door
	cout<<"Which door would you like to go through?"<<endl;
	cout<<"1. Pokemon"<<endl;
	cout<<"2. Lord of the Rings"<<endl;
	cout<<"0. View player stats."<<endl;
	
	cin>>door_select;
	
	if (door_select == 1){                                              //what's behind door 1? It's pokemon!
		if (player->poke_complete){                                     //if you've already completed a world, you can't do it again
			cout<<endl;
			cout<<"You've already completed this world!"<<endl;
		}
		else{
			Pokemon();                                                  //if you haven't though, it sends you off on your next adventure
		}
	}
	
	else if (door_select == 2){                                         //door 2: Lord of the Rings
		if (player->lotr_complete){
			cout<<endl;
			cout<<"You've already completed this world!"<<endl;
		}
		else{
			LotR();
		}
	}
	
	else if (door_select == 0){                                         //door 0 is how you view your stats
		view_stats();
	}
	
	else{
		cout<<"Invalid selection."<<endl;                               //try to stick to the script
	}
	
	worlds();
}

void choose_difficulty(){                                               //function for selecting your difficulty
	int diff_select;
	cout<<endl;
	cout<<"Select a difficulty:"<<endl;                                 //difficulty changes how much strength you gain from certain accomplishments throughout the game
	cout<<"1. Easy"<<endl;                                              //it does not affect your starting strength, or how much strength your enemies have
	cout<<"2. Normal"<<endl;
	cout<<"3. Hard"<<endl;
	cout<<"4. Insane"<<endl;
	
	cin>>diff_select;
	player->difficulty = diff_select;
	
	if (player->difficulty != 94){
		player->str = 50;                                               //it starts you with a strength of 50...
	}
	
	else if (player->difficulty == 94){                                 //unless you enter the hidden cheat code!
		player->str = 1000000;                                          //entering '94' at the difficulty menu activates God Mode, giving you a strength of 1000000, which can't be changed
		cout<<"God Mode activated."<<endl;
	}
	
	else{
		cout<<"Invalid selection."<<endl;
		choose_difficulty();
	}
}

int main(){                                                             //main acts as an initializer
	
	player->poke_complete = false;                                      //start by initializing our world bools
	player->lotr_complete = false;
	
	cout<<"Welcome, player! You are about to embark on a journey!"<<endl;
	cout<<endl;
	
	string player_name;                                                 //enter your name
	cout<<"Please enter your name:"<<endl;
	cin>>player_name;
	player->name = player_name;
	
	cout<<"Thank you, "<<player->name<<"!"<<endl;
	
	choose_difficulty();                                                //choose your difficulty
	
	worlds();                                                           //and now your off on your grand adventure
	
	return 0;
}
