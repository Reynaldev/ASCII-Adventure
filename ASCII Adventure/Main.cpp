#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

#include "Player.h"
#include "Dialogue.h"

using std::cout;
using std::cin;
using std::string;

int main(int argc, const char** argv) {
	Player player;
	string name;
	string dialogueText;

	string enemyName[] = {"Green Ogre", "Deathfly", "Spidey", "Snow Troll"};
	int enemyNameLen = sizeof(enemyName) / sizeof(string);

	bool isClosed = false;

	cout << "Please enter your name: "; cin >> name;
	player.Init(name);

	system("cls");

	while (!isClosed) {
		int input;

		Enemy enemy;
		enemy.Init(enemyName[rand() % enemyNameLen]);

		cout << "Your Health: " << player.
		if ()

		player.Execute();
		enemy.Execute();

		system("pause");
		system("cls");
	}
}