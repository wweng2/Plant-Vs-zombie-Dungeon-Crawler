/*
File: Zombie.cpp
Project: CMSC 202 Project 4, FAll 2020
Author: Wei zhang weng
Date: 11/10/2020
Section: 10
Email: wweng2@umbc.edu

This file contain the function impetation of the function in the zombie class
*/

#include "Zombie.h"


Zombie::Zombie(): Entity("Zombie",1){// Default value to be use to make a zombie even though it notn possible
}

Zombie::Zombie(string name, int health): Entity(name,health){// Makes a zombie objct using th set name and set health function from the netity class
}
 
int Zombie::Attack(){
  int damage = 1;// The damge for the zombie and everyhting sub class of it
  cout<<GetName()<<" deals "<<damage <<" damage "<<endl;
  return damage;
}

