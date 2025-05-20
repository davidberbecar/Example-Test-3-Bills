//
// Created by David Berbecar on 20.05.2025.
//

#include "Repository.h"
#include<sstream>
Repository::Repository() {
   readFromFile();
}

std::vector<std::string> tokenize(std::string line, char delimiter) {
   std::vector<std::string> tokens;
   std::stringstream ss{line};
   std::string token;
   while (std::getline(ss, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}

void Repository::readFromFile() {
   std::ifstream file("bills.txt");
   if (!file.is_open()) {
      std::ofstream("bills.txt");
   }
   std::string line;
   while (std::getline(file, line)) {
      std::vector<std::string> tokens = tokenize(line, ';');
      bool isPaid=false;
      if (tokens[3] == "true") {
         isPaid = true;
      }
      bills.push_back(Bill(tokens[0], tokens[1], std::stod(tokens[2]), isPaid));
   }
}



Repository::~Repository() {

}