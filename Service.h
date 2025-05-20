//
// Created by David Berbecar on 20.05.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "Repository.h"


class Service {
private:
    Repository& repo;
public:
    Service(Repository& repo);
    ~Service();
    std::vector<Bill>getPaidBills();
    std::vector<Bill>getUnpaidBills();
    std::vector<Bill>getAllBills();
    double getCompanyTotal(std::string companyName);
};



#endif //SERVICE_H
