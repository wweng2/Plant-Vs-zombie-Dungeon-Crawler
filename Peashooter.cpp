/*
File: Peashooter.cpp
Project: CMSC 202 Project 4, FAll 2020
Author: Wei zhang weng
Date: 11/10/2020
Section: 10
Email: wweng2@umbc.edu

This file contain the function impetation of the function in the peashooter class
*/

#include "Peashooter.h"


Peashooter::Peashooter(): Plant("Peashhoter",1){// The most basic assigment of name and health for a peashooter and it's health which use the plant construtor
}

Peashooter::Peashooter(string name , int health): Plant(name,health){// Make a peashooter by calling the plant contrutor that the peashooter inherits
}

Peashooter::~Peashooter(){
}// Nothing since there is nothing to delocated

int Peashooter::SpecialAttack(){
  int damage = rand() % 12 + 3;// Makes the the random to be range between 3 and 12

  cout<<GetName()<<" spins up doing GATLING DAMAGE! doing "<<damage<<" damage"<<endl;
  return damage;
}
