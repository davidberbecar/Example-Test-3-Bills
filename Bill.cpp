//
// Created by David Berbecar on 20.05.2025.
//

#include "Bill.h"

Bill::Bill(std::string companyName, std::string serialNumber, double sum, bool isPaid):
companyName{companyName}, serialNumber{serialNumber}, sum{sum},isPaid{isPaid}
{

}

std::string Bill::toString() {
    return this->companyName+ "\t"+ std::to_string(this->sum);
}

Bill::~Bill() {

}