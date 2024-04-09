/*
File: Buckethead.cpp
Project: CMSC 202 Project 4, FAll 2020
Author: Wei zhang weng
Date: 11/10/2020
Section: 10
Email: wweng2@umbc.edu

This file contain the function impetation of the function in the Buckethead class , to make a buckethead zombie with it's health and name
*/

#include "Buckethead.h"


Buckethead::Buckethead(): Zombie("Zombie", 1){
}// Make the bucket head zombie with the default value of 1 hp and basic name

Buckethead::Buckethead(string name, int health): Zombie(name, health){// makes the buckethead zombie sing the name ad health and calling the zombie contrutor
}

int Buckethead::SpecialAttack(){
  int damage = 1; // The damge of a specail attack for bucket head
  cout<< GetName()<<" throws its bucket at you! , dealing "<<damage<<" of damage"<<endl;
  return damage;
}
