/*
File: Chomper.cpp
Project: CMSC 202 Project 4, FAll 2020
Author: Wei zhang weng
Date: 11/10/2020
Section: 10
Email: wweng2@umbc.edu

This file contain the function impetation of the function in the Chomper class
which create a chomper class with it's health and name
*/

#include "Chomper.h"
  // Postconditions: Can create a chomper
Chomper::Chomper(): Plant("Chomper", 1){//The dfault value to make a chomper obejct
}

Chomper::Chomper(string name , int health): Plant(name,health){// Makes an chomper object using the name and health that calls to the plant construtor
}

Chomper::~Chomper(){
}// Nothing since there is nothing to dynamtically remove

int Chomper::SpecialAttack(){
  int damage = rand() % 6 + 1 ;// Get a random between 1 and 6
  cout<< GetName()<<" performs a sneak attack! CHOMP , dealing "<<damage<<" damge!"<<endl;
  return damage;
}

