#include "../include/Customer.h"
#include "../include/Loan.h"
#include <iostream>

Customer::Customer(int id, const std::string& name, const std::string& contactInfo)
	: id(id), name(name), contactInfo(contactInfo) { }

int Customer::getId() const {
	return id;
}

std::string Customer::getName() const {
	return name;
}

std::string Customer::getContactInfo() const {
	return contactInfo;
}

void Customer::setName(const std::string& newName) {
	name = newName;
}

void Customer::setContactInfo(const std::string& newContactInfo) {
	contactInfo = newContactInfo;
}

void Customer::display() const {
	std::cout << "Customer ID: " << id << "\n"
		<< "Name: " << name << "\n"
		<< "Contact: " << contactInfo << "\n";
}

void Customer::addLoan(const Loan& loan) {
	loans.push_back(loan);
}

void Customer::displayAllLoans() const {
	if (loans.empty()) {
		std::cout << "No loans for this customer." << std::endl;
		return;
	}
	for (const auto& loan : loans) {
		loan.displayLoanSummary();
		std::cout << std::endl;
	}
}