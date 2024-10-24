/*
 * Author: Daniel Urena
 * Date: 09/06/2024
 * Description:
 * Header file for the Investment class, which provides methods to calculate
 * investment balances with and without monthly deposits based on user input
 */

#ifndef INVESTMENT_H_
#define INVESTMENT_H_

#include <iostream>
#include <iomanip>

// Class for calculating balance without monthly deposit and class with monthly deposit
class Investment {
public:
    // Initializes parameters
    Investment(double initial_investment, double monthly_deposit, double annual_interest, int years);
    // Method to calculate the balance without monthly deposits
    double calculateBalanceWithoutMonthlyDeposit() const;
    // Method to calculate the balance with monthly deposits
    double balanceWithMonthlyDeposit() const;

private:
    // Prints out investment details 
    void printDetails(int year, double yearEndBalance, double interestEarned) const;

    double m_initial_investment; // Initial amount invested
    double m_monthly_deposit;  // Monthly deposit amount
    double m_annual_interest;  // Annual interest rate
    int m_years;  // Investment duration in years
};

#endif // INVESTMENT_H_