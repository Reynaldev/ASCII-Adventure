#include "Player.h"

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
	if (this->health <= 0) {
		Died();
	}
}

void Player::AddExp()
{
	if (this->exp < this->maxExp) {
		this->exp += (this->level * 0.25) * 100;
	}
	else {
		this->level++;
		this->maxExp += this->level * 100;
	}
}

void Player::Attack(Enemy enemy)
{
	enemy.TakeDamage(this->damage);
}

void Player::TakeDamage(int amount)
{
	this->health -= amount;
}

void Player::Died()
{

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

int Player::GetLevel()
{
	return this->level;
}

int Player::GetDamage()
{
	return this->damage;
}
