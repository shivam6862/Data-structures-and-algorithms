#include <iostream>
#include <string>
#include "BankAccount.h"

BankAccount::BankAccount(std::string owner) : count(1)
{
    this->owner = owner;
    this->balance = 0;
    std::cout << "BankAccount Created!" << std::endl;
}
BankAccount::BankAccount(std::string owner, int balance) : count(1)
{
    std::cout << "BankAccount Created with Parameter!" << std::endl;
    this->owner = owner;
    if (balance < 0)
    {
        std::cout << "You must enter balance > 0 !" << std::endl;
        this->balance = 0;
    }
    else
    {
        this->balance = balance;
    }
}
void BankAccount::deposit(int amount)
{
    if (amount <= 0)
    {
        std::cout << "You must deposit balance grater equal to zero!" << std::endl;
    }
    else
    {
        this->balance += amount;
    }
}
void BankAccount::withdraw(int amount)
{
    if (amount > this->balance)
    {
        std::cout << "You must withdraw balance less than your account balance!" << std::endl;
    }
    else
    {
        this->balance -= amount;
    }
}
std::string BankAccount::getowner() const
{
    return owner;
}
int BankAccount::getBalance() const
{
    return balance;
}
BankAccount::~BankAccount()
{
    std::cout << "BankAccount Destroyed!" << std::endl;
}