// PostOffice.cpp
#include "PostOffice.h"

int PostOffice::psavings = 0;

PostOffice::PostOffice() {
    savings = 0;
}

int PostOffice::save() {
    cout << endl << name << "����/�p�j�z�n,\n";
    cout << "�п�J�s(��)�ڪ��B(�t�ƪ�ܴ���): ";
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
    cout << "�ʺA���ͪ�����" << name << "���O����Ŷ��A�w�Q������k�ٵ��t��" << endl;
}
