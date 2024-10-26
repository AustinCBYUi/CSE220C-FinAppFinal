// FinancialApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Core.h"
#include "FinTools.h"
#include "FinAccounts.h"
#include <iostream>
#include <windows.h>

int main()
{
    std::map<int, FinancialAccounts> cc_accounts;
    //Console Color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);

    int user_input;
    bool quit_program = false;
    Core core;

    while (!quit_program) {
        core.display_core_menu();
        std::cout << ">> ";
        std::cin >> user_input;
        core.line_clear();

        switch (user_input) {
        case 0:
            std::cout << "Exiting Program" << std::endl;
            quit_program = true;
            break;

        case 1: {
            int user_input_nested;
            bool quit_nested_menu = false;

            while (!quit_nested_menu) {
                core.display_fintool_menu();
                std::cout << ">> ";
                std::cin >> user_input_nested;
                core.line_clear();

                switch (user_input_nested) {
                case 0:
                    std::cout << "Exiting Financial Tools Menu.." << std::endl;
                    quit_nested_menu = true;
                    break;
                    // Calculate Paycheck
                case 1: {
                    FinTools paycheck;
                    double hourly_rate;
                    int hours_worked;

                    std::cout << "Hourly Rate: ";
                    std::cin >> hourly_rate;
                    std::cout << "Hours Worked: ";
                    std::cin >> hours_worked;

                    std::cout << "Gross: $" << paycheck.calculate_paycheck(hourly_rate, hours_worked) << std::endl;

                    break;
                }
                      // Calculate car payment
                case 2: {
                    FinTools car_payment;
                    double interest;
                    double amount;
                    int term;

                    std::cout << "Total Purchase Amount: $";
                    std::cin >> amount;
                    std::cout << "Interest Rate %: ";
                    std::cin >> interest;
                    std::cout << "Term in Years: ";
                    std::cin >> term;

                    std::cout << "Monthly Payment: $" << car_payment.calculate_car_payment(interest, amount, term) << std::endl;
                    break;
                }
                      // Calculate CC Payment
                case 3: {
                    FinTools card_payment;
                    double interest_rate;
                    double principle;

                    std::cout << "Total CC Principle Balance: $";
                    std::cin >> principle;
                    std::cout << "CC interest rate: ";
                    std::cin >> interest_rate;

                    double cc_payment = card_payment.calculate_creditcard_payment(interest_rate, principle);

                    std::cout << "Credit Card Payment: $" << cc_payment;
                    std::cout << "\n" << std::endl;
                    break;
                }
                case 4: {
                    FinTools CCPayoff;
                    double interest;
                    double principle;
                    double target;

                    std::cout << "What is the CC Principle Balance?: $";
                    std::cin >> principle;
                    std::cout << "What is the CC Interest Rate?: ";
                    std::cin >> interest;
                    std::cout << "What is your target payment per month?: $";
                    std::cin >> target;

                    CCPayoff.calculate_cc_payoff(interest, principle, target);

                    break;
                }
                      // Calculate Time to Save Up
                case 5: {
                    FinTools savings;
                    int pay_interval;
                    int term;
                    double payment_amount;

                    std::cout << "What term would you like (in months): ";
                    std::cin >> term;
                    std::cout << "How frequently are you adding to savings? (1=Monthly|2=BiWeekly|4=Weekly): ";
                    std::cin >> pay_interval;
                    std::cout << "How much saved per interval?: $";
                    std::cin >> payment_amount;

                    double saved_amount = savings.calculate_savings(pay_interval, term, payment_amount);

                    std::cout << "You will save $" << saved_amount << " in " << term << " months.\n" << std::endl;
                    break;
                }
                }
            }
            //End of Case 1 (Financial Tools Menu)
            break;
        }
        case 2:
            break;
        case 3: {
            int user_input_accounts;
            bool quit_nested_accounts = false;

            while (!quit_nested_accounts) {
                core.display_cc_manager();
                std::cout << ">> ";
                std::cin >> user_input_accounts;
                core.line_clear();

                switch (user_input_accounts) {
                    //Quit
                case 0:
                    quit_nested_accounts = true;
                    break;
                    //Add a CC Account
                case 1: {
                    FinancialAccounts create_cc;
                    create_cc.input_cc_account();
                    create_cc.add_cc_account(create_cc);
                    std::cout << create_cc << std::endl;
                    break;
                }
                      //Display A CC Account
                case 2: {
                    FinancialAccounts acc;
                    int account_id;
                    std::cout << "\nEnter the account ID: ";
                    std::cin >> account_id;
                    acc.find_account(account_id);
                    break;
                }
                      //Display all CC Accounts
                case 3: {
                    FinancialAccounts acc;
                    acc.get_accounts();
                    break;
                }
                }
            }
        }
        }
    }
}