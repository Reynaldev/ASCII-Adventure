#include "Enemy.h"

Enemy::~Enemy()
{
	this->name = string();
	this->health = NULL;
	this->damage = NULL;
	this->level = NULL;
}

void Enemy::Init(string name, int level)
{
	this->name = name;
	this->level = rand() % level + 1;
	this->health = rand() % this->level + 5;
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
	this->health -= amount;
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

bool Enemy::IsDead()
{
	return this->isDead;
}
