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
    postOffices[0].name = "逸";
    postOffices[1].name = "鳴";
    InterestCalculator interestCalculator;
    LoanCalculator loanCalculator;

    int choose, customer;
    while (true) {
        cout << "1. 交易作業 2. 存提款作業 3. 存款利息計算 4. 貸款試算 0. 結束" << endl;
        cin >> choose;

        switch (choose) {
        case 0:
            return 0;
        case 1: {
            // 交易作業
            string account, password;
            cout << "請設定帳號：";
            cin >> account;
            cout << "請設定密碼：";
            cin >> password;
            transaction.setAccount(account, password);

            string inputAccount, inputPassword;
            cout << "請輸入帳號：";
            cin >> inputAccount;
            cout << "請輸入密碼：";
            cin >> inputPassword;
            if (transaction.verifyAccount(inputAccount, inputPassword)) {
                cout << "帳號密碼驗證通過！" << endl;
                string product;
                double price;
                char continueAdding;

                do {
                    cout << "請輸入商品名稱：";
                    cin >> product;
                    cout << "請輸入商品價格：";
                    cin >> price;
                    transaction.addProduct(product, price);

                    cout << "是否繼續添加商品？(Y/N)：";
                    cin >> continueAdding;
                } while (continueAdding == 'Y' || continueAdding == 'y');

                transaction.showProductList();
                transaction.settleTransaction();
            }
            else {
                cout << "帳號密碼驗證失敗！" << endl;
            }
            break;
        }
        case 2: {
            // 存提款作業
            cout << "\t存(提)款作業\n";
            cout << "輸入存戶編號(0: 0號存戶 1: 1號存戶): ";
            cin >> customer;

            if (customer == 0 || customer == 1) {
                int deposit = postOffices[customer].save();
                postOffices[customer].operate(deposit);
            }
            else {
                cout << "輸入錯誤\n";
            }

            cout << "1. 查詢個人的存款餘額 2. 查詢郵局的總存款 0. 返回" << endl;
            int subChoice;
            cin >> subChoice;
            if (subChoice == 1) {
                cout << postOffices[customer].name << "存戶之存款餘額為" << postOffices[customer].look() << endl;
            }
            else if (subChoice == 2) {
                cout << "\t郵局的總存款" << PostOffice::psavings << endl;
            }
            break;
        }
        case 3: {
            // 存款利息計算
            int money, years, yrate;
            float per_rate;
            cout << "==複利率本利和試算==\n";
            cout << "1. 輸入本金 : ";
            cin >> money;
            cout << "2. 輸入年利率(%) : ";
            cin >> yrate;
            cout << "3. 幾年後領回 : ";
            cin >> years;

            per_rate = static_cast<float>(yrate) / 100;
            cout << "***每年計息一次，" << years << "年後領回本利和 : " << interestCalculator.calculateYearlyTotal(money, years, per_rate) << endl;
            cout << "***每月計息一次，" << years << "年後領回本利和 : " << interestCalculator.calculateMonthlyTotal(money, years, per_rate) << endl;
            break;
        }
        case 4: {
            // 貸款試算
            int money, years, yrate;
            float per_rate;
            cout << "==貸款利息試算==\n";
            cout << "1. 輸入貸款本金 : ";
            cin >> money;
            cout << "2. 輸入年利率(%) : ";
            cin >> yrate;
            cout << "3. 貸款年限 : ";
            cin >> years;

            per_rate = static_cast<float>(yrate) / 100;
            cout << "***每年計息一次，" << years << "年後需償還本利和 : " << loanCalculator.calculateLoanYearly(money, years, per_rate) << endl;
            cout << "***每月計息一次，" << years << "年後需償還本利和 : " << loanCalculator.calculateLoanMonthly(money, years, per_rate) << endl;
            break;
        }
        default:
            cout << "輸入錯誤\n";
            break;
        }
    }

    return 0;
}
