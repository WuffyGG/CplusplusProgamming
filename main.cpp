/*
 * Author: Daniel Urena
 * Date: 09/06/2024
 * Description:
 * Main program for simulating investment growth. Collects user input for
 * and displays year-end balances with and without monthly deposits.
 */

#include <iostream>
#include "Investment.h"

using namespace std;

// Clears the input buffer
void clearInputBuffer() {
    cin.clear();
    while (cin.get() != '\n'); // Clear input buffer until newline
}
// Function to get a positive double input from user
double getPositiveInput(const string& prompt) {
    double input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail() || input <= 0) {
            cout << "Please enter a positive number.\n";
            clearInputBuffer();
        }
        else {
            clearInputBuffer();
            break;
        }
    }
    return input;
}
// Function to get a positive input from user
int getPositiveIntegerInput(const string& prompt) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (cin.fail() || input <= 0) {
            cout << "Please enter a positive integer.\n";
            clearInputBuffer();
        }
        else {
            clearInputBuffer();
            break;
        }
    }
    return input;
}

int main() {
    do {
        // Get user input while also displaying in a menu
        cout << "********** Data Input **********" << endl;
        double initial_investment = getPositiveInput("Enter initial investment amount: ");
        double monthly_deposit = getPositiveInput("Enter monthly deposit amount: ");
        double annual_interest = getPositiveInput("Enter annual interest rate (in %): ");
        int number_of_years = getPositiveIntegerInput("Enter number of years: ");
        cout << "********************************" << endl;

        // Create Investment object
        Investment investment(initial_investment, monthly_deposit, annual_interest, number_of_years);

        // Calculate and display results
        cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
        cout << "=======================================================\n";
        cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
        cout << "-------------------------------------------------------\n";
        investment.calculateBalanceWithoutMonthlyDeposit();

        cout << "\nBalance and Interest With Additional Monthly Deposits\n";
        cout << "=====================================================\n";
        cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
        cout << "-----------------------------------------------------\n";
        investment.balanceWithMonthlyDeposit();

        // Check if the user wants to run again
        cout << "\nDo you want to run the simulation again? (y/n): ";
        char choice;
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }

    } while (true);

    return 0;
}