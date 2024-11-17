/* A common pattern for preventing multiple inclusions, 
 * known as header guards*/

#ifndef _PLAYER_H_ // Checks if _PLAYER_H_ has not been defined yet.
#define _PLAYER_H_ // Ensuring that if this header file is included again, the contents will be ignored,
#include <string> // The angle brackets indicate that this is a standard library header file.

class Player {
private:
   static int num_players; // Static atributes
   std::string name;
   int health;
   int xp;
   
public:
	std::string get_name() { return name; }
	int get_health() { return health; }
	int get_xp() {return xp; } 
	
	Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
	// Copy constructor
	Player(const Player &source);
	// Destructor
	~Player();
	
	static int get_num_players(); // It only has access to static atributes
};

#endif // _PLAYER_H_ , the guard ends.


/*Header Files
Declarations: They contain declarations of classes, functions, 
and variables that can be shared across multiple source files.
  * Code Organization, Preventing Multiple Inclusions, Facilitating Code Reuse */
