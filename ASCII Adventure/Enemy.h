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
	bool isDead = false;

	~Enemy();

	void Init(string name, int level);
	void Execute();

	void TakeDamage(int amount);

	string GetName();
	double GetHealth();
	double GetDamage();
	int GetLevel();
};

