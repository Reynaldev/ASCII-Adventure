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
	double maxHealth;
	double mana;
	double maxMana;
	double maxExp;
	double exp;
	int level;
	int damage;
public:
	bool isDead = false;
	bool isLevelUp = false;
	bool isBlocking = false;

	~Player();

	void Init(string name);
	void Execute();

	void TakeDamage(int amount);
	void AddExp();
	void AddMana();
	void AddHealth();
	void UseMana(double amount);

	string GetName();
	double GetHealth();
	double GetMana();
	double GetExp();
	double GetMaxExp();
	int GetLevel();
	int GetDamage();
};

