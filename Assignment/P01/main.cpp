#include <iostream>
#include <fstream>
#include <sstream>
#include "Fraction.h"

int main() {
    std::ifstream infile("fractions.txt");                                      // Input file containing fractions and operations
    if (!infile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {                                        // Read each line from the file
        std::istringstream iss(line);
        std::string frac1_str, frac2_str, op;
 
         
        if (!(iss >> frac1_str >> op >> frac2_str)) {                           // Read fractions and operator from the line
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;                                                           // Skip invalid lines
        }

        
        int num1, den1, num2, den2;
        sscanf(frac1_str.c_str(), "%d/%d", &num1, &den1);                       // Extract numerator and denominator for the first fraction
        sscanf(frac2_str.c_str(), "%d/%d", &num2, &den2);                       // Extract numerator and denominator for the second fraction

        Fraction frac1(num1, den1);
        Fraction frac2(num2, den2);
        Fraction result(0, 1);

                                                                                 
        if (op == "+") {                                                        // Perform the correct operation based on the operator
            result = frac1 + frac2;
        } else if (op == "-") {
            result = frac1 - frac2;
        } else if (op == "*") {
            result = frac1 * frac2;
        } else if (op == "/") {
            result = frac1 / frac2;
        } else {
            std::cerr << "Unknown operator: " << op << std::endl;
            continue;
        }

        
        std::cout << frac1 << " " << op << " " << frac2 << " = " << result << std::endl;
    }

    infile.close();
    return 0;
}
