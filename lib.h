//lib.h
//-Igle-
#pragma once
#include <stdio.h>
#include <winsock.h>//sockets for windows
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>
//#include <cppconn/driver.h>
//#include <cppconn/exception.h>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
#define DEBUG 1
#if DEBUG 
	#define LOG(X) std::cout<<X<<std::endl;
#else
#define LOG(X)
#endif
#ifndef MAP
	#define MAP 3
#endif
#ifndef KEY
	#define KEY 0
#endif
#ifndef __cplusplus
	std::cout << "C++ compiler not found";
#endif
#ifndef ROOM0
#define ROOM0 "Room 0 descripton."
#endif
#ifndef ROOM1
#define ROOM1 "Room 1 descripton."
#endif
#ifndef ROOM2
#define ROOM2 "Room 2 descripton."
#endif
#ifndef ROOM3
#define ROOM3 "Room 3 descripton."
#endif
#ifndef ROOM4
#define ROOM4 "Room 4 descripton."
#endif
#define STRING std::string
typedef struct room
{
	int id;
	char description[2];
	room *north, *south, *east, *west;
};

class Dungeon {
	public:
		room *createDungeon() { 
			room rooms[9];
			for (int i = 0; i <9; i++) rooms[i].id = i;
			rooms[0].north = rooms[1].north = rooms[2].north = NULL;
			rooms[0].west= rooms[3].west = rooms[6].west = NULL;
			rooms[2].east = rooms[5].east = rooms[8].east = NULL;
			rooms[6].south = rooms[7].south = rooms[8].south = NULL;
			rooms[1].west = rooms[3].north = &rooms[0];
			rooms[0].east = rooms[2].west = rooms[4].north = &rooms[1];
			rooms[1].east = rooms[5].north = &rooms[2];
			rooms[0].south = rooms[6].north = rooms[4].west =  &rooms[3];
			rooms[1].south = rooms[3].east = rooms[7].north = rooms[5].west = &rooms[4];
			rooms[2].south = rooms[4].east = rooms[8].north = &rooms[5];
			rooms[3].south = rooms[7].west = &rooms[6];
			rooms[4].south = rooms[6].east = rooms[8].west = &rooms[7];
			rooms[5].south = rooms[7].east = &rooms[8];
			return rooms;
		};
		~Dungeon(){};
};

class object{
	public:
		char desc1[80], desc2[80];
		int now_room, got_it;
};

class Character {
	/*
	We are gonna have 3 main tipes of character, the mage, rogue and titan.
	The values of heath, defense and attack depends by the main type of character.
	*/
	private:
		STRING name;
		long health, defense, attack;
		STRING char_class = "";
		object inventory[2];
		room *now_room, *mazzmorra;
	public:
		int _room(){return now_room->id;};
		void set_name(STRING _name){ name = _name; };
		void set_class(STRING _class) { char_class =_class; };
		STRING get_class(){return char_class;};
		STRING get_name(){return name;};
		bool set_Mazz(room *mazz){this->mazzmorra = mazz; return true;};
		bool set_room(){now_room = &mazzmorra[0]; return true;};
		void move(char direction){
			switch (direction) {
				case 'N':
					LOG("north");
					break;
				case 'S':
					LOG("south");
					
					break;
				case 'E':
					LOG("east");
					
					break;
				case 'W':
					LOG("west");
					break;
				default:
					break;
			}
		};
		Character(){};
		Character(STRING _name, STRING _class){
			name = _name;
			char_class = _class;
		};
		~Character() {};
};
