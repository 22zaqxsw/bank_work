// PostOffice.h
#ifndef POSTOFFICE_H
#define POSTOFFICE_H

#include <iostream>
#include <string>
using namespace std;

class PostOffice {
private:
    int savings;
public:
    string name;
    static int psavings;
    PostOffice();
    int save();
    static void operate(int money);
    int look();
    ~PostOffice();
};

#endif
