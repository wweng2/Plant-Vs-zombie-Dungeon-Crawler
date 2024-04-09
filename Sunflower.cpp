/*
File: Sunflower.cpp
Project: CMSC 202 Project 4, FAll 2020
Author: Wei zhang weng
Date: 11/10/2020
Section: 10
Email: wweng2@umbc.edu

This file contain the function impetation of the function in the sunflower class and create a sunflower object with it's name and health
*/

#include "Sunflower.h"

 
Sunflower::Sunflower(): Plant("Sunflower",1){// The defualt name and health for sunflower that to make the object
}

Sunflower::Sunflower(string name , int health): Plant(name,health){// Uing the name and health insert in the in paramter to make an object
}
 
Sunflower::~Sunflower(){// Noithing becuase there is nothing dynammically in the sunflwoer class
}
 
int Sunflower::SpecialAttack(){
  int damage = rand() % 8 + 1;
  cout<<GetName()<<" uses a high beam turret- **SUNBEAM** , dealing "<<damage<<endl;
  return damage;
}
