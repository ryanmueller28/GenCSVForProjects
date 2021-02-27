#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <random>
#include <vector>

#include "Person.h"
#include "Account.h"

int main()
{
    std::string FirstNames[2000];
    std::string LastNames[1000];
    std::ifstream firstNameFile("D:\\Dev\\cpp-random\\GenCustomerCSV\\src\\FirstNames.txt");
    

    if (firstNameFile.is_open())
    {
        for (int i = 0; i < 2000; i++)
        {
            firstNameFile >> FirstNames[i];
        }
    }
    std::ifstream lastNameFile("D:\\Dev\\cpp-random\\GenCustomerCSV\\src\\LastNames.txt");
    if (lastNameFile.is_open())
    {
        for (int i = 0; i < 1000; i++)
        {
            lastNameFile >> LastNames[i];
        }
    }

    firstNameFile.close();
    
    lastNameFile.close();


    std::mt19937 prng(std::chrono::system_clock::now().time_since_epoch().count());
    std::vector<Person> customers;

    /**
     * Fill customer array.
     * */
    for (int i = 0; i < 1000; i++)
    {
        std::string first_name = FirstNames[i];
        std::string last_name = LastNames[i];
        std::uniform_real_distribution<float> dis(-100.f, 10000.f);
        float checking_balance = dis(prng);
        float savings_balance = dis(prng);
        std::string address = std::to_string((unsigned int)prng());
        address += " Street";
        Account savingsAccount(savings_balance, "Savings");
        Account checkingsAccount(checking_balance, "Checkings");
        Person person(first_name, last_name, address, checkingsAccount, savingsAccount);
        customers.push_back(person);
    }

    std::ofstream out("D:\\Dev\\cpp-random\\GenCustomerCSV\\src\\customers.csv");

    if (out.is_open())
    {
        for (int i = 0; i < 1000; i++)
        {
            out << customers.at(i).GetFirstName() << "," << customers.at(i).GetLastName() << "," << customers.at(i).SavingsAccount.GetAccountType()
                << customers.at(i).SavingsAccount.GetAccountNum() << ",$" << customers.at(i).SavingsAccount.GetBalance() << "," <<
                customers.at(i).CheckingAccount.GetAccountType() << customers.at(i).CheckingAccount.GetAccountNum() << ",$" <<
                customers.at(i).CheckingAccount.GetBalance() << "," << customers.at(i).GetAddress() << "," << customers.at(i).GetPhoneNum() << ","
                << customers.at(i).GetEmail() << "\n";
        }
    }



    return EXIT_SUCCESS;
}