#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Account {

public:
	Account();

	void CalculateBalance(double investmentAmount, double monthlyDeposit, double annualInterest, int numYears);
	void CalculateBalanceNoDeposit(double investmentAmount, double annualInterest, int numYears);
	void DisplayTable() const;
	void DisplayTableNoDeposit() const;
	void UserInput(double userAmount, double userMonthlyDeposit, double userInterest, int userYear);

private:
	double monthlyInterest;
	double yearlyInterestTotal;

	int tempYears;
	int tempMonth;

	vector<double> yearlyInterest;
	vector<double> yearlyInvestmentAmount;

	vector<vector<double>> tableNumbers;
	vector<vector<double>> tableNumbersNoDeposit;

};

