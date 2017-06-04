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
	char description[255];
	room *north, *south, *east, *west;
}room;

class Dungeon {
	public:
		room *createDungeon() { 
			room rooms[10];
			for (int i = 0; i < 10; i++) rooms[i].id = i;
			rooms[0].north = rooms[1].north = rooms[2].north = NULL;
			rooms[0].west= rooms[3].west = rooms[6].west = NULL;
			rooms[2].east = rooms[5].east = rooms[8].east = NULL;
			rooms[6].south = rooms[7].south = rooms[8].south = NULL;
			rooms[0].south = rooms[6].north = rooms[4].west =  &rooms[3];
			rooms[1].south = rooms[3].east = rooms[7].north = rooms[5].west = &rooms[4];
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
		room now_room;
	public:
		void actual_room( room now){now_room = now;};
		int _room(){return now_room.id;};
		void set_name(STRING _name){ name = _name; };
		void set_class(STRING _class) { char_class =_class; };
		STRING get_class(){return char_class;};
		STRING get_name(){return name;};
		void move(char direction){
			switch (direction) {
				case 'N':
					std::cout << "north" << std::endl;
					if(now_room.north != NULL)
						now_room = *now_room.north;
					else
						now_room = now_room;
					break;
				case 'S':
					std::cout << "sur" << std::endl;
					if (now_room.south != NULL)
						now_room = *now_room.south;
					else
						now_room = now_room;
					break;
				case 'E':
					std::cout << "east" << std::endl;
					if (now_room.east != NULL)
						now_room = *now_room.east;
					else
						now_room = now_room;
					break;
				case 'W':
					std::cout << "west" << std::endl;
					if (now_room.west != NULL)
						now_room = *now_room.west;
					else
						now_room = now_room;
					break;
				default:
					break;
			}
		};
		~Character() {};
};
