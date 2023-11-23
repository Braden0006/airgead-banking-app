

#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
    Account account1;
    Account account2;

    double userAmount;
    double userMonthlyAmount;
    double userInterest;
    int userYear;

    cout << "**********************************" << endl;
    cout << "*********** Data Input ***********" << endl;
    cout << "Initial Investment Amount:  ";
    cin >> userAmount;

    cout << "Monthly Deposit:  ";
    cin >> userMonthlyAmount;

    cout << "Annual Interest  ";
    cin >> userInterest;

    cout << "Number of Years:  ";
    cin >> userYear;

    cout << "Press any key to continue..." << endl;

    account1.CalculateBalanceNoDeposit(userAmount, userInterest, userYear);
    account2.CalculateBalance(userAmount, userMonthlyAmount, userInterest, userYear);

    account1.DisplayTableNoDeposit();
    cout << endl;
    cout << endl;
    account2.DisplayTable();

}