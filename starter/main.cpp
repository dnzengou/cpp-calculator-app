//#include <iostream>
//#include "Calc.h"

int main() {
//    int sentinal = 0;
//    do {
        std::cout << "Please enter the number of expressions you would like to store: " << std::endl;
        int values;
//        std::cin >> values;
        if (values < 1) {
            std::cout << "Error: Number of stored expressions must be positive" << std::endl;
        } else {
        }
            calc1.print();
            std::cout << "Press 1 to continue with another calculator, any other value to quit" << std::endl;
            std::cin >> sentinal;
        }
//    }while(sentinal == 1);
    return 0;
}
