#include "InvestmentCalculator.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using namespace std;

InvestmentCalculator::InvestmentCalculator(double initialAmount, double monthlyDeposit, double annualInterest, int years)
    : initialAmount(initialAmount), monthlyDeposit(monthlyDeposit), annualInterest(annualInterest), years(years) {}

string InvestmentCalculator::calculateMonthlyInterest(bool includeMonthlyDeposit) {
    stringstream output;
    double balance = initialAmount;
    double totalInterest = 0.0;
    double monthlyInterestRate = annualInterest / 100 / 12;
    
    output << fixed << setprecision(2);
    for (int year = 1; year <= years; ++year) {
        double yearlyInterest = 0.0;
        for (int month = 1; month <= 12; ++month) {
            if (includeMonthlyDeposit) {
                balance += monthlyDeposit;
            }
            double monthlyInterest = balance * monthlyInterestRate;
            yearlyInterest += monthlyInterest;
            balance += monthlyInterest;  // Add the interest to the balance
        }
        output << " " << left << setw(5) << year << "\t\t$" << setw(20) << balance
               << "\t\t$" << yearlyInterest << endl;
        totalInterest += yearlyInterest;  // Keep a running total of the interest earned
    }
    return output.str();
}

void InvestmentCalculator::displayInvestmentGrowth() {
    // Display table for the scenario without additional monthly deposits
    cout << endl << "     Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << string(66, '=') << endl;
    cout << "Year          Year End Balance          Year End Earned Interest" << endl;
    cout << string(66, '-') << endl;
    cout << calculateMonthlyInterest(false); // The calculation includes formatting for each line

    // Add a space between tables
    cout << endl << endl;

    // Display table for the scenario with additional monthly deposits
    cout << "     Balance and Interest With Additional Monthly Deposits" << endl;
    cout << string(66, '=') << endl;
    cout << "Year          Year End Balance          Year End Earned Interest" << endl;
    cout << string(66, '-') << endl;
    cout << calculateMonthlyInterest(true); // The calculation includes formatting for each line
}

int main() {
    double initialAmount, monthlyDeposit, annualInterest;
    int years;

    cout << "Enter initial investment amount: $";
    cin >> initialAmount;

    cout << "Enter monthly deposit: $";
    cin >> monthlyDeposit;

    cout << "Enter annual interest: %";
    cin >> annualInterest;

    cout << "Enter number of years: ";
    cin >> years;

    // Clear the input buffer to handle any leftover input from the user
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    InvestmentCalculator calculator(initialAmount, monthlyDeposit, annualInterest, years);

    cout << "**********************************" << endl;
    cout << "*********** Data Input ***********" << endl;
    cout << "Initial Investment Amount: $" << initialAmount << endl;
    cout << "Monthly Deposit: $" << monthlyDeposit << endl;
    cout << "Annual Interest: %" << annualInterest << endl;
    cout << "Number of years: " << years << " years" << endl;
    cout << "Press any key to continue..." << endl;

    // Wait for user input to continue
    cin.get();

    // Calculate and display both scenarios
    calculator.displayInvestmentGrowth();

    return 0;
}
