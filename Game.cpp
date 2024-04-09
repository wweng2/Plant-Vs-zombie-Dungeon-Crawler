/*
File: Game.cpp
Project: CMSC 202 Project 4, FAll 2020
Author: Wei zhang weng
Date: 11/10/2020
Section: 10
Email: wweng2@umbc.edu

This file contain the function impetation of the function in the Game class,which allows the user to create a full game of plants vs zombie where you crawl through rooms and right zombie
*/

#include "Game.h"

Game::Game(){
  string filename;
  cout<<"Please enter in a map to play with: "<<endl;
  cin >> filename;
  LoadMap(filename);// Load the map of room into an vector of rooms
  PlantCreation();// Create the plant for the user to use
  m_numRests = NUM_RESTS;// Set the number of rest the user have to a const
  m_numSpecial = NUM_SPECIAL;// Set the number of special attack the user can use to a const
  m_curZombie = nullptr;
  StartGame();
  
}
Game::Game(string filename){
  m_numRests = NUM_RESTS;// Set the number of rest the user have to a const
  m_numSpecial = NUM_SPECIAL;// Set the number of special attack the user can use to a const
  m_curZombie = nullptr;// Set curZombie to nullptr to show that it's empty
  LoadMap(filename);
  PlantCreation();
  StartGame();
}

Game::~Game(){
  delete m_myPlant;
  m_myPlant = nullptr;// delete myPlant and free ups room and set it to nullptr for security reasons
  if(m_curZombie != nullptr){
    delete m_curZombie;
    m_curZombie = nullptr;
  }
  for(unsigned int i = 0; i < m_myMap.size();i++){
    delete m_myMap.at(i);// Loops though the entire and deletes each room
  }
  
}

void Game::LoadMap(string filename){
  string ID;
  string name;
  string Desc;
  string north;
  string east;
  string south;
  string west;
  ifstream myfile(filename);

  if(myfile.is_open()){
    while(getline(myfile,ID,'|')&&
      getline(myfile,name,'|')&&
      getline(myfile,Desc,'|')&&
      getline(myfile,north,'|')&&
      getline(myfile,east,'|')&&
      getline(myfile,south,'|')&&
      getline(myfile,west)){
      
      Room *room = new Room(stoi(ID),name,Desc,stoi(north),stoi(east),stoi(south),stoi(west));// Creates a dynamically allocalted room that is push into the m_myMap vector
      m_myMap.push_back(room);
    }
  }
  else{
    cout<<"unable to open file: please try again."<<endl;
}
}

void Game::PlantCreation(){
  string name;
  int choice = 5;
  cout<<"Plant Name: "<<endl;
  cin >> name;

  while( choice > 4){
    
    cout<<"Select a class"<<endl;
    cout<<"1. Peashooter "<<endl;
    cout<<"2. Chomper "<<endl;
    cout<<"3. Sunflower "<<endl;
    cout<<"4. No Class"<<endl;
  
    cin >> choice;// Selecting the plant to use the class that will be dynamically called
  }
  
    if(choice == 1){
      Peashooter * peashooter = new Peashooter(name,PEASHOOTER_HEALTH);// Creastes a new peashooter that will the character for the user to play with
      m_myPlant = peashooter;
    }
    
    else if(choice == 2){
      Chomper *chomper = new Chomper(name,CHOMPER_HEALTH);
      m_myPlant = chomper;
    }
    
    else if(choice == 3){
      Sunflower * sunflower = new Sunflower(name,SUNFLOWER_HEALTH);
      m_myPlant = sunflower;// Set the m_myPlant to sunflower a create dynamic object
  }
    else if (choice == 4){
      Plant* plant = new Plant(name,PLANT_HEALTH);
      m_myPlant = plant;
    }
    else{
      cout<<"Please input an valid number"<<endl;
    }

}

void Game::StartGame(){
  m_curRoom = START_ROOM;// Set curRoom to the start room which is 0
  Action();
  }

void Game::Action(){
  int choice = 0;
  int chance = rand() % 4 + 1;
  
  Room* currRoom = m_myMap[m_curRoom];

  currRoom->PrintRoom();
  

  if(chance < 4){
    m_curZombie = RandomZombie();// m_curZombie will be set to the zombie
  }
  else{
    cout<<"This is peaceful "<<endl;
  }

  while(choice != 6 && m_myPlant->GetHealth() > 0){// Until the plant dies or the user quit this game will keep running
 
    cout<<"1.Look"<<endl;
    cout<<"2.Move"<<endl;
    cout<<"3.Attack Zombie"<<endl;
    cout<<"4.Rest"<<endl;
    cout<<"5.Check stats"<<endl;
    cout<<"6.Quit"<<endl;

    cin >> choice;
    
    if (choice == 1){
      currRoom->PrintRoom();

    }
    else if (choice == 2){
      Move();
    }
    else if (choice == 3){
      Attack();
    }
    else if (choice == 4){
      Rest();
    }
    else if (choice == 5){
      Stats();
    }
    else if (choice == 6){// When it choose it will display good bye than quiz , to prevent werid problem when the user press 6
      cout<<"Good bye"<<endl;
    }
    else{// Input validation
      cout<<"Please insert an valid number please"<<endl;
  }

 
  }
 
}

