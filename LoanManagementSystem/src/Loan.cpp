#include "../include/Loan.h"
#include <cmath>
#include <iostream>
#include <iomanip>

Loan::Loan(double principal, double interestRate, int numberOfPayments)
	: principal(principal), interestRate(interestRate), numberOfPayments(numberOfPayments) { 
	monthlyPayment = calculateMonthlyPayment(principal, interestRate, numberOfPayments);
}

double Loan::calculateMonthlyPayment(double principal, double interestRate, int numberOfPayments) {
	double monthlyRate = (interestRate / 100) / 12.0;

	return (principal * monthlyRate) / (1 - std::pow(1 + monthlyRate, -numberOfPayments));
}

double Loan::getPrincipal() const {
	return principal;
}

double Loan::getInterestRate() const {
	return interestRate;
}

int Loan::getNumberOfPayments() const {
	return numberOfPayments;
}

double Loan::getMonthlyPayment() const {
	return monthlyPayment;
}

double Loan::calculateTotalPayment() const {
	return monthlyPayment * numberOfPayments;
}

double Loan::calculateTotalInterest() const {
	return calculateTotalPayment() - principal;
}

void Loan::displayLoanSummary() const {
	std::cout << std::fixed << std::setprecision(2);

	std::cout << "======== Loan Summary ========" << std::endl;
	std::cout << "Principal: $" << principal << std::endl;
	std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
	std::cout << "Loan Term: " << numberOfPayments << " months" << std::endl;
	std::cout << "Monthly Payment: $" << monthlyPayment << std::endl;
	std::cout << "Total Payment: $" << calculateTotalPayment() << std::endl;
	std::cout << "Total Interest Paid: $" << calculateTotalInterest() << std::endl;
	std::cout << "=============================" << std::endl;
}