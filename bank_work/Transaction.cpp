// Transaction.cpp
#include "Transaction.h"

void Transaction::setAccount(string& account, string& password) {
    account_ = account;
    password_ = password;
}

bool Transaction::verifyAccount(const string& account, const string& password) {
    return (account == account_ && password == password_);
}

void Transaction::addProduct(const string& product, double price) {
    products_[numProducts_] = product;
    prices_[numProducts_] = price;
    numProducts_++;
}

void Transaction::showProductList() {
    cout << "�ӫ~�C��G" << endl;
    for (int i = 0; i < numProducts_; i++) {
        cout << i + 1 << ". " << products_[i] << " ����G" << prices_[i] << endl;
    }
}

void Transaction::settleTransaction() {
    double totalAmount = 0.0;
    cout << "�w���ʪ��ӫ~�λ���G" << endl;
    for (int i = 0; i < numProducts_; i++) {
        cout << products_[i] << " ����G" << prices_[i] << endl;
        totalAmount += prices_[i];
    }
    cout << "�`���B�G" << totalAmount << endl;
}
