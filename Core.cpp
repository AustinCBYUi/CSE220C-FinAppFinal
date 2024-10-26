#include "Core.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

//Static Variable Initialize
std::string Core::version = "v0.1";

//Constructor
Core::Core() {};


//Methods
void Core::display_core_menu() {
	std::cout << "Financial Application Menu " << version << std::endl;
	std::cout << "0 - Quit" << std::endl;
	std::cout << "1 - Financial Tools" << std::endl;
	std::cout << "2 - Create a Budget" << std::endl;
	std::cout << "3 - Credit Card / Loan Management" << std::endl;
	line_clear();
}

void Core::display_fintool_menu() {
	std::cout << "\n-> Financial Tools <-\n" << std::endl;
	std::cout << "0 - Exit to Core Menu" << std::endl;
	std::cout << "1 - Calculate a Paycheck" << std::endl;
	std::cout << "2 - Calculate a Car Payment" << std::endl;
	std::cout << "3 - Calculate Credit Card Payments" << std::endl;
	std::cout << "4 - Calculate CC Payoff" << std::endl;
	std::cout << "5 - Calculate Time to Save Up" << std::endl;
	line_clear();
}

void Core::display_cc_manager() {
	std::cout << "\n -> Credit Card / Loan Management Menu <-\n" << std::endl;
	std::cout << "0 - Exit to Core Menu" << std::endl;
	std::cout << "1 - Add a Credit Card Account" << std::endl;
	std::cout << "2 - Display A CC Account" << std::endl;
	std::cout << "3 - View all CC Accounts" << std::endl;
	line_clear();
}

void Core::line_clear() {
	std::cout << "\n";
}