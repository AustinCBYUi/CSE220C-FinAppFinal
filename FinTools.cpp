#include "FinTools.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>

double FinTools::calculate_paycheck( double rate, int hours ) {
	return rate * hours;
}

double FinTools::calculate_car_payment( double interest_rate, double amount, int term ) {
	char user_input;

	double monthly_interest_rate = ( interest_rate / 100 ) / 12;
	int total_payments = term * 12;
	double monthly_payment = ( amount * monthly_interest_rate * pow( 1 + monthly_interest_rate, total_payments )) /
		( pow( 1 + monthly_interest_rate, total_payments ) - 1 );

	std::cout << "Would you like a monthly breakdown? (Y/N): ";
	std::cin >> user_input;

	if ( user_input == 'Y' || user_input == 'y' ) {
		breakdown_payments( interest_rate, amount, monthly_payment );
	}

	return monthly_payment;
}

double FinTools::calculate_creditcard_payment( double interest_rate, double principle ) {
	double monthly_interest = (interest_rate / 12) / 100;
	double monthly_payment = monthly_interest * principle;
	return monthly_payment;
}

//Work on cc_payoff
void FinTools::calculate_cc_payoff(double interest_rate, double principle, double target) {
	double monthly_payment_min = calculate_creditcard_payment(interest_rate, principle);
	double payment_toward_principle = target - monthly_payment_min;
	double months_to_pay_bal = principle / payment_toward_principle;

	std::cout << "Monthly Interest: $" << monthly_payment_min << " | Payment to Principle: $" << payment_toward_principle << std::endl;
	std::cout << "Month || Payment To Principle || Principle Balance" << std::endl;
	for (double i = 0; i < months_to_pay_bal; i++) {
		principle = principle - payment_toward_principle;
		std::cout << "Month: " << i << " || $" << " || $" << payment_toward_principle << " || $" << round(principle) << std::endl;
	}
}

void FinTools::breakdown_payments(double interest_rate, double amount, double monthly_payment, int term) {
	double remaining_balance = amount;
	int month = 1;

	std::cout << std::fixed << std::setprecision( 2 );
	std::cout << "Month\tInterest\tPayment\t\tRemaining Balance\n";

	while ( remaining_balance > 0 ) {
		double monthly_interest = ( interest_rate / 12 ) / 100;
		double interest_payment = monthly_interest * remaining_balance;

		double actual_payment = (remaining_balance + interest_payment < monthly_payment) ? remaining_balance + interest_payment : monthly_payment;

		remaining_balance += interest_payment - actual_payment;

		std::cout << month << "\t$" << interest_payment << "\t\t$" << actual_payment << "\t\t$" << remaining_balance << "\n";

		month++;
	}
}

double FinTools::calculate_savings(int pay_interval, int term, double payment) {
	double total_saved;

	//Monthly
	if (pay_interval) {
		total_saved = (term * pay_interval) * payment;
		return total_saved;
	}
	else {
		std::cout << "There was an error processing the calculations, check your values." << std::endl;
	}
}