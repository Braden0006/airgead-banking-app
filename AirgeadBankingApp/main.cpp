

#include <iostream>
#include "Account.h"
using namespace std;

int main()
{
    Account account1;

    account1.UserInput();

    account1.CalculateBalanceNoDeposit(account1.GetInvestmentAmount(), account1.GetInterestRate(), account1.GetNumYears());

    account1.CalculateBalance(account1.GetInvestmentAmount(), account1.GetMonthlyDeposit(), account1.GetInterestRate(), account1.GetNumYears());

    account1.DisplayTableNoDeposit();
    cout << endl;
    cout << endl;
    account1.DisplayTable();

}