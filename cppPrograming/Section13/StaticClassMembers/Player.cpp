#include "Player.h"

int Player::num_players {0};

Player::Player(std::string name_val, int health_val, int xp_val) 
	: name{name_val}, health{health_val}, xp{xp_val} {
		++num_players;
}

Player::Player(const Player &source)
	   : Player {source.name, source.health, source.xp}  {
}

Player::~Player() {
	--num_players;
}

int Player::get_num_players() {
	return num_players;
}

/* 
 * Defining member functions like constructors and 
 destructors outside of the class definition 
 enhances clarity, maintainability, and organization of your code
 This practice is common in C++ programming and 
 aligns with best practices for software design.
*/ 
