//
// Created by David Berbecar on 20.05.2025.
//

#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "Bill.h"
#include<vector>
#include<fstream>

class Repository {
private:
    std::vector<Bill>bills;
    void readFromFile();
public:
    Repository();
    ~Repository();
    std::vector<Bill>getBills(){return bills;};
};



#endif //REPOSITORY_H
