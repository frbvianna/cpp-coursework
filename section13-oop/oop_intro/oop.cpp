// Declare classes and objects
#include <iostream>
#include <string>
#include <vector>

class Player {
public:
    // attributes
    std::string name;
    int health {100};
    int xp {0};
    
    // methods
    void talk(std::string text_to_say) { 
        std::cout <<
        name << " says " << text_to_say 
        << std::endl; 
    };
    bool is_dead();
};

class Account {
public:
    // attributes
    std::string name;
    double balance;

    // methods
    bool deposit(double bal) { 
        balance += bal;
        std::cout << "Deposited "
        << bal << std::endl;
    };
    bool withdraw(double) {};
};

int main() {
    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.xp = 12;

    frank.talk("Hi there!");

    Player hero;

    Player players[] {frank, hero};

    Player *enemy {new Player};
    (*enemy).name = "Enemy";
    (*enemy).health = 100;
    enemy->xp = 15;

    enemy->talk("I will destroy you!");

    delete enemy;

    std::vector<Player> player_vec {frank};
    player_vec.push_back(hero); 

    Account frank_account;
    frank_account.name = "Frank's account";
    frank_account.balance = 5000.0;

    frank_account.deposit(1000.0);
    frank_account.withdraw(500.0);

    Account jim_account;

    Account *my_account {new Account};

    return 0;
}