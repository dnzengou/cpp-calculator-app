#include <iostream>
#include "Calc.h"

int main() {
    int sentinal = 0; // sentinal values (0 here) allow, when entered, users to quit the programme whenever THEY decide to
    do {
        std::cout << "Please enter the number of expressions you would like to store: " << std::endl;
        int values;
        std::cin >> values;
        if (values < 1) {
            std::cout << "Error: Number of stored expressions must be positive" << std::endl;
        } else {
            Calc calc1 = Calc(values);
            for(size_t count = 0; count < values; count++){ // calculate as long as the for loop conditions are valid, repeatedly asking the users for info
                double answer = 0;
                bool flag = true;
                while(flag){ // we continue while flag == true
                    std::string userString;
                    std::cout << " Please enter your expression (Enter 'STOP' to halt this input stream): \n" << " = " << answer
                              << " + ... " << std::endl;
                    std::cin >> userString;
                    if (userString == "STOP") {
                        calc1.storedExpressions[calc1.getStored()] = std::to_string(answer);
                        flag = false;
                        break; // we put both the flag false and the break to make sure our programme wouldn't get stuck in an infinite checking loop
                    }
                    std::cout << userString << "= " << calc1.process(userString, answer); // we implement the userString and the result of the process methods defined earlier.
                    // Note that methods and functions have a subtle difference: functions aren't associated with a class, but methods are.
                    answer = calc1.process(userString, answer);
                }
                calc1.setStored(calc1.getStored() + 1); // we want here to increment the number of stored equations by one, after each one is completed
                // Note that we use methods set and get because Stored is a private variable
            }
            calc1.print();
            std::cout << "Press 1 to continue with another calculator, any other value to quit" << std::endl;
            std::cin >> sentinal;
        }
    }while(sentinal == 1);
    return 0;
}

