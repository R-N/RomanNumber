#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <cstring>
#include "romannumber.hpp"

using namespace std;


RomanNumber::RomanNumber(const char* romanNumber){
    SetValue(romanNumber);
}

RomanNumber::RomanNumber(const string& romanNumber){
    SetValue(romanNumber);
}

RomanNumber::RomanNumber(const int& decimal){
    SetValue(decimal);
}

void RomanNumber::SetValue(const char* romanNumber){
    SetValue(string(romanNumber));
}

void RomanNumber::SetValue(const string& romanNumber){
    int len = romanNumber.length();
    int prevVal=0, ret=0, counter=0;
    for (int i=0; i < len; ++i){
        char c = romanNumber[i];
        int val = RomanNumber::CharToInt(c);
        if (val > prevVal){
            if (counter > 1)
                throw runtime_error("Invalid roman number : " + romanNumber);
            ret += val - 2*prevVal;
            counter = 1;
        }else{
            ret += val;
            if (val == prevVal)
                ++counter;
            else
                counter = 1;
            if (counter > 3)
                throw runtime_error("Invalid roman number : " + romanNumber);
        }
        prevVal = val;
    }
    value = ret;
}

void RomanNumber::SetValue(const int& decimal){
    if (decimal < 0)
        throw runtime_error("Negative numbers can't be represented in Roman number");
    if (decimal > 3999)
        throw runtime_error("Numbers higher than 3999 can't be represented in Roman number");
    value = decimal;
}

int RomanNumber::GetInt(){
    return value;
}

string RomanNumber::GetString(){
    return thousands[value/1000] + hundreds[(value%1000)/100] + tens[(value%100)/10] + ones[value%10];
}

RomanNumber operator+(RomanNumber lhs, RomanNumber rhs){
    return RomanNumber(lhs.GetInt() + rhs.GetInt());
}
RomanNumber operator-(RomanNumber lhs, RomanNumber rhs){
    return RomanNumber(lhs.GetInt() - rhs.GetInt());
}
RomanNumber operator*(RomanNumber lhs, RomanNumber rhs){
    return RomanNumber(lhs.GetInt() * rhs.GetInt());
}
RomanNumber operator/(RomanNumber lhs, RomanNumber rhs){
    return RomanNumber(lhs.GetInt() / rhs.GetInt());
}
RomanNumber operator%(RomanNumber lhs, RomanNumber rhs){
    return RomanNumber(lhs.GetInt() % rhs.GetInt());
}

RomanNumber operator+(const int& lhs, RomanNumber rhs){
    return RomanNumber(lhs + rhs.GetInt());
}
RomanNumber operator-(const int& lhs, RomanNumber rhs){
    return RomanNumber(lhs - rhs.GetInt());
}
RomanNumber operator*(const int& lhs, RomanNumber rhs){
    return RomanNumber(lhs * rhs.GetInt());
}
RomanNumber operator/(const int& lhs, RomanNumber rhs){
    return RomanNumber(lhs / rhs.GetInt());
}
RomanNumber operator%(const int& lhs, RomanNumber rhs){
    return RomanNumber(lhs % rhs.GetInt());
}

RomanNumber operator+(RomanNumber lhs, const int& rhs){
    return RomanNumber(lhs.GetInt() + rhs);
}
RomanNumber operator-(RomanNumber lhs, const int& rhs){
    return RomanNumber(lhs.GetInt() - rhs);
}
RomanNumber operator*(RomanNumber lhs, const int& rhs){
    return RomanNumber(lhs.GetInt() * rhs);
}
RomanNumber operator/(RomanNumber lhs, const int& rhs){
    return RomanNumber(lhs.GetInt() / rhs);
}
RomanNumber operator%(RomanNumber lhs, const int& rhs){
    return RomanNumber(lhs.GetInt() % rhs);
}

RomanNumber& RomanNumber::operator+=(RomanNumber rhs){
    value += rhs.GetInt();
    return *this;
}
RomanNumber& RomanNumber::operator-=(RomanNumber rhs){
    value -= rhs.GetInt();
    return *this;
}
RomanNumber& RomanNumber::operator*=(RomanNumber rhs){
    value *= rhs.GetInt();
    return *this;
}
RomanNumber& RomanNumber::operator/=(RomanNumber rhs){
    value /= rhs.GetInt();
    return *this;
}
RomanNumber& RomanNumber::operator%=(RomanNumber rhs){
    value %= rhs.GetInt();
    return *this;
}

RomanNumber& RomanNumber::operator+=(const int& rhs){
    value += rhs;
    return *this;
}
RomanNumber& RomanNumber::operator-=(const int& rhs){
    value -= rhs;
    return *this;
}
RomanNumber& RomanNumber::operator*=(const int& rhs){
    value *= rhs;
    return *this;
}
RomanNumber& RomanNumber::operator/=(const int& rhs){
    value /= rhs;
    return *this;
}
RomanNumber& RomanNumber::operator%=(const int& rhs){
    value %= rhs;
    return *this;
}

ostream& operator<<(ostream& os, RomanNumber num)
{
    os << num.GetString();
    return os;
}

ostream& operator<<(RomanNumber num, ostream& os)
{
    os << num.GetString();
    return os;
}

