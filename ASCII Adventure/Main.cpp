#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

#include "Player.h"

using std::cout;
using std::cin;
using std::string;

Enemy initEnemy(Player player) {
	Enemy enemy;
	string enemyName[] = { "Green Ogre", "Deathfly", "Spidey", "Snow Troll" };
	int enemyNameLen = sizeof(enemyName) / sizeof(string);

	enemy.Init(enemyName[rand() % enemyNameLen], player.GetLevel());

	return enemy;
}

int main() {
	Player player;
	string name;
	bool isClosed = false;

	cout << "Please enter your name: "; cin >> name;
	player.Init(name);

	system("cls");

	while (!isClosed) {
		int input;

		Enemy enemy = initEnemy(player);

		//playerTurn(player, enemy);

		while (!player.isDead) {
			cout << enemy.GetName()
				<< "\nHealth: " << enemy.GetHealth()
				<< "\nLevel: " << enemy.GetLevel();

			cout << "\n=================================================================\n\n";

			cout << player.GetName()
				<< "\nHealth: " << player.GetHealth()
				<< "\nLevel: " << player.GetLevel()
				<< "\nExp: " << player.GetExp()
				<< "\nExps till next level: " << player.GetMaxExp();

			cout << "\n=================================================================\n\n";

			cout << "\n1) Attack";
			cout << "\n>> "; cin >> input;

			switch (input)
			{
			case 1:
				system("cls");
				enemy.TakeDamage(player.GetDamage());
				cout << "Enemy takes " << player.GetDamage() << " damage(s)\n";
				break;
			default:
				break;
			}

			enemy.Execute();

			if (enemy.isDead) {
				system("cls");
				cout << "You win\n";
				player.AddExp();
				enemy.~Enemy();
				enemy = initEnemy(player);
			}
			else {
				cout << "Enemy turn\n";
				system("pause");
				system("cls");
				player.TakeDamage(enemy.GetDamage());
				cout << "You take " << enemy.GetDamage() << " damage(s)\n";
			}

			player.Execute();

			if (player.isLevelUp) {
				system("cls");
				cout << "You leveled up!\n";
				player.isLevelUp = false;
			}

			system("pause");
			system("cls");
		}

		system("cls");
		cout << "You lose\n";
		cout << "\nYour final score: "
			<< "\nLevel: " << player.GetLevel()
			<< "\nExp: " << player.GetExp();
		isClosed = true;
	}
}