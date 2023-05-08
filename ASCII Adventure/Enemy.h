#pragma once

#ifndef Enemy.h
#include <string>
#include "Player.h"
#endif // !Enemy.h

using std::string;

class Enemy
{
private:
	string name;
	double health;
	double damage;
	int level;

public:
	void Init(string name);
	void Execute();

	void Attack();
	void TakeDamage(int amount);
	void Died();

	string GetName();
	double GetHealth();
	double GetDamage();
	int GetLevel();
};

