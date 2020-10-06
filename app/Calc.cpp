//
//

//#include <iostream>
//#include "Calc.h"
//#include "stddef.h"
//#include <cmath>

Calc::Calc(int values){
}

Calc::Calc(const Calc &rhs) {
}

Calc::~Calc() {
}

const Calc &Calc::operator=(const Calc &rhs) {
}

double Calc::process(std::string userInput, double prevValue) {
    //First cleanse
    std::string cleansedString = "";
    for(size_t i = 0; i < userInput.size(); ++i) {
        if (userInput[i] == '=' || userInput[i] == ' ' || userInput[i] == '(' || userInput[i] == ')') {
        } else {
            cleansedString += userInput[i];
        }
    }
  }

void Calc::print() {
    std::cout << "You have " << stored << " expressions stored: ";
    for(size_t i = 0; i < stored; ++i){
        std::cout << "Expression " << i + 1 << ":\n";
        std::cout << storedExpressions[i] << std::endl;
    }
}


void Calc::setStored(size_t newStored) {
    stored = newStored;
}

size_t Calc::getStored() {
    return stored;
}
