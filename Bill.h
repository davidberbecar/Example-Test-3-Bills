//
// Created by David Berbecar on 20.05.2025.
//

#ifndef BILL_H
#define BILL_H
#include <string>


class Bill {
private:
    std::string companyName;
    std::string serialNumber;
    double sum;
    bool isPaid;
public:
    Bill(std::string companyName, std::string serialNumber, double sum, bool isPaid);
    ~Bill();
    std::string getCompanyName(){return companyName;};
    std::string getSerialNumber(){return serialNumber;};
    bool paid(){return isPaid;};
    double getSum(){return sum;};
    std::string toString();
};



#endif //BILL_H
