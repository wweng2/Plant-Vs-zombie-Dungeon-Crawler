/*
File: Engineer.cpp
Project: CMSC 202 Project 4, FAll 2020
Author: Wei zhang weng
Date: 11/10/2020
Section: 10
Email: wweng2@umbc.edu

This file contain the function impetation of the function in the engineer class
making a zombie engineer with it health and hp and it's special attack
*/

#include "Engineer.h"


Engineer::Engineer(): Zombie("Engineer",1){// the defualt value to make a enginerr zombie
}
 
Engineer::Engineer(string name , int health): Zombie(name,health){// making a zombie imp based on the name and health that is put itno the zombie contrutor
}
 
int Engineer::SpecialAttack(){
  int damage = 2; // The damge of a specail attack for bucket head
  cout<< GetName()<<" blasts you with their steam blaster! , dealing "<<damage<<" of damag\
e"<<endl;
  return damage;
}
