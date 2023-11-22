#include "Account.h"
#include <iostream>
using namespace std;

// Default constructor
Account::Account() {
	investmentAmount = 0.0;
	monthlyDeposit = 0.0;
	annualInterest = 0.0;
	numYears = 0;
	tempYears = 0;
}

void Account::SetInvestmentAmount(double amount) {
	investmentAmount = amount;
}

void Account::SetMonthlyDeposit(double deposit) {
	monthlyDeposit = deposit;
}

void Account::SetAnnualInterest(double interest) {
	annualInterest = interest;
}

void Account::SetNumberYears(int year) {
	numYears = year;
}

void Account::CalculateBalance(double investmentAmount, double monthlyDeposit, double annualInterest, int numYears) {
	
	while (tempYears != numYears) {

		monthlyInterest = (investmentAmount + monthlyDeposit) * ((annualInterest / 100) / 12);

		yearlyInterestTotal += monthlyInterest;
		investmentAmount += monthlyInterest;
		investmentAmount += monthlyDeposit;
		tempMonth += 1;

		if (tempMonth == 12) {
			yearlyInterest.push_back(yearlyInterestTotal);
			yearlyInvestmentAmount.push_back(investmentAmount);

			tempYears += 1;

			yearNumber.push_back(tempYears);

			monthlyInterest = 0;
			tempMonth = 0;
			yearlyInterestTotal = 0;
		}
	}
}

void Account::CalculateBalanceNoDeposit(double investmentAmount, double annualInterest, int numYears) {

	while (tempYears != numYears) {

		monthlyInterest = (investmentAmount) * ((annualInterest / 100) / 12);

		yearlyInterestTotal += monthlyInterest;
		investmentAmount += monthlyInterest;
		tempMonth += 1;

		if (tempMonth == 12) {
			yearlyInterest.push_back(yearlyInterestTotal);
			yearlyInvestmentAmount.push_back(investmentAmount);

			tempYears += 1;

			yearNumber.push_back(tempYears);

			monthlyInterest = 0;
			tempMonth = 0;
			yearlyInterestTotal = 0;
		}
	}

	for (unsigned i = 0; i < yearlyInvestmentAmount.size(); ++i) {
		cout << yearlyInvestmentAmount[i] << endl;
	}
}

double Account::GetInvestmentAmount() const {
	return investmentAmount;
}

double Account::GetMonthlyDeposit() const {
	return monthlyDeposit;
}

double Account::GetAnnualInterest() const {
	return annualInterest;
}

int Account::GetNumberYears() const {
	return numYears;
}