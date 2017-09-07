#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <cstring>

using namespace std;

class RomanNumber{
private:
    RomanNumber(){}
    int value = 0;
public:
    const string thousands[4] = {"", "M", "MM", "MMM"};
    const string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const string ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    static int CharToInt(char c){
        switch (c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        throw std::runtime_error("Invalid Roman digit : " + c);
    }
    RomanNumber(const char* romanNumber);
    RomanNumber(const string& romanNumber);
    RomanNumber(const int& decimal);
    void SetValue(const char* romanNumber);
    void SetValue(const string& romanNumber);
    void SetValue(const int& decimal);
    int GetInt();
    string GetString();
    RomanNumber& operator+=(RomanNumber rhs);
    RomanNumber& operator-=(RomanNumber rhs);
    RomanNumber& operator*=(RomanNumber rhs);
    RomanNumber& operator/=(RomanNumber rhs);
    RomanNumber& operator%=(RomanNumber rhs);
    RomanNumber& operator+=(const int& rhs);
    RomanNumber& operator-=(const int& rhs);
    RomanNumber& operator*=(const int& rhs);
    RomanNumber& operator/=(const int& rhs);
    RomanNumber& operator%=(const int& rhs);
    RomanNumber& operator++();
    RomanNumber& operator++(int);
    RomanNumber& operator--();
    RomanNumber& operator--(int);
};

RomanNumber operator+(RomanNumber lhs, RomanNumber rhs);
RomanNumber operator-(RomanNumber lhs, RomanNumber rhs);
RomanNumber operator*(RomanNumber lhs, RomanNumber rhs);
RomanNumber operator/(RomanNumber lhs, RomanNumber rhs);
RomanNumber operator%(RomanNumber lhs, RomanNumber rhs);

RomanNumber operator+(const int& lhs, RomanNumber rhs);
RomanNumber operator-(const int& lhs, RomanNumber rhs);
RomanNumber operator*(const int& lhs, RomanNumber rhs);
RomanNumber operator/(const int& lhs, RomanNumber rhs);
RomanNumber operator%(const int& lhs, RomanNumber rhs);

RomanNumber operator+(RomanNumber lhs, const int& rhs);
RomanNumber operator-(RomanNumber lhs, const int& rhs);
RomanNumber operator*(RomanNumber lhs, const int& rhs);
RomanNumber operator/(RomanNumber lhs, const int& rhs);
RomanNumber operator%(RomanNumber lhs, const int& rhs);

ostream& operator<<(ostream& os, RomanNumber num);
ostream& operator<<(RomanNumber num, ostream& os);
