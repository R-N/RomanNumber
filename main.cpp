#include <iostream>
#include "romannumber.hpp"

using namespace std;

int main(int argc, char** argv){
    cout << RomanNumber(5) << "+" << RomanNumber(4) << "==" << (RomanNumber(4) + RomanNumber(5));
}
