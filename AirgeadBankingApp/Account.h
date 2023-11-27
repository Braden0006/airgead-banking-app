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

	void SetInvestmentAmount(double investmentAmount);
	void SetMonthlyDeposit(double monthlyDeposit);
	void SetInterestRate(double interestRate);
	void SetNumYears(int numYears);

	double GetInvestmentAmount() const;
	double GetMonthlyDeposit() const;
	double GetInterestRate() const;
	int GetNumYears() const;

private:
	double monthlyInterest;
	double yearlyInterestTotal;
	double investmentAmount;
	double monthlyDeposit;
	double interestRate;

	int tempYears;
	int tempMonth;
	int numYears;

	vector<double> yearlyInterest;
	vector<double> yearlyInvestmentAmount;

	vector<vector<double>> tableNumbers;
	vector<vector<double>> tableNumbersNoDeposit;

};

