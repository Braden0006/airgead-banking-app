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

void Account::CalculateInterest(double investmentAmount, double monthlyDeposit, double annualInterest, int numYears) {
	
	while (tempYears != numYears) {
		monthlyInterest = (investmentAmount + monthlyDeposit) * ((annualInterest / 100) / 12);
		tempYears = 5;
	}

	cout << monthlyInterest << endl;
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