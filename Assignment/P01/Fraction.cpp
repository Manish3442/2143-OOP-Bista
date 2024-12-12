#include "Fraction.h"


Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    reduce();                                                                           // Reduce the fraction to its simplest form
}


int Fraction::gcd(int a, int b) const {                                                // Function to calculate GCD 
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int Fraction::lcm(int a, int b) const {                                                 // Function to calculate LCM 
    return (a / gcd(a, b)) * b;                                                          // LCM formula
}


void Fraction::reduce() {                                                               // Reduce the fraction to its simplest form
    int common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;
    if (denominator < 0) { 
        numerator = -numerator;
        denominator = -denominator;
    }
}


Fraction Fraction::operator+(const Fraction& other) const {
    int commonDenominator = lcm(denominator, other.denominator);                         // Find the least common denominator (LCD)
    int adjustedNumerator1 = numerator * (commonDenominator / denominator);              // Adjust both fractions to have this denominator
    int adjustedNumerator2 = other.numerator * (commonDenominator / other.denominator);
    int sumNumerator = adjustedNumerator1 + adjustedNumerator2;                          // Add the numerators
    return Fraction(sumNumerator, commonDenominator);                                    // Return the result as a new fraction
}

// Overloaded subtraction operator
Fraction Fraction::operator-(const Fraction& other) const {
    int commonDenominator = lcm(denominator, other.denominator);
    int adjustedNumerator1 = numerator * (commonDenominator / denominator);
    int adjustedNumerator2 = other.numerator * (commonDenominator / other.denominator);
    int diffNumerator = adjustedNumerator1 - adjustedNumerator2;
    return Fraction(diffNumerator, commonDenominator);
}

// Overloaded multiplication operator
Fraction Fraction::operator*(const Fraction& other) const {
    int newNumerator = numerator * other.numerator;
    int newDenominator = denominator * other.denominator;
    return Fraction(newNumerator, newDenominator);
}

// Overloaded division operator
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Cannot divide by zero fraction");
    }
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

// Overloaded equality operator (==)
bool Fraction::operator==(const Fraction& other) const {
    return numerator == other.numerator && denominator == other.denominator;
}

// Overload output operator (<<) for printing fractions
std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}
