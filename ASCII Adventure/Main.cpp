#include <iostream>
#include <string>

#include "Player.h"

using std::cout;
using std::cin;
using std::string;

Player player;

Enemy initEnemy(Player player) {
	Enemy enemy;
	string enemyName[] = { "Green Ogre", "Deathfly", "Spidey", "Snow Troll" };
	int enemyNameLen = sizeof(enemyName) / sizeof(string);

	enemy.Init(enemyName[rand() % enemyNameLen], player.GetLevel());

	return enemy;
}

void playerTurn(Enemy &enemy) {
	int input;

	cout << enemy.GetName()
		<< "\nHealth: " << enemy.GetHealth()
		<< "\nLevel: " << enemy.GetLevel();

	cout << "\n=================================================================\n\n";

	cout << player.GetName()
		<< "\nHealth: " << player.GetHealth()
		<< "\nLevel: " << player.GetLevel()
		<< "\nMana: " << player.GetMana()
		<< "\nExp: " << player.GetExp()
		<< "\nExps to next level: " << player.GetMaxExp();

	cout << "\n=================================================================\n\n";

	cout << "\n1) Attack (0 Mana)"
		<< "\n2) Heal (25 Mana)"
		<< "\n3) Block (10 Mana)";
	cout << "\n>> "; cin >> input;

	system("cls");

	switch (input)
	{
	case 1:
		enemy.TakeDamage(player.GetDamage());
		cout << "Enemy takes " << player.GetDamage() << " damage(s)\n";
		break;
	case 2:
		if (player.GetMana() < 25) {
			cout << "Not enough mana\n";
			system("pause");
			system("cls");
			playerTurn(enemy);
			
			return;
		}

		cout << "Player healing by 50%\n";
		player.AddHealth();
		player.UseMana(25);
		break;
	case 3:
		if (player.GetMana() < 10) {
			cout << "Not enough mana\n";
			system("pause");
			system("cls");
			playerTurn(enemy);
			
			return;
		}

		cout << "Player block all damages from the next attack\n";
		player.isBlocking = true;
		player.UseMana(10);
		break;
	default:
		break;
	}
}

int main() {
	string name;
	bool isClosed = false;

	cout << "Please enter your name: "; cin >> name;
	player.Init(name);

	system("cls");

	while (!isClosed) {
		Enemy enemy = initEnemy(player);

		while (!player.isDead) {
			playerTurn(enemy);

			enemy.Execute();

			if (enemy.isDead) {
				system("cls");
				cout << "You win\n";
				player.AddExp();
				player.AddMana();
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
				system("pause");
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

		player.~Player();

		isClosed = true;
	}

	return 0;
}