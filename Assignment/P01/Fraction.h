

#include <iostream>
#include <stdexcept>  
#include <numeric>    

class Fraction {
private:
    int numerator;
    int denominator;

    // To calculate the Greatest Common Divisor (GCD)
    int gcd(int a, int b) const;

    // To calculate Least Common Multiple (LCM)
    int lcm(int a, int b) const;

    // To reduce the fraction to its simplest form
    void reduce();

public:
    
    Fraction(int num, int den);

    // Overloaded addition operator
    Fraction operator+(const Fraction& other) const;

    // Overloaded subtraction operator
    Fraction operator-(const Fraction& other) const;

    // Overloaded multiplication operator
    Fraction operator*(const Fraction& other) const;

    // Overloaded division operator
    Fraction operator/(const Fraction& other) const;

    // Overloaded equality operator (==)
    bool operator==(const Fraction& other) const;

    // Overload output operator (<<) for printing fractions
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
};


