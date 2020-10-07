//
// Created by Anirudh Balasubramanian on 5/14/20.
//

#include <iostream>
#include "Calc.h"
#include "stddef.h"
#include <cmath>

Calc::Calc(int values):storedExpressions(new std::string[values]), stored(0){
}

Calc::Calc(const Calc &rhs) { // constructor
    if(storedExpressions != nullptr){
        storedExpressions = new std::string[rhs.stored];
        // we assign storedExpression to a new string array of size rhs.stored
        // (with rhs being what we are tryin to copy)
    }
}

Calc::~Calc() { // destructor
    delete[] storedExpressions;
    storedExpressions = nullptr;
    stored = 0; // stored is not holding any value after deletion
}

const Calc &Calc::operator=(const Calc &rhs) { // the copy assignment operator tries to make sure that 
// you are not assigning two identical objects to one another
    if(this != &rhs){ // *this* indicates *this object* on which the object is called
        Calc temp(rhs); // copy constructor (because of temp)
        std::swap(storedExpressions, temp.storedExpressions); // you swap the appropriate values
        std::swap(stored, temp.stored);
    }
    return *this; // returns a pointer to this object
}

double Calc::process(std::string userInput, double prevValue) {
    //First cleanse
    std::string cleansedString = "";
    for(size_t i = 0; i < userInput.size(); ++i) { // string_t indicates integer values betwn 0 and infinite (not negative)
        if (userInput[i] == '=' || userInput[i] == ' ' || userInput[i] == '(' || userInput[i] == ')') {}
        // the following symbols are ignored
        else {
            cleansedString += userInput[i];
        }
    }
    double value = std::stod(cleansedString.substr(1, cleansedString.length() - 1)); // stod takes a string and converts it to a double
    // we take a substring of cleansedString, starting from the second character (index 1) and of a substring value of (total length of the string - 1)
    if(cleansedString[0] == '^'){
        return pow(prevValue, value);
    }
    else if(cleansedString[0] == '*' || cleansedString[0] == '/'){
        if(cleansedString[0] == '*'){
            return prevValue * value;
        }
        else{
            if(value != 0){
                std::exit(0);
            }
        }
    }
    else if(cleansedString[0] == '+' || cleansedString[0] == '-'){
        if(cleansedString[0] == '+'){
            return prevValue + value;
        }
        else{
            return prevValue - value;
        }
    }
    else{
        std::cout << "ERROR: Must start with operator " << std::endl;
        return -10000000;
    }
    return -10000000;
}

void Calc::print() {
    std::cout << "You have " << stored << " expressions stored: ";
    for(size_t i = 0; i < stored; ++i){
        std::cout << "Expression " << i+1 << " result is:\n";
        std::cout << storedExpressions[i] << std::endl;
    }
}


void Calc::setStored(size_t newStored) {
    stored = newStored;
}

size_t Calc::getStored() {
    return stored;
}

