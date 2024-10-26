#ifndef FINTOOLS_HPP
#define FINTOOLS_HPP
#include <string>
#include <cmath>
#include <map>

class FinTools {
private:
public:
	/// <summary>
	/// Calculates a paycheck for hourly employees, does not implement overtime.
	/// </summary>
	/// <param name="rate">Hourly earnings</param>
	/// <param name="hours">Hours worked</param>
	/// <returns>Gross amount earned</returns>
	double calculate_paycheck(double rate, int hours);

	/// <summary>
	/// Calculates a car payment and offers monthly breakdown.
	/// </summary>
	/// <param name="interest_rate">Interest rate of loan</param>
	/// <param name="amount">Principle balance of loan</param>
	/// <param name="term">Term in years</param>
	/// <returns>Monthly payment of vehicle</returns>
	double calculate_car_payment(double interest_rate, double amount, int term);

	/// <summary>
	/// Calculates the minimum monthly credit card payment based off principle and interest.
	/// </summary>
	/// <param name="interest_rate">Interest rate of credit card</param>
	/// <param name="principle">Principle balance of credit card</param>
	/// <returns>Minimum monthly payment based off interest.</returns>
	double calculate_creditcard_payment(double interest_rate, double principle);

	/// <summary>
	/// Calculates a credit card total payoff with breakdown to stimulate a payoff.
	/// </summary>
	/// <param name="interest_rate">Interest rate of credit card</param>
	/// <param name="principle">Principle balance of credit card</param>
	/// <param name="target">Target payment the user would like to pay per month</param>
	void calculate_cc_payoff(double interest_rate, double principle, double target);
	
	/// <summary>
	/// Breaks down payments utilizing a loop, can be used for other loan types.
	/// </summary>
	/// <param name="interest_rate">Interest rate of loan</param>
	/// <param name="principle">Principle balance of loan</param>
	/// <param name="monthly_payment">Minimum monthly payment</param>
	/// <param name="term">Term in months</param>
	void breakdown_payments(double interest_rate, double principle, double monthly_payment, int term=NULL);

	/// <summary>
	/// Simple savings calculator.
	/// </summary>
	/// <param name="pay_interval">Interval for adding to savings (weekly, bi-weekly, monthly)</param>
	/// <param name="term">Term for savings in months (Want to save for X amount of months)</param>
	/// <param name="payment">Amount of money saved per interval</param>
	/// <returns>Amount of money saved over X amount of time.</returns>
	double calculate_savings(int pay_interval, int term, double payment);
};


#endif // FINTOOLS_HPP