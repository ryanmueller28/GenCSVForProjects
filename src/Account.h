#pragma once
#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include <string>

class Account{
public:
    Account() {}
    ~Account() {}
    Account(float _Balance, std::string _AccountType);


    void PrintInfo();

    std::string GetAccountNum() { return AccountNum; }
    float GetBalance() { return Balance; }
    std::string GetAccountType() { return AccountType; }
private:
    std::string AccountNum;
    float Balance;
    std::string AccountType;
    
};