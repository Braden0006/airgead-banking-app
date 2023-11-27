#include "Account.h"
#include <iostream>
#include <iomanip>
#include <string>
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

// Set functions
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

// Get functions
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

// Calculates the yearly end balance and interest rate with the monthly deposit
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
			tableNumbers.push_back({ investmentAmount, yearlyInterestTotal});

			tempYears += 1;
			monthlyInterest = 0;
			tempMonth = 0;
			yearlyInterestTotal = 0;
		}
	}
}

// Calculates the yearly end balance and earned interest rate without the monthly deposit
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

// Displays a table with the additional monthly deposits
void Account::DisplayTable() const{
	int width = 29;

	cout << setw((width + 10) / 2) << "    Balance and Interest With Additional Monthly Deposits    " << endl;
	cout << setw(32) << "-------------------------------------------------------------" << endl;
	cout << setw(32) << "-------------------------------------------------------------" << endl;

	cout << "Year" << setw(28) << "Year End Balance" << setw(28) << "Year End Earned Interest" << endl;
	cout << setw(32) << "-------------------------------------------------------------" << endl;

	for (int i = 0; i < tableNumbers.size(); ++i) {
		cout << i + 1;

		for (int j = 0; j < tableNumbers[i].size(); ++j) {
			cout << setw(31) << fixed << setprecision(2) << tableNumbers[i][j];
		}
		cout << endl;
		cout << endl;
	}
}

// Displays a table without the additional monthly deposits
void Account::DisplayTableNoDeposit() const {
	int width = 29;

	cout << setw((width + 10) / 2) << "    Balance and Interest Without Additional Monthly Deposits    " << endl;
	cout << setw(32) << "-------------------------------------------------------------" << endl;
	cout << setw(32) << "-------------------------------------------------------------" << endl;

	cout << "Year" << setw(28) << "Year End Balance" << setw(28) << "Year End Earned Interest" << endl;
	cout << setw(32) << "-------------------------------------------------------------" << endl;

	for (int i = 0; i < tableNumbersNoDeposit.size(); ++i) {
		cout << i + 1;

		for (int j = 0; j < tableNumbersNoDeposit[i].size(); ++j) {
			cout << setw(30) << fixed << setprecision(2) << tableNumbersNoDeposit[i][j];
		}
		cout << endl;
		cout << endl;
	}
}

// Displays directions and stores user input
void Account::UserInput() {
	string userAmount;
	string userMonthlyDeposit;
	string userInterest;
	int userYear;

	bool isNum = true;

	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount:  ";
	cin >> userAmount;

	// Checks to see if the user investment amount is valid
	while (isNum) {
		if (userAmount[0] == '$') {
			if (stod(userAmount.substr(1)) > 0.0) {
				SetInvestmentAmount(stod(userAmount.substr(1)));
				break;
			}
			else {
				cout << endl;
				cout << "Please enter a value of 1 or more:  ";
				cin >> userAmount;
			}
		}
		else {
			cout << endl;
			cout << "Please enter a valid investment amount:  ";
			cin >> userAmount;
		}
	}

	cout << "Monthly Deposit:  ";
	cin >> userMonthlyDeposit;

	// Checks to see if the user monthly deposit amount is valid
	while (isNum) {
		if (userMonthlyDeposit[0] == '$') {

			if (stod(userMonthlyDeposit.substr(1)) > 0.0) {
				SetMonthlyDeposit(stod(userMonthlyDeposit.substr(1)));
				break;
			}
			else {
				cout << endl;
				cout << "Please enter a monthly deposit amount of 1 or more:  ";
				cin >> userMonthlyDeposit;
			}
		}
		else {
			cout << endl;
			cout << "Please enter a valid monthly deposit:  ";
			cin >> userMonthlyDeposit;
		}
	}

	cout << "Annual Interest  ";
	cin >> userInterest;

	// Checks to see if the user interest rate is valid
	while (isNum) {
		if (userInterest[0] == '%') {

			if (stod(userInterest.substr(1)) > 0.0) {
				SetInterestRate(stod(userInterest.substr(1)));
				break;
			}
			else {
				cout << endl;
				cout << "Please enter an interest percentage amount of 0.1 or more:  ";
				cin >> userInterest;
			}
		}
		else {
			cout << endl;
			cout << "Please enter a valid interest percentage:  ";
			cin >> userInterest;
		}
	}

	cout << "Number of Years:  ";
	cin >> userYear;

	// Checks to see if the user year is valid
	while (isNum) {
		if (userYear > 0) {
			SetNumYears(userYear);
			break;
		}
		else {
			cout << endl;
			cout << "Please enter a valid year:  ";
			cin >> userYear;
		}
	}

	cout << "Press any key to continue..." << endl;
	cout << endl;
}