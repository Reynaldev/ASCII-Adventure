#include <iostream>
#include <string>

#include "Player.h"

using std::cout;
using std::cin;
using std::string;

Player player;
Enemy enemy;

Enemy initEnemy(Player player);
void playerTurn(Enemy &enemy);
void enemyTurn(Player &player);

int main() {
	string name;
	bool isClosed = false;

	cout << "Please enter your name: "; cin >> name;
	player.Init(name);

	system("cls");

	enemy = initEnemy(player);

	playerTurn(enemy);

	return 0;
}

Enemy initEnemy(Player player) {
	string enemyName[] = { "Green Ogre", "Deathfly", "Spidey", "Snow Troll" };
	int enemyNameLen = sizeof(enemyName) / sizeof(string);

	enemy.Init(enemyName[rand() % enemyNameLen], player.GetLevel());

	return enemy;
}

void playerTurn(Enemy& enemy) {
	if (player.isDead) {
		system("cls");

		cout << "You lose\n";
		cout << "\nYour final score: "
			<< "\nLevel: " << player.GetLevel()
			<< "\nExp: " << player.GetExp();

		player.~Player();
		return;
	}

	if (player.isLevelUp) {
		cout << "You leveled up!\n";

		system("pause");
		system("cls");
		
		player.isLevelUp = false;
	}

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

	switch (input) {
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

		cout << "Player will block all damages in the next turn.\n";
		player.isBlocking = true;
		player.UseMana(10);
		break;
	default:
		break;
	}

	system("pause");
	system("cls");

	enemy.Execute();
	enemyTurn(player);
}

void enemyTurn(Player& player) {
	if (enemy.isDead) {
		system("cls");
		
		cout << "You win\n";
		player.AddExp();
		player.AddMana();
		enemy.~Enemy();
		enemy = initEnemy(player);

		system("pause");
		system("cls");
		
		playerTurn(enemy);
		
		return;
	}

	int attack = rand() % 3;

	cout << "Enemy turn\n";

	system("pause");
	system("cls");

	switch (attack) {
	case 0:
		player.TakeDamage(enemy.GetDamage());
		cout << "You take " << enemy.GetDamage() << " damage(s)\n";
		break;
	case 1:
		enemy.AddHealth();
		cout << "Enemy heals by 25% of max HP.\n";
		break;
	case 2:
		enemy.isBlocking = true;
		cout << "Enemy ignores all attack in the next turn.\n";
		break;
	default:
		break;
	}

	system("pause");
	system("cls");

	player.Execute();
	playerTurn(enemy);
}
