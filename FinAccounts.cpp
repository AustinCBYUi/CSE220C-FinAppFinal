#include "FinAccounts.h"
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <istream>

int FinancialAccounts::next_id = 1;
std::map<int, FinancialAccounts> FinancialAccounts::cc_accounts;

FinancialAccounts::FinancialAccounts() : account_id(-1), principle_balance(0.0f) {
	institution_name = "";
}

std::map<int, FinancialAccounts>& FinancialAccounts::get_ccaccounts_map() {
	return cc_accounts;
}

void FinancialAccounts::get_accounts()const {
	if (cc_accounts.empty()) {
		std::cout << "No CC Accounts are available..\n" << std::endl;
		return;
	}

	std::for_each(cc_accounts.begin(), cc_accounts.end(), [](const auto& pair) {
		const int& account_id = pair.first;
		const FinancialAccounts& account = pair.second;

		std::cout << "Accound ID: " << account_id << " | Institution Name: " << account.institution_name << " | Interest Rate: " << account.interest_rate << " | Principle Bal: $" << account.principle_balance << std::endl;
		});
	std::cout << "\n";
}

void FinancialAccounts::add_cc_account(const FinancialAccounts& account) {
	cc_accounts[account.account_id] = account;
}

void FinancialAccounts::find_account(int account_id) const {
	auto it = cc_accounts.find(account_id);
	if (it != cc_accounts.end()) {
		const FinancialAccounts& account = it->second;
		std::cout << "Found Account: Account ID: " << account_id << " | Institution Name: " << account.institution_name << " | Interest Rate: " << account.interest_rate << " | Principle Bal $" << account.principle_balance << std::endl;
	}
	else {
		std::cout << "Account with ID " << account_id << " was not found.\n" << std::endl;
	}
}

void FinancialAccounts::input_cc_account() {
	account_id = next_id++;
	std::string inst_name;
	std::string interest;
	std::string principle;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "Enter Institution Name: ";
	std::getline(std::cin, inst_name);
	std::cout << "Enter Interest Rate: ";
	std::getline(std::cin, interest);
	//Convert string to double
	std::cout << "Enter Principle Balance: $";
	std::getline(std::cin, principle);
	try {
		institution_name = inst_name;
		interest_rate = std::stod(interest);
		principle_balance = std::stod(principle);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "You must enter a number" << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Input was out of range" << std::endl;
	}
	std::cout << "\n";
}

void FinancialAccounts::WriteToStream(std::ostream& os) const {
	os << "Account ID: " << account_id << "\n"
		<< "Institution Name: " << institution_name << "\n"
		<< "Interest Rate: " << interest_rate << "\n"
		<< "Principle Balance: $" << principle_balance << "\n";
}

std::ostream& operator<< (std::ostream& os, const FinancialAccounts& account) {
	account.WriteToStream(os);
	return os;
}