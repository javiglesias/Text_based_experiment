//lib.h
//-Igle-
#pragma once
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

#ifndef PRINT_ROOM_0
#define PRINT_ROOM_0 " _______\n|\t|\n|\t|\n|\t|\n|\t|\n|_______|\n"
#endif // !PRINT_ROOM_0


//
struct room
{
	char description[255];
	int nort, south, east, west;
}rooms[(MAP*MAP)];

struct object
{
	int state;
	char desc1[80], desc2[80];
	int now_room, got_it;
}objects[2];

struct inventory
{
	int obj1 = -1, obj2 = -1, obj3 = -1, obj4 = -1;
}bag;

typedef struct rooms
{
	char description[140];
	char puerta[5];
	//north, south, east, west
} roome;