// Section 13
// Static class members
#include <iostream>
#include "Player.h"

using namespace std;

void display_active_players() {
	cout << "Active players: " << Player::get_num_players() << endl;
}

int main() {
	display_active_players();
	Player hero{"Hero"};
	
	display_active_players();
	
	{
		Player geralt{"Geralt"};
		display_active_players();
		// Destructor will be call
	}
	
	display_active_players();
	
	Player *enemy = new Player("Enemy", 100, 100);
	display_active_players();
	delete enemy;
	display_active_players();    

	return 0;
}

