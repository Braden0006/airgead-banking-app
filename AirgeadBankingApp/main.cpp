// AirgeadBankingApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
    Account account1;

    double userAmount;
    double userMonthlyAmount;
    double userInterest;
    int userYear;

    cout << "**********************************" << endl;
    cout << "*********** Data Input ***********" << endl;
    cout << "Initial Investment Amount:  ";
    cin >> userAmount;
    account1.SetInvestmentAmount(userAmount);

    cout << "Monthly Deposit:  ";
    cin >> userMonthlyAmount;
    account1.SetMonthlyDeposit(userMonthlyAmount);

    cout << "Annual Interest  ";
    cin >> userInterest;
    account1.SetAnnualInterest(userInterest);

    cout << "Number of Years:  ";
    cin >> userYear;
    account1.SetNumberYears(userYear);

    cout << "Press any key to continue..." << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
