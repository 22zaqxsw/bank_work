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
    cout << "商品列表：" << endl;
    for (int i = 0; i < numProducts_; i++) {
        cout << i + 1 << ". " << products_[i] << " 價格：" << prices_[i] << endl;
    }
}

void Transaction::settleTransaction() {
    double totalAmount = 0.0;
    cout << "已選購的商品及價格：" << endl;
    for (int i = 0; i < numProducts_; i++) {
        cout << products_[i] << " 價格：" << prices_[i] << endl;
        totalAmount += prices_[i];
    }
    cout << "總金額：" << totalAmount << endl;
}
