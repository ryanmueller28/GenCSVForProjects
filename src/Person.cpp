#include "Person.h"

Person::Person()
{

}

Person::~Person()
{

}

Person::Person(std::string _firstName, std::string _lastName, std::string _Address, Account _CheckingAccount, Account _SavingAccount)
{
    FirstName = _firstName;
    LastName = _lastName;
    Address = _Address;
    CheckingAccount = _CheckingAccount;
    SavingsAccount = _SavingAccount;

}

void Person::Print()
{
      GenEmail();
    GenPhoneNum();
    std::cout << FirstName << "," << LastName << ",";
    SavingsAccount.PrintInfo();
    CheckingAccount.PrintInfo();
    std::cout << Address << "," << PhoneNum << "," << Email << std::endl;
}

void Person::GenEmail()
{
    std::mt19937 prng(std::chrono::system_clock::now().time_since_epoch().count());
    
    std::string domainNames[4] = { "gmail.com", "hotmail.com", "yahoo.com", "msn.com" };

    Email += FirstName;
    Email += ".";
    Email += LastName;
    Email += "@";
    Email += domainNames[prng() % 4];
}

void Person::GenPhoneNum()
{

    std::default_random_engine prng;
    std::uniform_int_distribution<int> dist(0, 9);
    std::string temp = "";

    for (int i = 0; i < 9; i++)
    {
        temp = (char)dist(prng);
    }

    PhoneNum = temp;
}

std::string Person::GetPhoneNum()
{
    GenPhoneNum();
    return Email;
}

std::string Person::GetEmail()
{
    GenEmail();
    return Email;
}
