/*
File: Room.cpp
Project: CMSC 202 Project 4, FAll 2020
Author: Wei zhang weng
Date: 11/10/2020
Section: 10
Email: wweng2@umbc.edu

This file contain the function impetation of the function in the room class , in order to create a room, with its id, desc, and possioble exits and is able to display that imforamtion to the user
*/

#include "Room.h"


Room::Room(int ID , string name , string Desc, int north , int east, int south , int west){
  m_ID = ID;
  m_name = name;
  m_desc = Desc;
  m_direction[0] = north;// Sets the direction for the north exit
  m_direction[1] = east;
  m_direction[2] = south;
  m_direction[3] = west;

}

string Room::GetName(){
  return m_name;
}

int Room::GetID(){
  return m_ID;
}

string Room::GetDesc(){
  return m_desc;
}

int Room::CheckDirection(char myDirection){

  int choice;

  if(myDirection == 'N' || myDirection == 'n'){
    choice = 0 ;
  }
  else if (myDirection == 'E' || myDirection == 'e'){
    choice = 1 ;
  }
  else if (myDirection == 'S' || myDirection == 's'){
    choice = 2 ;
  }
  else if (myDirection == 'W' || myDirection == 'w'){
    choice = 3 ;
  }
  
  if (m_direction[choice] != -1){// If there is an exit, meaning the number is not -1 than return the id
    cout<<m_direction[choice]<<endl;
    return m_direction[choice];
      
  }
  else{// If the direction goes to -1 than return -1 and there is no exit
        return -1;
    }
     
}

void Room::PrintRoom(){
  int i;

  char direction [] = {'N','E','S','W'};// This set an array of char of direction to be use to display with direction has exots
  cout<<m_name<<endl;
  cout<<m_desc<<endl;
  cout<<"Possible exits: ";
  for (i = 0 ; i<4; i++){
    if(m_direction[i] != -1 ){// If m_direction is not -1 with mean there is an exit
      cout<<direction[i]<<" ";// This will display the direction corrpsonding to the number usiing the direction arrray
    }
  }
  cout<<" "<<endl;// This is to make the the the disply skip a line after the possible exits in order to avoiding for the screen to look like a mess  
      
       

  
}
