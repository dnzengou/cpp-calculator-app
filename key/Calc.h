//
// Created by Anirudh Balasubramanian on 5/14/20.
//

#ifndef RHYMECALC_CALC_H
#define RHYMECALC_CALC_H


#include <string>

class Calc {
public:
// Big 3, for memory management
    Calc(int val); // we create a variable val for the class Calc (or any other class as needed)
    Calc(const Calc &rhs); // & indicate le adresse in memory
    ~Calc(); // ~ indicates that the newly created element will be destroyed in memory
    const Calc &operator=(const Calc &rhs);
    double process(std::string userInput, double prevValue);
    void print();
    std::string* storedExpressions;
    void setStored(size_t newStored);
    size_t getStored();
private:
    size_t stored;
};


#endif //RHYMECALC_CALC_H
