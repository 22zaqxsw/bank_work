// InterestCalculator.cpp
#include "InterestCalculator.h"

int InterestCalculator::calculateYearlyTotal(int principal, int years, float rate) {
    return principal * pow(1 + rate, years);
}

int InterestCalculator::calculateMonthlyTotal(int principal, int years, float rate) {
    return principal * pow(1 + rate / 12, years * 12);
}
