#pragma once
#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include "Account.h"

class Person
{
public:
    Person();
    ~Person();
    Person(std::string _firstName, std::string _lastName, std::string _Address, Account _CheckingAccount, Account _SavingAccount);

    void GenEmail();
    void Print();
    void GenPhoneNum();

    std::string GetAddress() { return Address; }
    std::string GetFirstName() { return FirstName; }
    std::string GetLastName() { return LastName; }
    std::string GetPhoneNum();
    std::string GetEmail();

    Account CheckingAccount;
    Account SavingsAccount;

private:
    std::string FirstName;
    std::string LastName;
    std::string Address;
    std::string PhoneNum;
    std::string Email = "";


};