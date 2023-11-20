#pragma once
class Account {

public:
	Account();
	void displayMenu() const;

	void SetInvestmentAmount(double amount);
	void SetMonthlyDeposit(double deposit);
	void SetAnnualInterest(double interest);

	double GetInvestmentAmount() const;
	double GetMonthlyDeposit() const;
	double GetAnnualInterest() const;

private:
	double investmentAmount;
	double monthlyDeposit;
	double annualInterest;
	int numYears;
};

