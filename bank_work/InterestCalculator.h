// InterestCalculator.h
#ifndef INTERESTCALCULATOR_H
#define INTERESTCALCULATOR_H

#include <iostream>
#include <cmath>
using namespace std;

class InterestCalculator {
public:
    int calculateYearlyTotal(int principal, int years, float rate);
    int calculateMonthlyTotal(int principal, int years, float rate);
};

#endif
