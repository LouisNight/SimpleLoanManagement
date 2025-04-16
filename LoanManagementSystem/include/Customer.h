#pragma once
#include "../include/Loan.h"
#include <vector>
#include <string>

class Customer {
private:
	int id;
	std::string name;
	std::string contactInfo;
	std::vector<Loan> loans;

public:

	// we make this constructor so we can call Customer objects and initialize their info like Customer c1(01, "John Smith", "jsmith@whatever.com");
	Customer(int id, const std::string& name, const std::string& contactInfo);

	int getId() const;
	std::string getName() const;
	std::string getContactInfo() const;

	void setName(const std::string& newName);
	void setContactInfo(const std::string& newContactInfo);


	void addLoan(const Loan& loan);
	void displayAllLoans() const;

	// helper method to display all customer's info in console
	void display() const;

};