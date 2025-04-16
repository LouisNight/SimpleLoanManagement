#pragma once


class Loan {
private:
	double principal;
	double interestRate;
	double monthlyPayment;
	int numberOfPayments;

	double calculateMonthlyPayment(double principal, double interestRate, int numberOfPayments);

public:

	Loan(double principal, double interestRate, int numberOfPayments);

	double getPrincipal() const;
	double getInterestRate() const;
	int getNumberOfPayments() const;
	double getMonthlyPayment() const;

	
	double calculateTotalPayment() const;
	double calculateTotalInterest() const;

	void displayLoanSummary() const;

};