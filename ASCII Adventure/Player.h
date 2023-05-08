#pragma once

#ifndef Player.h
#include <string>
#include "Enemy.h"
#endif // !Player.h

using std::string;

class Player
{
private:
	string name;
	double health;
	double maxExp;
	double exp;
	int level;
	int damage;
public:
	void Init(string newName);
	void Execute();
	void AddExp();

	void Attack();
	void TakeDamage(int amount);
	void Died();

	string GetName();
	double GetHealth();
	double GetExp();
	int GetLevel();
	int GetDamage();
};

