//main.cpp
//Igle

#include "lib.h"

/*bool restore_game(Character ch_restore) {
std::ifstream ifile(".saved.bin");
char __name[10];
if (ifile) {
std::ifstream saved_file;
int file_size[2];
file_size[0] = saved_file.tellg();
saved_file.seekg(0, std::ios::end);
file_size[1] = saved_file.tellg();
std::ifstream::pos_type size = file_size[1] - file_size[0];
saved_file.open(".saved.bin", std::ios::binary);
saved_file.seekg(0, std::ios::beg);
saved_file.read((char *)&__name, size);
Character ch_restore(__name);
std::cout << "Nombre: "
<< __name << std::endl;
saved_file.close();
return true;
}
else
return false;
}

bool save_game(Character ch_save) {
std::ifstream::pos_type size = sizeof(ch_save);
std::ofstream saved_file;
saved_file.open(".saved.bin", std::ios::binary);
saved_file.seekp(0, std::ios::beg);
saved_file.write((char *)&ch_save, size);
saved_file.close();
return true;
}
Character::Character(char *_name) {
strcpy_s(name,_name);
}*/
Character pj1;
Dungeon mazz;
int room_establish(int x)
{
	/*
	ESTA FUNCION SE ENCARGA DE DETERMINAR DE FORMA ALEATORIA ENTRE TODAS LAS HABITACIONES
	DONDE ESTARÁ EL ITEM QUE LA LLAMA
	*/
	srand(time(NULL) + x);
	return rand() % (MAP*MAP);
}
void create_Map()
{
	//HERE WE CREATE THE DUNGEON ITSELF.
	if (!pj1.set_Mazz(mazz.createDungeon()) || !(pj1.set_room())) {
		LOG("Error al crear la mazzmorra");
	}
	//AND WE PUT OWR CHARACTER ON THE ROOM 0

}
/*int find_objects(int now_Room)
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
}*/
void main(void)
{
	bool done = false, done2 = false;
	int choose = -1;
	int now_Room = 0;
	int finder = -1;
	char __name[10] = "";
	int char_class;
	object inventario[5];
	while (!done)
		//mientras que no se pase el juego seguira dentro del bucle pero cambiando opciones
	{
		//mostrar info de la habitacion actual
		std::cout << "1-Exit\n0-Create Map\n";
		//tomar entrada de jugador
		std::cin >> done;
		//procesar info obtenida del jugador
		if (!done)
		{
			std::cout << "Escriba su nombre(maximo 10 caracteres):" << std::endl;
			std::cin >> __name;
			//Character ch1(__name);
			//save_game(ch1);
			std::cout << "Elige a tu heroe:\n"
				<< "0-Mage\n"
				<< "1-Titan\n"
				<< "2-Rogue\n";
			//tomar entrada de jugador
			std::cin >> char_class;
			switch (char_class) {
			case 0:
				pj1 = Character(__name, "Mage");
				break;
			case 1:
				pj1 = Character(__name, "Titan");
				break;
			case 2:
				pj1 = Character(__name, "Rogue");
				break;
			default:
				break;
			}
			//instanciamos el mapa de la dungeon para esta partida.
			create_Map();
			done2 = false;
			while (!done2)
			{
				std::cout << "You are now in the ROOM "
					<< pj1._room() << std::endl;
				LOG(pj1.get_name());
				LOG(pj1.get_class());
				/*finder = find_objects(now_Room);
				if (finder != -1)
				{
				std::cout << "\nIn this ROOM you have: "
				<< objects[finder].desc1;
				}
				else
				std::cout << "\nThere is no items in this ROOM";*/
				std::cout << "\nWhat do you do?";
				std::cout << "\n1-Go North."
					<< "\n2-Go South."
					<< "\n3-Go East."
					<< "\n4-Go West."
					<< "\n5-Inventory."
					<< "\n6-Take."
					<< "\n7-BACK"
					<< "\n";
				std::cin >> choose;
				switch (choose)
				{
				case 1:
					pj1.move('N');
					break;
				case 2:
					pj1.move('S');
					break;
				case 3:
					pj1.move('E');
					break;
				case 4:
					pj1.move('W');
					break;
				case 5:
					LOG("Under construction!!!");
					break;
				case 6:
					LOG("Under construction!!!");
					break;
				case 7:
					done2 = true;
					break;
				default:
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
}