#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <vector>
class BankAccount
{
private:
    std::string owner;
    int balance;
    const int count;

public:
    BankAccount(std::string owner);
    BankAccount(std::string owner, int balance);
    void deposit(int amount);
    void withdraw(int amount);
    std::string getowner() const;
    int getBalance() const;
    ~BankAccount();
};

#endif