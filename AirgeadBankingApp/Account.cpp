#include "Account.h"
#include <iostream>
using namespace std;

// Default constructor
Account::Account() {
	investmentAmount = 0.0;
	monthlyDeposit = 0.0;
	annualInterest = 0.0;
	numYears = 0;
}

void Account::displayMenu() const{
	cout << "Hello there world!" << endl;
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

double Account::GetInvestmentAmount() const {
	return investmentAmount;
}

double Account::GetMonthlyDeposit() const {
	return monthlyDeposit;
}

double Account::GetAnnualInterest() const {
	return annualInterest;
}