Entity* Game::RandomZombie(){
  int ZombieNumber = rand() % 3 + 1;// A number to decide which zombie to show up

  if(ZombieNumber == 1){
    cout<<"A buckethead zombie teaters here with a bucket on his head. "<<endl;
    Buckethead* buckethead = new Buckethead("Buckethead",BUCKETHEAD_HEALTH);
    return buckethead;// Return the zombie object that will be store in m_curZombie
  }
  
  else if(ZombieNumber == 2){
    cout<<"A dirty imp licks his lips and glares at you. "<<endl;
    Imp* imp = new Imp("Imp",IMP_HEALTH);
    return imp;
  }
  else if (ZombieNumber == 3){
    cout<<"A large zombie stands here wearing khakis with a sign that says ENGINEER. "<<endl;
    Engineer* engineer = new Engineer("Engineer",ENGINEER_HEALTH);// Creates dyannically allocated zombie
    return engineer;
  }
  else{
    return nullptr;
  }
 
}

void Game::Rest(){
  
  if (m_curZombie == nullptr){// If there is no zombie in the room
    if(m_numRests > 0){// And if the user still have number of rests
      int currhealth = m_myPlant->GetHealth();

      m_myPlant->SetHealth(currhealth + REST_HEAL);// Retores it by 10
      cout<<"You woke up rested and healed"<<endl;
    }
    else if (m_numRests < 1){
      cout<<"Sorry, you ran out of rests you can't heal"<<endl;
    }
    
  }
  else if (m_curZombie != nullptr){
    cout<<"There is still a zombie in here please take care of that first than you can rest"<<endl;
    }
}

void Game::Move(){
  char direction = 'z';
  Room* currRoom = m_myMap[m_curRoom];
 
  int chance = rand() % 4 + 1;
  while (direction != 'N' && direction != 'n' && direction != 'E' && direction != 'e' && direction != 'S' && direction != 's' && direction != 'W' && direction != 'w'){
  cout<<"Which direction? (N E S W)"<<endl;
  
  cin >> direction;
   }
   
  int check = currRoom->CheckDirection(direction);


  if(check != -1){
    m_curRoom = check;
    if(m_curZombie != nullptr){
      delete m_curZombie;// Get rid of the zombie that exist in the old room
      m_curZombie = nullptr;
    }
    currRoom = m_myMap[m_curRoom];// Update curr room to the one that it just move to
    currRoom->PrintRoom();

    if (chance < 4){
    m_curZombie = RandomZombie();
    }
    else{
      cout<<"Today is peaceful"<<endl;
      m_curZombie = nullptr;
    }
  }
 
 
  else{
    cout<<"There is no exit this way please choose another way"<<endl;

  }  
  
  }

void Game::Attack(){
  int attackChoice;
  int playerHealth = m_myPlant->GetHealth();
  int ZombieHealth = m_curZombie->GetHealth(); 
  int damage;
  int attack;
  if(m_curZombie != nullptr){
    while(ZombieHealth > 0 && playerHealth > 0){// Until either the zombie or plant die this will not stop
    
      cout<<"1. Normal Attack"<<endl;
      cout<<"2. Special Attack"<<endl;
      cin >> attackChoice;
      if(attackChoice == 1){
	damage = m_myPlant->Attack();// The daamge that will be deelt to the zombie
	ZombieHealth -= damage;
	
	if(ZombieHealth > 0 ){// If the zombie still haven't die ye
	  attack = rand() % 2 + 1;// Randomly choose to see if it will attack or use a specail attack
	
	  if(attack == 1){
	    damage = m_curZombie->Attack();

	    playerHealth -= damage;
	    
	  }
	  else if(attack == 2){
	    damage = m_curZombie->SpecialAttack();// This will deal damge based on the zombie's specail attack

	    playerHealth -= damage;
	    
	    
	  }
	}
	
      }
      else if(attackChoice == 2){
	
	if(m_numSpecial > 0){
	damage = m_myPlant->SpecialAttack();// Uses the specail attack of the plant
       	m_numSpecial -= 1;// Decrease the amount of specail the user have left to use

	ZombieHealth -= damage;

	if(ZombieHealth > 0 ){// If the zombie still haven't die ye
	  attack = rand() % 2 + 1;// Randomly choose to see if it will attack or use a specail attack
	
	  if(attack == 1){
	    damage = m_curZombie->Attack();
	    playerHealth -= damage;
	    
	  }
	  else if(attack == 2){
	    damage = m_curZombie->SpecialAttack();// This will deal damge based on the zombie's specail attack
	    playerHealth -= damage;
	    
	  }
	}
	}
	else if (m_numSpecial < 1){
	  cout<<"You don't have enough specail attacks left to use"<<endl;
      }
      }
      else{
	cout<<"Please enter an valid number"<<endl;
      }
           
      cout<<m_myPlant->GetName()<<" 's health : "<<playerHealth<<endl; 
      cout<<m_curZombie->GetName()<<" 's health: "<<ZombieHealth<<endl;
    }
    
   
  }
  else if (m_curZombie == nullptr){// If there is no zombie than , tell the user there is nothing to fight
    cout<<"There is no zombie in this room, please stop trying to attack at the air"<<endl;

  }

  if(playerHealth < 1){// If the user lost than show that
    cout<<"Sorry, you have lost and die , the game ends"<<endl;
    m_myPlant->SetHealth(playerHealth);
  }
  else if (ZombieHealth < 1){// If the zombie lost it will delte the zombie and display that it died
    cout<<"Congrats you have defeated the "<<m_curZombie->GetName()<<endl;
      delete m_curZombie;
      m_curZombie = nullptr;
      m_myPlant->SetHealth(playerHealth);
	  
      
  }
}
void Game::Stats(){//Display the stats the person has
   cout<<"Name: "<<m_myPlant->GetName()<<endl;
   cout<<"Health: "<<m_myPlant->GetHealth()<<endl;
   cout<<"Rests left: "<<m_numRests<<endl;
   cout<<"Specials left: "<<m_numSpecial<<endl;
  }

