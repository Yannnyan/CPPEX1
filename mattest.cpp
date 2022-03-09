#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
# include "doctest.h"
# include "mat.cpp"
# include "iostream"
const int MIN_TESTS = 20;
using namespace doctest;
using namespace std;

int factorial(int number) { return number <= 1 ? number : factorial(number - 1) * number; }

string nospaces(string input) {
    std::string::erase(input, ' ');
    std::string::erase(input, '\t');
    std::string::erase(input, '\n');
    std::string::erase(input, '\r');
    return input;
}

