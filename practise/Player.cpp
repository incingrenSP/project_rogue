#include "Player.h"
#include "Enemy.h"
#include <cmath>

const double eular = std::exp(1.0);

Player::Player(std::string p_name)
	:name{p_name}, max_exp{100}, exp{0}, max_level{80}, level{1}
{}

Player::Player(const Player& source)
	:name(source.name), max_exp(source.max_exp), exp(source.exp), max_level(source.max_level), level(source.level)
{}

Player::~Player()
{}

int Player::add_exp(int p_exp)
{
	exp += p_exp;
	if (level_condition()) {
		level_up();
	}
	return 0;
}

int Player::exp_curve()
{
	exp -= max_exp;
	max_exp += (1 + eular * 100);
	return 0;
}

bool Player::level_condition()
{
	if (exp > max_exp || level < max_level) {
		exp_curve();
		std::cout << name << " levelled up to level " << level << std::endl;
		return true;
	}
	else {
		return false;
	}
}

int Player::level_up()
{
	level++;
	level_condition();
	return 0;
}

std::string Player::getName()
{
	return name;
}

int Player::getLevel()
{
	return level;
}

int Player::getExp()
{
	return exp;
}

int Player::getToNextLevel()
{
	return max_exp;
}