#include "Account.h"
#include <iostream>
using namespace std;

// Default constructor
Account::Account() {
	investmentAmount = 0.0;
	monthlyDeposit = 0.0;
	interestRate = 0.0;
	numYears = 0;
	tempYears = 0;
	tempMonth = 0;
	monthlyInterest = 0;
	yearlyInterestTotal = 0;
}

void Account::SetInvestmentAmount(double investmentAmount) {
	this->investmentAmount = investmentAmount;
}

void Account::SetMonthlyDeposit(double monthlyDeposit) {
	this->monthlyDeposit = monthlyDeposit;
}

void Account::SetInterestRate(double interestRate) {
	this->interestRate = interestRate;
}

void Account::SetNumYears(int numYears) {
	this->numYears = numYears;
}

double Account::GetInvestmentAmount() const {
	return investmentAmount;
}

double Account::GetMonthlyDeposit() const {
	return monthlyDeposit;
}

double Account::GetInterestRate() const {
	return interestRate;
}

int Account::GetNumYears() const {
	return numYears;
}

void Account::CalculateBalance(double investmentAmount, double monthlyDeposit, double annualInterest, int numYears) {
	this->tempYears = 0;
	this->tempMonth = 0;
	
	while (tempYears != numYears) {

		monthlyInterest = (investmentAmount + monthlyDeposit) * ((annualInterest / 100) / 12);

		yearlyInterestTotal += monthlyInterest;
		investmentAmount += monthlyInterest;
		investmentAmount += monthlyDeposit;
		tempMonth += 1;

		if (tempMonth == 12) {
			this->tableNumbers.push_back({ investmentAmount, yearlyInterestTotal });

			tempYears += 1;
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
			tableNumbersNoDeposit.push_back({ investmentAmount, yearlyInterestTotal });

			tempYears += 1;
			monthlyInterest = 0;
			tempMonth = 0;
			yearlyInterestTotal = 0;
		}
	}
}

void Account::DisplayTable() const{
	for (int i = 0; i < tableNumbers.size(); ++i) {
		for (int j = 0; j < tableNumbers[i].size(); ++j) {
			cout << tableNumbers[i][j] << "            ";
		}
		cout << endl;
	}
}

void Account::DisplayTableNoDeposit() const {
	for (int i = 0; i < tableNumbersNoDeposit.size(); ++i) {
		for (int j = 0; j < tableNumbersNoDeposit[i].size(); ++j) {
			cout << tableNumbersNoDeposit[i][j] << "            ";
		}
		cout << endl;
	}
}

void Account::UserInput() {
	double userAmount;
	double userMonthlyDeposit;
	double userInterest;
	int userYear;

	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount:  ";
	cin >> userAmount;
	SetInvestmentAmount(userAmount);

	cout << "Monthly Deposit:  ";
	cin >> userMonthlyDeposit;
	SetMonthlyDeposit(userMonthlyDeposit);

	cout << "Annual Interest  ";
	cin >> userInterest;
	SetInterestRate(userInterest);

	cout << "Number of Years:  ";
	cin >> userYear;
	SetNumYears(userYear);

	cout << "Press any key to continue..." << endl;
}