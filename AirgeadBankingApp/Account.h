#pragma once
class Account {

public:
	Account();
	void displayMenu() const;

	void SetInvestmentAmount(double amount);
	void SetMonthlyDeposit(double deposit);
	void SetAnnualInterest(double interest);
	void SetNumberYears(int year);
	void CalculateInterest(double investmentAmount, double monthlyDeposit, double annualInterest, int numYears);

	double GetInvestmentAmount() const;
	double GetMonthlyDeposit() const;
	double GetAnnualInterest() const;
	int GetNumberYears() const;

private:
	double investmentAmount;
	double monthlyDeposit;
	double annualInterest;
	double monthlyInterest;

	int numYears;
	int tempYears;
};

