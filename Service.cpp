//
// Created by David Berbecar on 20.05.2025.
//

#include "Service.h"

Service::Service(Repository& repo) : repo{repo} {

}

std::vector<Bill> Service::getAllBills() {
    std::vector<Bill> bills = repo.getBills();
    std::sort(bills.begin(),bills.end(),[](Bill a, Bill b){return a.getCompanyName() < b.getCompanyName();});
    return bills;
}

std::vector<Bill> Service::getPaidBills() {
    std::vector<Bill> bills = repo.getBills();
    std::vector<Bill> paidBills;
    for (auto bill: bills) {
        if (bill.paid()) {
            paidBills.push_back(bill);
        }
    }
    return paidBills;
}


std::vector<Bill> Service::getUnpaidBills() {
    std::vector<Bill> bills = repo.getBills();
    std::vector<Bill> paidBills;
    for (auto bill: bills) {
        if (!bill.paid()) {
            paidBills.push_back(bill);
        }
    }
    return paidBills;
}

double Service::getCompanyTotal(std::string companyName) {
    std::vector<Bill> bills = repo.getBills();
    double total = 0;
    for (auto bill: bills) {
        if (bill.getCompanyName() == companyName) {
            total += bill.getSum();
        }
    }
    if (total == 0) {
        throw std::invalid_argument("No bills for this company");
    }
    return total;
}

Service::~Service() =default;