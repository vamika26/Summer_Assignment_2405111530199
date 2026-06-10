#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        string doubled = s + s;

        // Remove first and last character
        string temp = doubled.substr(1, doubled.size() - 2);

        return temp.find(s) != string::npos;
    }
};