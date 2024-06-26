// Transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
using namespace std;

class Transaction {
public:
    void setAccount(string& account, string& password);
    bool verifyAccount(const string& account, const string& password);
    void addProduct(const string& product, double price);
    void showProductList();
    void settleTransaction();

private:
    string account_;
    string password_;
    string products_[100];
    double prices_[100];
    int numProducts_ = 0;
};

#endif
