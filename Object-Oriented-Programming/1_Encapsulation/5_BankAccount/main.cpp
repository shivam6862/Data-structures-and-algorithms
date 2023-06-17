#include <iostream>
#include <string>
#include "BankAccount.h"

void PrintAccount(BankAccount &myaccount);

int main()
{
    BankAccount myAccount("Shivam");
    myAccount.deposit(1000);
    myAccount.withdraw(450);

    PrintAccount(myAccount);

    std::string name;
    std::cout << "Enter your Name :- ";
    std::cin >> name;

    int amount;
    std::cout << "Enter the Amount :- ";
    std::cin >> amount;

    BankAccount myAccount2(name, amount);

    int deposit;
    std::cout << "Enter the Amount to deposit :- ";
    std::cin >> deposit;
    myAccount2.deposit(deposit);

    int withdraw;
    std::cout << "Enter the Amount to withdraw :- ";
    std::cin >> withdraw;
    myAccount2.withdraw(withdraw);

    PrintAccount(myAccount2);

    return 0;
}

void PrintAccount(BankAccount &myAccount)
{
    std::cout << "Name " << myAccount.getowner() << ", Amount :- " << myAccount.getBalance() << std::endl;
}
