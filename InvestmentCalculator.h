#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H

#include <string>

class InvestmentCalculator {
public:
    InvestmentCalculator(double initialAmount, double monthlyDeposit, double annualInterest, int years);
    std::string calculateMonthlyInterest(bool includeMonthlyDeposit); 
    void displayInvestmentGrowth(); 

private:
    double initialAmount;
    double monthlyDeposit;
    double annualInterest;
    int years;
    
};

#endif // INVESTMENTCALCULATOR_H
