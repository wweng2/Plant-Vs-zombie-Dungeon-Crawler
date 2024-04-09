/*
File: Entity.cpp
Project: CMSC 202 Project 4, FAll 2020
Author: Wei zhang weng
Date: 11/10/2020
Section: 10
Email: wweng2@umbc.edu

This file contain the function impetation of the function in the entity class, of basic settiung of health and name to be use as a base class .
*/

#include "Entity.h"

Entity::Entity(){
  SetName("Nothing");// Set the name to nothing as this will never be called directly so placeholder
  SetHealth(1);
}

Entity::Entity(string name, int health){
  SetName(name);
  SetHealth(health);
}

Entity::~Entity(){// As it's a virtual classleft it blanked as the thing that is use is in it's child class

}
 
string Entity::GetName(){
  return m_name;
}
 
int Entity::GetHealth(){
  return m_health;
}

void Entity::SetName(string name){
  m_name = name;
}

void Entity::SetHealth(int health){
  if (health >= 0){// If the health is not negative , set m_health as it
    m_health = health;
  }
 
}
ostream& operator<<(ostream& output, Entity& E){
    cout<<"Name: "<<E.m_name<<endl;
    cout<<"Health: "<<E.m_health<<endl;
    return output;
  }
