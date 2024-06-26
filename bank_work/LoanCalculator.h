// LoanCalculator.h
#ifndef LOANCALCULATOR_H
#define LOANCALCULATOR_H

#include "InterestCalculator.h"

class LoanCalculator {
public:
    int calculateLoanYearly(int principal, int years, float rate);
    int calculateLoanMonthly(int principal, int years, float rate);
};

#endif
