
#include <iostream>
#include <vector>
#include <string>
#include "../include/Customer.h"
#include "../include/Loan.h"


void showMenu() {
	std::cout << "\n===== Bank Loan Management System =====" << std::endl;
	std::cout << "1. Add New Customer" << std::endl;
	std::cout << "2. Create Loan for Customer" << std::endl;
	std::cout << "3. Display Customer Info & Loans" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cout << "\nMake A Choice: ";
}

int main()
{
	std::vector<Customer> customers;
	int choice;

	while (true) {
		showMenu();
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 1) {
			int id;
			std::string name, contactInfo;

			std::cout << "Enter Customer ID: ";
			std::cin >> id;
			std::cin.ignore();

			std::cout << "Enter Name: ";
			std::getline(std::cin, name);

			std::cout << "Enter Contact Info: ";
			std::getline(std::cin, contactInfo);

			Customer newCustomer(id, name, contactInfo);
			customers.push_back(newCustomer);

			std::cout << "Customer Created Successfully!\n";
		}
		else if (choice == 2) {
			int searchId;
			std::cout << "Enter Customer ID to add a loan: ";
			std::cin >> searchId;

			bool found = false;
			for (auto& customer : customers) {
				if (customer.getId() == searchId) {
					found = true;
					std::cout << "---- Customer Found ----" << std::endl;
					double principal, rate;
					int term;

					std::cout << "Enter loan principal: ";
					std::cin >> principal;

					std::cout << "Enter interest rate (%): ";
					std::cin >> rate;

					std::cout << "Enter number of monthly payments: ";
					std::cin >> term;

					Loan newLoan(principal, rate, term);
					customer.addLoan(newLoan);

				}
			}
			if (!found) {
				std::cout << "Customer not found. \n";
			}
		}
		else if (choice == 3) {
			for (const auto& customer : customers) {
				std::cout << "\n===========================\n";
				std::cout << "Customer ID: " << customer.getId() << "\n";
				std::cout << "Name: " << customer.getName() << "\n";
				std::cout << "Contact Info: " << customer.getContactInfo() << "\n";

				std::cout << "\n  -------- LOANS -------- \n";
				customer.displayAllLoans();
			}
		}
		else if (choice == 4) {
			std::cout << "Program Closing.." << std::endl;
			break;
		}
		else {
			std::cout << "Invalid choice. Try again." << std::endl;
		}
	}


	return 0;
}
