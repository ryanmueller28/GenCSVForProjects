#include "Account.h"

Account::Account(float _Balance, std::string _AccountType)
{
    Balance = _Balance;
    AccountType = _AccountType;

    std::mt19937 prng(std::chrono::system_clock::now().time_since_epoch().count());
    
    std::string accountNumString = "";

    for (int i = 0; i < 12; i++)
    {
        accountNumString += (char)prng();
    }
}

void Account::PrintInfo()
{
    std::cout << AccountType << "," << AccountNum << "," << Balance << ",";
}