/*
File: Imp.cpp
Project: CMSC 202 Project 4, FAll 2020
Author: Wei zhang weng
Date: 11/10/2020
Section: 10
Email: wweng2@umbc.edu

This file contain the function impetation of the function in the imp class
to make an imp zombie with it's health and name
*/

#include "Imp.h"


Imp::Imp(): Zombie("Imp", 1){// TYhe defualt value to contrut an imp zombie
}

Imp::Imp(string name, int health): Zombie(name, health){// Making an imp zombie based on the name and health
}

int Imp::SpecialAttack(){
  int damage = 4; // The damge of a specail attack for bucket head
  cout<< GetName()<<" blast you with thier Impkata attack! , dealing "<<damage<<" of damag\
e"<<endl;
  return damage;
}
