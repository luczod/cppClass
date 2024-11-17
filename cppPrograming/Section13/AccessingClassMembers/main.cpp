// Section 13
// Accessing Class Members
#include <iostream>
#include <string>

using namespace std;

class Player { // default private
public: 
    // attributes
    string name;
    int health;
    int xp;
    
    // methods
    void talk(string text_to_say) { cout << name << " says " << text_to_say << endl;  }
    bool is_dead();
};

class Account { // default private
public:
    // attributes
    string name;
    double balance;
    
    // methods
    bool deposit(double bal) {
        balance += bal; 
        cout << "In deposit" << endl; 
        return true;
    }
    
    bool withdraw(double bal) {
        balance -= bal; 
        cout << "In withdraw" << endl;
        return true;
    }
    
};

int main() {
    Account jonh_account;
    jonh_account.name = "jonh's account";
    jonh_account.balance = 5000.0;
    
    jonh_account.deposit(1000.0);
    jonh_account.withdraw(500.0);
    
    
    Player jonh;
    jonh.name = "jonh";
    jonh.health = 100;
    jonh.xp = 12;
    jonh.talk("Hi there");
    
    Player *enemy = new Player;
    (*enemy).name = "Enemy";
    (*enemy).health = 100;
    enemy->xp = 15;
    
    enemy->talk("I will destroy you!");
    


    return 0;
}

