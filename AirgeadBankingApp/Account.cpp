#include "Account.h"
#include <iostream>
using namespace std;

// Default constructor
Account::Account() {
	tempYears = 0;
	tempMonth = 0;
	monthlyInterest = 0;
	yearlyInterestTotal = 0;
}

void Account::CalculateBalance(double investmentAmount, double monthlyDeposit, double annualInterest, int numYears) {
	
	while (tempYears != numYears) {

		monthlyInterest = (investmentAmount + monthlyDeposit) * ((annualInterest / 100) / 12);

		yearlyInterestTotal += monthlyInterest;
		investmentAmount += monthlyInterest;
		investmentAmount += monthlyDeposit;
		tempMonth += 1;

		if (tempMonth == 12) {
			tableNumbers.push_back({ investmentAmount, yearlyInterestTotal });

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