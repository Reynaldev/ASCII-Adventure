#include "Enemy.h"

void Enemy::Init(string name)
{
	this->name = name;
	this->health = std::rand() % 10 + 1;
	this->damage = std::rand() % 5;
}

void Enemy::Execute()
{
	if (this->health <= 0) {
		Died();
	}
}

void Enemy::Attack(Player player)
{
	player.TakeDamage(this->damage);
}

void Enemy::TakeDamage(int amount)
{
	this->health -= amount;
}

void Enemy::Died()
{
}
