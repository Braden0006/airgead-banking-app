#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Account {

public:
	Account();

	void SetInvestmentAmount(double amount);
	void SetMonthlyDeposit(double deposit);
	void SetAnnualInterest(double interest);
	void SetNumberYears(int year);
	void CalculateBalanceMonthly(double investmentAmount, double monthlyDeposit, double annualInterest, int numYears);

	double GetInvestmentAmount() const;
	double GetMonthlyDeposit() const;
	double GetAnnualInterest() const;
	int GetNumberYears() const;

private:
	double investmentAmount;
	double monthlyDeposit;
	double annualInterest;
	double monthlyInterest;
	double yearlyInterestTotal;

	int numYears;
	int tempYears;
	int tempMonth;

	vector<double> yearlyInterest;
	vector<double> yearlyInvestmentAmount;
	vector<int> yearNumber;

};

