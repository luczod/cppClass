#include "Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "IllegalBalanceException.h"
#include "Savings_Account.h"
#include "Trust_Account.h"

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    // try by value(Object) and catch by ref
    try {
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0);
        std::cout << *moes_account << std::endl;

    } catch(const IllegalBalanceException& ex) {
        std::cerr << "Couldn't create account - negative balance" << std::endl;
    }
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}
