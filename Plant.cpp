/*
File: Plant.cpp
Project: CMSC 202 Project 4, FAll 2020
Author: Wei zhang weng
Date: 11/10/2020
Section: 10
Email: wweng2@umbc.edu

This file contain the function impetation of the function in the plant class, to create a plant object with it's health and name
*/

#include "Plant.h"

Plant::Plant(): Entity("Plant",1){
  // Set the plant to use the entity contrutor to make the plan with a default name and 1 hp as default
}

Plant::Plant(string name , int health): Entity(name,health){// Set useing the plant name and health parameter into the entity contrutor to mmake a plant object
}

Plant::~Plant(){
  // Nothing since nothing in here is dynammically 
  }

int Plant::Attack(){
  int damage = rand() % 6 + 1;
  
  cout<<GetName()<<" attacks dealing "<<damage<<" damage!"<<endl;
  return damage;
}

int Plant::SpecialAttack(){
  cout<<"Plant does not have a special attack"<<endl;// No special attack and return 0 to show that
  return 0;
}
