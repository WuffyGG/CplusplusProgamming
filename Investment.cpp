/*
 * Author: Daniel Urena
 * Date: 09/06/2024
 * Description:
 * Implementation of the Investment class which provides methods to calculate
 * investment balances with and without monthly deposits based on user input
 */

#include "Investment.h"
using namespace std;


Investment::Investment(double initial_investment, double monthly_deposit, double annual_interest, int years)
    : m_initial_investment(initial_investment),
    m_monthly_deposit(monthly_deposit),
    m_annual_interest(annual_interest),
    m_years(years) {}

// Private method to print investment details for a specific year
void Investment::printDetails(int year, double yearEndBalance, double interestEarned) const {
    cout << fixed << setprecision(2);
    cout << year << "\t\t$" << yearEndBalance << "\t\t$" << interestEarned << endl;
}
// Method to calculate balance without monthly deposits
double Investment::calculateBalanceWithoutMonthlyDeposit() const {
    double balance = m_initial_investment;
    double monthlyInterestRate = (m_annual_interest / 100) / 12;

    for (int year = 1; year <= m_years; year++) {
        double interestEarnedThisYear = 0.0;

        // Compound interest monthly for the entire year
        for (int month = 1; month <= 12; month++) {
            double interestForMonth = balance * monthlyInterestRate;
            balance += interestForMonth;
            interestEarnedThisYear += interestForMonth;
        }

        // Print the details for the year
        printDetails(year, balance, interestEarnedThisYear);
    }

    // Return the final balance after all years
    return balance;
}
// Method to calculate balance while considering monthly balance
double Investment::balanceWithMonthlyDeposit() const {
    double monthlyInterestRate = (m_annual_interest / 100) / 12;
    double balance = m_initial_investment;

    for (int year = 1; year <= m_years; ++year) {
        double interestEarnedThisYear = 0;

        // Compound interest for the entire year
        for (int month = 0; month < 12; ++month) {
            double interestThisMonth = balance * monthlyInterestRate;
            balance += interestThisMonth;
            interestEarnedThisYear += interestThisMonth;
            balance += m_monthly_deposit;
        }

        // Print the details for the year
        printDetails(year, balance, interestEarnedThisYear);
    }

    // Return the final balance after all years
    return balance;
}