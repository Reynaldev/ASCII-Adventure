#include "Enemy.h"

Enemy::~Enemy()
{
	this->name = string();
	this->maxHealth = NULL;
	this->health = NULL;
	this->damage = NULL;
	this->level = NULL;
	this->isDead = false;
}

void Enemy::Init(string name, int level)
{
	this->name = name;
	this->level = rand() % level + 1;
	this->maxHealth = rand() % this->level + 5;
	this->health = this->maxHealth;
	this->damage = rand() % level + 1;
}

void Enemy::Execute()
{
	if (this->health <= 0) {
		this->isDead = true;
	}
}

void Enemy::TakeDamage(int amount)
{
	this->health -= (this->isBlocking) ? 0 : amount;
	this->isBlocking = false;
}

void Enemy::AddHealth()
{
	this->health += this->maxHealth * .25;
}

string Enemy::GetName()
{
	return this->name;
}

double Enemy::GetHealth()
{
	return this->health;
}

double Enemy::GetDamage()
{
	return this->damage;
}

int Enemy::GetLevel()
{
	return this->level;
}
