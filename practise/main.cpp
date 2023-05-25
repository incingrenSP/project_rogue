#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Player.h"

int enemy_diff(int& exp, int random_num)
{
	switch (random_num) {
	case 0:
		exp = 200;
		break;
	case 1:
		exp = 1500;
		break;
	case 2:
		exp = 10000;
		break;
	case 3:
		exp = 50;
		break;
	default:
		exp = 0;
		std::cout << "Enemy ran away." << std::endl;
	}
	return 0;
}

int dev_mode(Player hero)
{
	int exp{ 0 };
	std::cout << "You chose DEV MODE." << std::endl;
	std::cout << "Enter amount of exp: " << std::endl;
	std::cin >> exp;
	hero.add_exp(exp);
	return 0;
}

int main()
{
	std::string name;
	int choice{ 0 }, exp{ 0 }, enemy{ 0 };
	
	
	std::cout << "Enter Player Name: ";
	std::cin >> name;
	std::cout << "Welcome to clusterfuck game.\nYou have a chance to fight a boss which can obliterate you if you're too underlevelled." << std::endl;
	std::cout << "But you won't know you're fighting a boss unless you take your turn. Hope you enjoy!" << std::endl;

	Player player(name);

	while (true) {
		enemy = rand() % 5;
		std::cout << "An enemy has appeared.\t[1]Fight\t[2]Exit" << std::endl;
		std::cin >> choice;
		fflush(stdin);
		switch (choice) {
		case 1:
			enemy_diff(exp, enemy);
			std::cout << "You chose to fight.\nYou defeated the enemy.\nYou gained " << exp << " exp." << std::endl;
			player.add_exp(exp);
			break;
		case 2:
			std::cout << "You chose to run away.\n" << std::endl;
			std::cout << "Your stats:\n" << std::endl;
			std::cout << "Name:\t" << player.getName() << std::endl;
			std::cout << "Level:\t" << player.getLevel() << std::endl;
			std::cout << "Exp:\t" << player.getExp() << std::endl;
			std::cout << "To Next Level: " << player.getToNextLevel() << std::endl;
			exit(0);
			break;
		case 69:
			dev_mode(player);
			break;
		default:
			std::cout << "Enter a valid choice." << std::endl;
		}
		system("cls");
	}
	
	return 0;
}