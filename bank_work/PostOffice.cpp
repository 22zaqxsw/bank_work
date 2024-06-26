// PostOffice.cpp
#include "PostOffice.h"

int PostOffice::psavings = 0;

PostOffice::PostOffice() {
    savings = 0;
}

int PostOffice::save() {
    cout << endl << name << "先生/小姐您好,\n";
    cout << "請輸入存(提)款金額(負數表示提款): ";
    int money;
    cin >> money;
    savings += money;
    return money;
}

void PostOffice::operate(int money) {
    psavings += money;
}

int PostOffice::look() {
    return savings;
}

PostOffice::~PostOffice() {
    cout << "動態產生的物件" << name << "之記憶體空間，已被釋放並歸還給系統" << endl;
}
