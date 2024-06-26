// main.cpp
#include <iostream>
#include <string>
#include "Transaction.h"
#include "PostOffice.h"
#include "InterestCalculator.h"
#include "LoanCalculator.h"
using namespace std;

int main() {
    Transaction transaction;
    PostOffice postOffices[2];
    postOffices[0].name = "�h";
    postOffices[1].name = "��";
    InterestCalculator interestCalculator;
    LoanCalculator loanCalculator;

    int choose, customer;
    while (true) {
        cout << "1. ����@�~ 2. �s���ڧ@�~ 3. �s�ڧQ���p�� 4. �U�ڸպ� 0. ����" << endl;
        cin >> choose;

        switch (choose) {
        case 0:
            return 0;
        case 1: {
            // ����@�~
            string account, password;
            cout << "�г]�w�b���G";
            cin >> account;
            cout << "�г]�w�K�X�G";
            cin >> password;
            transaction.setAccount(account, password);

            string inputAccount, inputPassword;
            cout << "�п�J�b���G";
            cin >> inputAccount;
            cout << "�п�J�K�X�G";
            cin >> inputPassword;
            if (transaction.verifyAccount(inputAccount, inputPassword)) {
                cout << "�b���K�X���ҳq�L�I" << endl;
                string product;
                double price;
                char continueAdding;

                do {
                    cout << "�п�J�ӫ~�W�١G";
                    cin >> product;
                    cout << "�п�J�ӫ~����G";
                    cin >> price;
                    transaction.addProduct(product, price);

                    cout << "�O�_�~��K�[�ӫ~�H(Y/N)�G";
                    cin >> continueAdding;
                } while (continueAdding == 'Y' || continueAdding == 'y');

                transaction.showProductList();
                transaction.settleTransaction();
            }
            else {
                cout << "�b���K�X���ҥ��ѡI" << endl;
            }
            break;
        }
        case 2: {
            // �s���ڧ@�~
            cout << "\t�s(��)�ڧ@�~\n";
            cout << "��J�s��s��(0: 0���s�� 1: 1���s��): ";
            cin >> customer;

            if (customer == 0 || customer == 1) {
                int deposit = postOffices[customer].save();
                postOffices[customer].operate(deposit);
            }
            else {
                cout << "��J���~\n";
            }

            cout << "1. �d�߭ӤH���s�ھl�B 2. �d�߶l�����`�s�� 0. ��^" << endl;
            int subChoice;
            cin >> subChoice;
            if (subChoice == 1) {
                cout << postOffices[customer].name << "�s�ᤧ�s�ھl�B��" << postOffices[customer].look() << endl;
            }
            else if (subChoice == 2) {
                cout << "\t�l�����`�s��" << PostOffice::psavings << endl;
            }
            break;
        }
        case 3: {
            // �s�ڧQ���p��
            int money, years, yrate;
            float per_rate;
            cout << "==�ƧQ�v���Q�M�պ�==\n";
            cout << "1. ��J���� : ";
            cin >> money;
            cout << "2. ��J�~�Q�v(%) : ";
            cin >> yrate;
            cout << "3. �X�~���^ : ";
            cin >> years;

            per_rate = static_cast<float>(yrate) / 100;
            cout << "***�C�~�p���@���A" << years << "�~���^���Q�M : " << interestCalculator.calculateYearlyTotal(money, years, per_rate) << endl;
            cout << "***�C��p���@���A" << years << "�~���^���Q�M : " << interestCalculator.calculateMonthlyTotal(money, years, per_rate) << endl;
            break;
        }
        case 4: {
            // �U�ڸպ�
            int money, years, yrate;
            float per_rate;
            cout << "==�U�ڧQ���պ�==\n";
            cout << "1. ��J�U�ڥ��� : ";
            cin >> money;
            cout << "2. ��J�~�Q�v(%) : ";
            cin >> yrate;
            cout << "3. �U�ڦ~�� : ";
            cin >> years;

            per_rate = static_cast<float>(yrate) / 100;
            cout << "***�C�~�p���@���A" << years << "�~����v�٥��Q�M : " << loanCalculator.calculateLoanYearly(money, years, per_rate) << endl;
            cout << "***�C��p���@���A" << years << "�~����v�٥��Q�M : " << loanCalculator.calculateLoanMonthly(money, years, per_rate) << endl;
            break;
        }
        default:
            cout << "��J���~\n";
            break;
        }
    }

    return 0;
}
