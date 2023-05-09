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
	bool isDead = false;
public:
	~Player();

	void Init(string newName);
	void Execute();
	void AddExp();

	void TakeDamage(int amount);

	string GetName();
	double GetHealth();
	double GetExp();
	int GetLevel();
	int GetDamage();
	bool IsDead();
};

