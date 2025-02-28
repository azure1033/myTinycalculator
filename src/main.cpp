#include "calculate.h"

int main() {
    Calculator cal;
    
    std::string expression;
    while (true) {
        std::cout << "Please input the expression (or type 'exit' to quit): ";
        std::getline(std::cin, expression);
        
        if (expression == "exit") {
            std::cout << "Exiting the calculator. Goodbye!" << std::endl;
            break;
        }
        
        cal.InfixToPostfix(expression);
        cal.get_res();
    }
}