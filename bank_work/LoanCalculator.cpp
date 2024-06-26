// LoanCalculator.cpp
#include "LoanCalculator.h"

int LoanCalculator::calculateLoanYearly(int principal, int years, float rate) {
    InterestCalculator calculator;
    return calculator.calculateYearlyTotal(principal, years, rate);
}

int LoanCalculator::calculateLoanMonthly(int principal, int years, float rate) {
    InterestCalculator calculator;
    return calculator.calculateMonthlyTotal(principal, years, rate);
}
