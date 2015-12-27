//main.cpp
//Igle
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include "lib.h"
#include <string.h>



int room_establish(int x)
{
	/*
		ESTA FUNCION SE ENCARGA DE DETERMINAR DE FORMA ALEATORIA ENTRE TODAS LAS HABITACIONES 
		DONDE ESTARÁ EL ITEM QUE LA LLAMA
	*/
	srand(time(NULL)+x);
	return rand() % (MAP*MAP);
}
void create_Map()
{

	//INICIALIZAMOS LAS HABITACIONES CON SUS DESCRIPCIONES
	//ROOM 0
	strcpy_s(rooms[0].description, ROOM0);
	rooms[0].nort = -1;
	rooms[0].south = 3;
	rooms[0].east = 1;
	rooms[0].west = -1;
	//ROOM 1
	strcpy_s(rooms[1].description, ROOM1);
	rooms[1].nort = 0;
	rooms[1].south = 4;
	rooms[1].east = 2;
	rooms[1].west = 0;
	//ROOM 2
	strcpy_s(rooms[2].description, ROOM2);
	rooms[2].nort = 0;
	rooms[2].south = 5;
	rooms[2].east = -1;
	rooms[2].west = 1;
	//ROOM 3
	strcpy_s(rooms[3].description, ROOM3);
	rooms[3].nort = 0;
	rooms[3].south = 6;
	rooms[3].east = 4;
	rooms[3].west = -1;
	//ROOM 4
	strcpy_s(rooms[4].description, ROOM4);
	rooms[4].nort = 1;
	rooms[4].south = 7;
	rooms[4].east = 5;
	rooms[4].west = 3;

	//INICIALIZAMOS CADA UNO DE LOS ITEMS
	std::cout << "Key in Room: "
		<<room_establish(0)
		<<"\n";
	objects[0].now_room= room_establish(0);
	strcpy_s(objects[0].desc1 ,"KEY");
	strcpy_s(objects[0].desc2, "The KEY shine.");
	objects[0].state = 0;
	objects[0].got_it = 0;
	std::cout << "Chest in Room: " 
		<<room_establish(1)
		<< "\n";
	objects[1].now_room = room_establish(1);
	strcpy_s(objects[1].desc1, "CHEST");
	strcpy_s(objects[1].desc2, "The CHEST shine.");
	objects[1].state = 0;
	objects[1].got_it = 0;
	std::cout << "Lantern in Room: "
		<< room_establish(2)
		<< "\n"; 
	objects[2].now_room = room_establish(2);
	strcpy_s(objects[2].desc1, "LANTERN");
	strcpy_s(objects[2].desc2, "The LANTERN is off.");
	objects[2].state = 0;
	objects[2].got_it = 0;
}
int find_objects(int now_Room)
{
	for (int i = 0; i <= 2; i++)
	{
		if (objects[i].now_room == now_Room)
		{
			return i;
		}
	}
	return -1;
}
void clean_floor(int x)
{
	objects[x].now_room = -1;
	strcpy_s(objects[x].desc1, "\0");
	strcpy_s(objects[2].desc2, "\0");
	objects[x].state = -1;
	objects[x].got_it = -1;
}
void free_inventory()
{
	bag.obj1 = -1;
	bag.obj2 = -1;
	bag.obj3 = -1;
	bag.obj4 = -1;
}
void main(void)
{
	bool done = false, done2 = false;
	int choose = -1;
	int now_Room = 0;
	int finder = -1;
	while (!done)//mientras que no se pase el juego seguira dentro del bucle pero cambiando opciones
	{
		//mostrar info de la habitacion actual
		std::cout << "1-Exit\n0-Create Map\n";
		//tomar entrada de jugador
		std::cin >> done;
		//procesar info obtenida del jugador
		if (!done)
		{
			free_inventory();
			create_Map();
			done2 = false;
			now_Room = 0;
			while (!done2)
			{
				std::cout << "You are now in the ROOM "
					<< now_Room;
				finder = find_objects(now_Room);
				if (finder != -1)
				{
					std::cout << "\nIn this ROOM you have: "
						<< objects[finder].desc1;
				}
				else
					std::cout << "\nThere is no items in this ROOM";
				std::cout << "\nWhat do you do?";
				std::cout << "\n1-Go North."
					<< "\n2-Go South."
					<< "\n3-Go East."
					<< "\n4-Go West."
					<< "\n5-Back."
					<< "\n6-Take."
					<< "\n7-See Inventory."
					<< "\n";
				std::cin >> choose;
				switch (choose)
				{
				case 1:
					//Vas hacia el norte
					if (now_Room <= 2 && now_Room>=0)
					{
						std::cout << "You hit with a very well built wall.\n";
					}
					else if (now_Room > 2)
					{
						now_Room = now_Room - 3;
						std::cout << "You enter in Room"
							<< now_Room
							<< "\n";
					}
					break;
				case 2:
					//vas hacia el sur
					if (now_Room >= 6)
					{
						std::cout << "You hit with a very well built wall.\n";
					}
					else if (now_Room < 6)
					{
						now_Room = now_Room + 3;
						std::cout << "You enter in Room"
							<< now_Room
							<< "\n";
					}
					break;
				case 3:
					//vas hacia el este
					if (now_Room < 8)
					{
						if (now_Room == 2)
						{
							std::cout << "You hit with a very well built wall.\n";
							break;	
						}
						else if (now_Room == 5)
						{
							std::cout << "You hit with a very well built wall.\n";
							break;
						}
						else if (now_Room == 8)
						{
							std::cout << "You hit with a very well built wall.\n";
							break;
						}
						else
						{
							now_Room = now_Room + 1;
							std::cout << "You enter in Room"
								<< now_Room
								<< "\n";
						}
						
					}
					else
						std::cout << "You hit with a very well built wall.\n";
					break;
				case 4:
					//vas hacia el oeste
					if (now_Room > 0)
					{
						if (now_Room == 0)
						{
							std::cout << "You hit with a very well built wall.\n";
							break;
						}
						else if (now_Room == 3)
						{
							std::cout << "You hit with a very well built wall.\n";
							break;
						}
						else if (now_Room == 6)
						{
							std::cout << "You hit with a very well built wall.\n";
							break;
						}
						else
						{
							now_Room = now_Room - 1;
							std::cout << "You enter in Room"
								<< now_Room
								<< "\n";
						}

					}
					else
						std::cout << "You hit with a very well built wall.\n";
					break;
				case 5:
					done2 = true;
					break;
				case 6:
					if (finder != -1)
					{
						std::cout << "You take: "
							<< objects[finder].desc1
							<< "\n";
						clean_floor(finder);
						if (bag.obj1 != -1)
						{
							bag.obj1 = finder;
						}
						else if (bag.obj2 != -1)
						{
							bag.obj2 = finder;
						}
						else if (bag.obj3 != -1)
						{
							bag.obj3 = finder;
						}
						else if (bag.obj4 != -1)
						{
							bag.obj4 = finder;
						}
						else
						{
							std::cout << "The inventory is full."
								<< "\n";
							break;
						}
						finder = -1;
						
					}
					else
					{
						std::cout << "There is nothing to take in this ROOM."
							<< "\n";
						break;
					}
				case 7:
					if (bag.obj1 == -1)
					{
						std::cout << "The inventory is empty."
							<< "\n";
						break;
					}
					else if (bag.obj2 == -1)
					{
						std::cout << bag.obj1
							<< "\n";
						break;
					}
					else if (bag.obj3 == -1)
					{
						std::cout << bag.obj1
							<< "\n"
							<< bag.obj2
							<< "\n";
						break;
					}
					else if (bag.obj4 == -1)
					{
						std::cout << bag.obj1
							<< "\n"
							<< bag.obj2
							<< "\n"
							<< bag.obj3
							<< "\n";
						break;
					}
					else
					{
						std::cout << bag.obj1
							<< "\n"
							<< bag.obj2
							<< "\n"
							<< bag.obj3
							<< "\n"
							<< bag.obj4
							<< "\n";
						break;
					}
					break;
				}
			}
		}
		else
		{
			done = true;
			std::cout << "Exiting...\n";
			system("pause");
		}
	}
	//system("CLS");//limpia la pantalla de la terminal
}