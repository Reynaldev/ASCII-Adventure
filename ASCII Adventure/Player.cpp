#include "Player.h"

Player::~Player()
{
	this->name = string();
	this->health = NULL;
	this->maxExp = NULL;
	this->exp = NULL;
	this->level = NULL;
	this->damage = NULL;
}

void Player::Init(string newName)
{
	this->name = newName;
	this->health = 100;
	this->level = 1;
	this->exp = 0;
	this->maxExp = level * 100;
	this->damage = 1;
}

void Player::Execute()
{
	// Health
	if (this->health <= 0) {
		this->isDead = true;
	}
	// Health
}

void Player::AddExp()
{
	if (this->exp < this->maxExp) {
		this->exp += (this->level * 0.25) * 100;
	}
	else {
		this->isLevelUp = true;
		this->level++;
		this->damage += level - 1;
		this->maxExp += this->level * 100;
	}
}

void Player::TakeDamage(int amount)
{
	this->health -= amount;
}

string Player::GetName()
{
	return this->name;
}

double Player::GetHealth()
{
	return this->health;
}

double Player::GetExp()
{
	return this->exp;
}

double Player::GetMaxExp()
{
	return this->maxExp;
}

int Player::GetLevel()
{
	return this->level;
}

int Player::GetDamage()
{
	return this->damage;
}
