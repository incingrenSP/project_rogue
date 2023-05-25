#pragma once

#include <iostream>
#include <string>
#include <vector>

class Player
{
public:
	Player(std::string);
	Player(const Player&);
	~Player();
	int add_exp(int);
	bool level_condition();
	int exp_curve();
	int level_up();
	std::string getName();
	int getLevel();
	int getExp();
	int getToNextLevel();
private:
	std::string name;
	int level;
	int exp;
	int max_level;
	int max_exp;
};

