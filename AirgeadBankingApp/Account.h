#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Account {

public:
	Account();

	// Initialized all public member functions
	void CalculateBalance(double investmentAmount, double monthlyDeposit, double annualInterest, int numYears);
	void CalculateBalanceNoDeposit(double investmentAmount, double annualInterest, int numYears);
	void DisplayTable() const;
	void DisplayTableNoDeposit() const;
	void UserInput();

	void SetInvestmentAmount(double investmentAmount);
	void SetMonthlyDeposit(double monthlyDeposit);
	void SetInterestRate(double interestRate);
	void SetNumYears(int numYears);

	double GetInvestmentAmount() const;
	double GetMonthlyDeposit() const;
	double GetInterestRate() const;
	int GetNumYears() const;

private:

	// Initialized all private variables
	double monthlyInterest;
	double yearlyInterestTotal;
	double investmentAmount;
	double monthlyDeposit;
	double interestRate;

	int tempYears;
	int tempMonth;
	int numYears;

	// Initialized vector variables store table calculations
	vector<vector<double>> tableNumbers;
	vector<vector<double>> tableNumbersNoDeposit;
};

